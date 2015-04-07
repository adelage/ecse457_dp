/****************************************************************************
 * Copyright (c) 2013 Jonah Caplan, McGill University.      				*
 * All rights reserved. All use of this software and documentation is     	*
 * subject to the License Agreement located at the end of this file below.	*
 ****************************************************************************
 * Description:                                                           	*
 * 																			*
 ***************************************************************************/

/**********************************
 * Includes
 **********************************/
#include <stdio.h>
#include <time.h>
#include <altera_avalon_pio_regs.h>
#include <altera_avalon_mutex.h>
#include <ucos_ii.h>
#include <string.h>
#include <stdlib.h>

#include "includes.h"
#include "shared_mem.h"
#include "fingerprint.h"
#include "critical.h"
#include "car_data.h"
#include "priv/alt_busy_sleep.h"
#include "alt_types.h"
#include "stdio.h"
#include "sys/alt_dma.h"
#include "sys/alt_timestamp.h"
#include "system.h"
#include "gp.h"

/***********************************
 * Local Variables
 **********************************/
alt_mutex_dev* mutex;									//hardware mutex pointer


/*
 * These two pointers are the addresses of interrupt registers
 * When the monitor wishes to communicate with either cpu0 or cpu1,
 * it writes 0x1 to the appropriate pointer address
 */

int *isr_0_ptr = (int *) PROCESSOR0_0_CPU_IRQ_0_BASE;
int *isr_1_ptr = (int *) PROCESSOR1_0_CPU_IRQ_0_BASE;


/*
 *
 * TASK STACK DECLARATIONS
 */
#define   TASK_STACKSIZE       768						//Stack size for all tasks
OS_STK schedule_task_stk[TASK_STACKSIZE] __attribute__ ((section (".critical")));
OS_STK print_status_stk[TASK_STACKSIZE] __attribute__ ((section (".critical")));
OS_STK print_execution_times_stk[TASK_STACKSIZE] __attribute__ ((section (".critical")));

/*
 * SEMAPHORE DECLARATIONS
 */
OS_EVENT* done;
OS_EVENT* start_schedule;
/*
 * Definition of Task Priorities
 * Used only to set directory offsets
 */
#define TASK_START_PRIORITY			1
#define PREEMPT_TASK_PRIORITY_2		2
#define PREEMPT_TASK_PRIORITY_3		3
#define PREEMPT_TASK_PRIORITY		4
#define CRITICAL_TASK_PRIORITY		5

/*
 * Monitor task priorities
 */

#define SCHEDULE_TASK_PRIORITY      		5
#define PRINT_STATUS_PRIORITY				4
#define PRINT_EXECUTION_TIMES_PRIORITY		3

int status;
/*
 * IO
 */
CriticalFunctionPointers cpg;
INT8U err;



/*
 * This task sends instructions to cpu0 and cpu1.
 * It acquires the hardware mutex, it then puts
 * the address of the task to be fingerprinted in shared memory.
 * shared_mem.h is a data structure which could be extended
 * into a collection of data structures with a header/identifier
 * integer. cpu0 and cpu1 look for the address of the function
 * to fingerprint using the CriticalFunctionPointers data structure
 */
void schedule_task(void* pdata){
	//int i;

	printf("Monitor!\n");
	CriticalFunctionPointers* cp =
						(CriticalFunctionPointers*) SHARED_MEMORY_BASE;

	// Initialize critical function arguments
	sum_data s_data;
	s_data.sum_in1 = 2.0;
	s_data.sum_in2 = 1.0;
	s_data.sum_out = 0.0;

	cruise_control_data cc_data;
	cc_data.cc_desired_speed = 0.0;
	cc_data.cc_current_speed = 0.0;

	sum_args s_args;
	s_args.priority = CRITICAL_TASK_PRIORITY;
	s_args.sum_data = &s_data;
	s_args.cruise_control_data = &cc_data;

	// Initialize Altera timer
	alt_timestamp_start();

	while(1){
		OSSemPend(start_schedule, 0, &err);
		int i;
		int x;
		alt_u64 t1, t2, tdiff;

		// Run Sum function
		t1 = alt_timestamp();
		sum_task(&s_args);
		t2 = alt_timestamp();
		tdiff = t2 - t1;
		i++;

		// //Acquire the mutex and set cores 1 and 2 to execute the first task
		// altera_avalon_mutex_lock(mutex, 1);
		// {
		// 	for(i = 0; i < 2; i++){
		// 		cp->task[i] = basicmath_test;
		// 		cp->priority[i] = 3;
		// 		cp->blocksize[i] = 0xfff;
		// 		cp->args[i] = &args[0];
		// 	}
		// }
		// altera_avalon_mutex_unlock(mutex);
		//Wait 10 seconds before trying again
		OSTimeDlyHMSM(0, 0, 0, 1);



	}
}


