/*
 * critical.h
 *
 *  Created on: 2014-03-02
 *      Author: Jonah
 */

#ifndef CRITICAL_H_
#define CRITICAL_H_

#include "rtwtypes.h"                  /* MathWorks ty*/
#include "fingerprint.h"

// Type definitions used to pass data to the tasks
typedef struct airbag_args {
	int priority;
	real_T* deriv_out;			// Derivative stage's output
	boolean_T* activate_airbag;		// Airbag stage's output
}airbag_args;

// These are tasks to be fingerprinted
void airbag_task(void* args);
void collision_avoidance_task(void* args);
void cruise_control_task(void* args);
void traction_control_task(void* args);
void transmission_control_task(void* args);
void derivative_task(void* args);
void sum_task(void* args);

// These two tasks are used to save the values of callee saved
// registers onto the stack before fingerprinting and restore them
// after fingerprinting
extern void context_switch(long *reg_stack);
extern void context_restore(long *reg_stack);

#endif /* CRITICAL_H_ */
