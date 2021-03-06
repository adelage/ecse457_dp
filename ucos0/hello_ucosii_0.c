/****************************************************************************
 * Copyright (c) 2013 Jonah Caplan, McGill University.      				*
 * All rights reserved. All use of this software and documentation is     	*
 * subject to the License Agreement located at the end of this file below.	*
 ****************************************************************************
 * Description:                                                           	*
 * This software is one half of a program that demonstrates how				*
 * fingerprinting can be controlled from software using the ucos RTOS.		*
 * This is the slave core. This is the second processor, it executes		*
 * Task 2 until an interrupt from the main processor triggers critical		*
 * execution. When multiple tasks or argument passing occur	a data 			*
 * structure in shared on chip memory can be used to pass arguments.		*
 ***************************************************************************/

/**********************************
 * Includes
 **********************************/
#include <stdio.h>
#include <stdlib.h>
#include "includes.h"
#include "fingerprint.h"
#include "shared_mem.h"
#include <altera_avalon_pio_regs.h>
#include <altera_avalon_mutex.h>
#include <sys/alt_irq.h>
#include "critical.h"
#include <string.h>
#include "sys/alt_timestamp.h"
#include "gp.h"
#include "tlb.h"

alt_mutex_dev* mutex;									//hardware mutex pointer
void (*ct)(int);
void (*pt)(void*);

int *isr_0_ptr = (int *) PROCESSOR0_0_CPU_IRQ_0_BASE;	//Pointer to IRQ Register

#define   TASK_STACKSIZE       1024						//Stack size for all tasks


OS_STK critical_task_stk[TASK_STACKSIZE] __attribute__ ((section (".critical")));

/* Definition of Task Priorities */


#define CRITICAL_TASK_PRIORITY      5

OS_EVENT* mbox;
/*
 * Interrupt Handler and Initializer
 */
int count = 0;

/*
 * If CPU0 interrupt goes off, we assume that it has been sent
 * by the monitor for now and that a task must be executed.
 * The identity of the task is retrieved from the shared_memory
 * using the CriticalFunctionPointers data structure. The task is then executed
 */
static void handle_cpu0_interrupt(void* context) {
	unsigned short priority;
	altera_avalon_mutex_lock(mutex, 1);
	{

		CriticalFunctionPointers* cp = (CriticalFunctionPointers*)SHARED_MEMORY_BASE;
		priority = cp->priority[0];
		*isr_0_ptr = 0;

	}
	altera_avalon_mutex_unlock(mutex);
	if(priority == CRITICAL_TASK_PRIORITY)
		OSSemPost(mbox);

}

static void init_cpu0_isr(void) {
	alt_ic_isr_register(PROCESSOR0_0_CPU_IRQ_0_IRQ_INTERRUPT_CONTROLLER_ID,
			PROCESSOR0_0_CPU_IRQ_0_IRQ, handle_cpu0_interrupt, (void*) NULL,
			(void*) NULL);
}

/*
 * Critical task. Only code prior to enable fingerprinting is
 * waiting for an activation message. This is necessary
 * to guarantee the stack matches on both cores.
 */

INT8U err;
void preemption_task(void* pdata){
	int done = 0;
	int first = 0;
	int t_os;

	CriticalFunctionPointers* cp =
				(CriticalFunctionPointers*) SHARED_MEMORY_BASE;
	pt = cp->task[0];

	while(1){
		// Get initial time, then wait for 2 ticks
		t_os = OSTimeGet();
		OSTimeDly(2 - t_os);

		//This is a crude way of synchronizing the beginning of the task
		//on both cores
		while (done == 0) {
			altera_avalon_mutex_lock(mutex, 1); //Acquire the hardware mutex
			{
				if(first == 0){
					cp->checkout[0] = 1;
					first = 1;
				}
				if( cp->checkout[1] == 1){
					cp->checkout[1] = 0;
					done = 1;
				}

			}
			altera_avalon_mutex_unlock(mutex);
		}

		// Set default block size for fingerprinting
		fprint_set_block_size(cp->blocksize[1]);

		//Context switch is necessary to clear the callee saved registers
		long registers[8];
		context_switch(registers);

		//Set the global pointer in case of compilation issues related
		//to global variables
		set_gp();
		//call the critical task
		pt(cp->args[0]);
		//restore the original global pointer
		restore_gp();
		//Restore the callee saved registers
		context_restore(registers);
		//Get the end time
		alt_u64 t = alt_timestamp();
		//store the end time
		cp->core_time[0] = t;
	}
}

void init_tlb(){
	set_cputable_entry(0, 0x00431000);
	set_spmtable_entry(0, 0x04203000);

	//Enable these 4 translations
	set_enable(0x1);

}

/*
 * Main
 */
int main(void) {

	init_tlb();
	enable_tlb();
	printf("Hello from Nios II!\n");
	mutex = altera_avalon_mutex_open(MUTEX_0_NAME);	// Initialize the hardware mutex
	mbox = OSSemCreate(0);							// Initialize the message box
	CriticalFunctionPointers* cp = (CriticalFunctionPointers*)SHARED_MEMORY_BASE;
	
	// Wait for monitor to be done initialization of shared variables before retrieving their values
	while(cp->init_complete == 0);
	init_cpu0_isr();								// Initialize the ISR

	// Set the task(only one in this example)
	int arg_5 = CRITICAL_TASK_PRIORITY;
	OSTaskCreateExt(preemption_task, &arg_5, &critical_task_stk[TASK_STACKSIZE - 1],
					CRITICAL_TASK_PRIORITY, CRITICAL_TASK_PRIORITY,
					critical_task_stk, TASK_STACKSIZE, NULL,0);

	// Signal that the core has finished initializing
	altera_avalon_mutex_lock(mutex, 1);				// Acquire the hardware mutex
	{
		cp->core_ready[0] = 1;
	}
	altera_avalon_mutex_unlock(mutex);				// Memory

	// Start OS
	OSStart();
	return 0;
}