/*
 * print_status_task() will print the status
 * of each ask from 2->10 as it is currently
 * written. endstate[] is used to keep track
 * of the success or failure of each task
 * since they may not arrive with a single
 * interrupt
 */
int endstate[10];
void print_status_task(void* pdata){
	while(1){
		OSSemPend(done, 0, &err);
		int i;
		for(i = 2; i < 10; i++){

			int success = endstate[i];

			printf("task %d was ",i);
			if(success == 1){
				printf("successful ");
			}
			else if(success == -1){
				printf("unsuccessful ");
			}
			else{
				printf("not executed ");
			}
			unsigned long t = clock();
			printf("at time %lu.\n",t);
		}

		for(i = 0; i < 10; i++){
			endstate[i] = 0;
		}

	}
}

/*
 * This prints the execution times for each task as
 * measured by the more precise performance counters
 * local to each core
 */
void print_execution_times(void* pdata){
	CriticalFunctionPointers* cp =
							(CriticalFunctionPointers*) SHARED_MEMORY_BASE;
	while(1){
		OSTimeDlyHMSM(0,0,10,0);
		int i;
		for(i = 0; i < 8; i++){

			printf("core %d finished at time %llu\n",i,cp->core_time[i]);
		}
	}
}

/*
 * Interrupt handler for the comparator
 * Check the status and and failed registers
 * to see which task caused the interrupt.
 * Update the endstate data structure that maintains
 * the history. Then reset the IRQ register
 */
int count = 0;
static void handle_collision_interrupt(void* context) {
	Fprint_Status status;
	fprint_status(&status);

	int i;
	for(i = 0; i < 16; i++){
		if((status.successful_reg & (1 << i)) == (1 << i)){
			endstate[i] = 1;
		}
		if((status.failed_reg & (1 << i)) == (1 << i)){
			endstate[i] = -1;
		}
	}
	fprint_reset_irq();

	//If the last task is finished (there's only one in this example)
	//start_schedule prevents the schedule from reexecuting before the task
	//is complete. done triggers print_status_task
	if(endstate[5] != 0){
		OSSemPost(start_schedule);
		OSSemPost(done);
		count = 0;
	}
}

/*
 * Initialize the comparator interrupt
 */
static void init_collision_isr(void) {
	alt_ic_isr_register(CFPU_0_CSR_IRQ_INTERRUPT_CONTROLLER_ID,
			CFPU_0_CSR_IRQ, handle_collision_interrupt, (void*) NULL,
			(void*) NULL);
}
/*
 * Main
 */

/*
 * Here is an example of how to use DMA to move data into
 * the scratchpads. It's taken directly out of the
 * software development manual. The driver's are a mess
 * but they work so let's leave it there. The only points worth noting are the values of
 * tx_data and rx_buffer.
 *
 * tx_data= 0x431000, this is a 4kB aligned page in the Monitor main memory region
 * where global variables have been stored for the critical task. (This is done in the critical.c
 * file in the critical_library using:
 * 			int global_var	__attribute__ ((section (".global_data")));
 * 	more info on __atribute__ can be found in the tightly coupled memory tutorial from Altera.
 *
 * 	rx_buffer = 0x8203000 is a 4k aligned section in the cpu0 or cpu1 scratchpad where
 * 	the local copies of this data will be stored
 */
static volatile int rx_done = 0;

static void done_dma (void* handle, void* data)
{
	rx_done++;
}

void dma(void){


	int rc;
	alt_dma_txchan txchan[2];
	alt_dma_rxchan rxchan[2];


	void* tx_data = (void*) 0x00431000; /* pointer to data to send */
	void* rx_buffer = (void*) 0x04203000; /* pointer to rx buffer */
	/* Create the transmit channel */

		if ((txchan[0] = alt_dma_txchan_open("/dev/processor0_0_dma_0")) == NULL){
			printf ("Failed to open transmit channel\n");
			exit (1);
		}
		/* Create the receive channel */
		if ((rxchan[0] = alt_dma_rxchan_open("/dev/processor0_0_dma_0")) == NULL){
			printf ("Failed to open receive channel\n");
			exit (1);
		}
		if ((rc = alt_dma_txchan_send (txchan[0],
		tx_data,
		0x1000,
		NULL,
		NULL)) < 0){
			printf ("Failed to post transmit request, reason = %i\n", rc);
			exit (1);
		}
		/* Post the receive request */
		if ((rc = alt_dma_rxchan_prepare (rxchan[0],
		rx_buffer,
		0x1000,
		done_dma,
		NULL)) < 0){
			printf ("Failed to post read request, reason = %i\n", rc);
			exit (1);
		}
		/* wait for transfer to complete */

		//printf ("Transfer successful!\n");

		if ((txchan[1] = alt_dma_txchan_open("/dev/processor1_0_dma_0")) == NULL){
			printf ("Failed to open transmit channel\n");
			exit (1);
		}
		/* Create the receive channel */
		if ((rxchan[1] = alt_dma_rxchan_open("/dev/processor1_0_dma_0")) == NULL){
			printf ("Failed to open receive channel\n");
			exit (1);
		}
		if ((rc = alt_dma_txchan_send (txchan[1],
		tx_data,
		0x1000,
		NULL,
		NULL)) < 0){
			printf ("Failed to post transmit request, reason = %i\n", rc);
			exit (1);
		}
		/* Post the receive request */
		if ((rc = alt_dma_rxchan_prepare (rxchan[1],
		rx_buffer,
		0x1000,
		done_dma,
		NULL)) < 0){
			printf ("Failed to post read request, reason = %i\n", rc);
			exit (1);
		}
		while (rx_done<2);
}
int main(void) {

	printf("Hello from Nios II!\n");
	int i,j;
	init_collision_isr();
	CriticalFunctionPointers* cp =
					(CriticalFunctionPointers*) SHARED_MEMORY_BASE;


	//Get the global data into the scratchpads
	dma();

	mutex = altera_avalon_mutex_open(MUTEX_0_NAME);	//Initialize the hardware mutex
	altera_avalon_mutex_lock(mutex, 1);
	{
		OSTimeSet(0);
		cp->init_complete = 1;
	}
	altera_avalon_mutex_unlock(mutex);


	done = OSSemCreate(0);
	start_schedule = OSSemCreate(1);

	//This is how you can set the start and end pointers
	Directory_Init_Struct d;
	for(i = 0; i < 2; i++){
		d.core_id = i;
		d.key = 0;
		d.start_ptr = 5;
		d.end_ptr = 0xff;
		set_task_directory(&d);

		for(j = 2; j < 10; j++){
			d.key = j;
			d.start_ptr = 50*(j-2);
			d.end_ptr = 50*(j-1)-1;
			set_task_directory(&d);

		}
	}

	//This is how you can set the core assignment table(easy for 2  cores...)
	Core_Assignment_Table ca;

	/* TABLE VALUES:
	 * x x
	 * x x
	 * 0 1
	 * 2 3
	 * 4 5
	 * 6 7
	 * ...
	 */
	//Default table
	for(i = 0; i < CA_TABLE_MAX_REDUNDANCY; i++){
		for(j = 0; j < CA_TABLE_NUM_TASKS; j++){
			ca.table[i][j] = i;
		}
	}
	set_core_assignment_table(&ca);


	//Now we make sure both have finished their initialization procedures before
	//moving forward
	//Wait for both cores to be ready
	int p0 = 0, p1 = 0;
	while((p0 != 1) || (p1 != 1)){
		altera_avalon_mutex_lock(mutex, 1);
		{
			memcpy(&cpg, (void*) SHARED_MEMORY_BASE,
					sizeof(CriticalFunctionPointers));
			p0 = cpg.core_ready[0];
			p1 = cpg.core_ready[1];
		}
		altera_avalon_mutex_unlock(mutex);
	}
	cpg.core_ready[0] = 0;
	cpg.core_ready[1] = 0;

	//Start up the tasks and OS
	int arg_5 = CRITICAL_TASK_PRIORITY;
	OSTaskCreateExt(schedule_task, &arg_5, &schedule_task_stk[TASK_STACKSIZE - 1],
			SCHEDULE_TASK_PRIORITY, SCHEDULE_TASK_PRIORITY,
			schedule_task_stk, TASK_STACKSIZE, NULL,OS_TASK_OPT_STK_CHK + OS_TASK_OPT_STK_CLR);
	OSTaskCreateExt(print_status_task, &arg_5, &print_status_stk[TASK_STACKSIZE - 1],
				PRINT_STATUS_PRIORITY, PRINT_STATUS_PRIORITY,
				print_status_stk, TASK_STACKSIZE, NULL,OS_TASK_OPT_STK_CHK + OS_TASK_OPT_STK_CLR);


	//Start operating system
	OSStart();

	return 0;
}
