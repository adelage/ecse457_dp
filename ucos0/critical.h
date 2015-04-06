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

// Type definitions that hold the data for each stage in the system
typedef struct airbag_data {
	real_T gain_in;
	boolean_T activate_airbag;
}airbag_data;

typedef struct collision_avoidance_data {
	real_T ca_radar_sensor;
	real_T ca_acceleration;
	boolean_T ca_light_on;
}collision_avoidance_data;

typedef struct cruise_control_data {
	real_T cc_desired_speed;
	real_T cc_current_speed;
}cruise_control_data;

typedef struct traction_control_data {
	real_T current_speed_powered;
	real_T current_speed_unpowered;
	real_T traction_control_feedback;
}traction_control_data;

typedef struct derivative_data {
	real_T deriv_in;
	real_T deriv_out;
}derivative_data;

typedef struct sum_data {
	real_T sum_in1;
	real_T sum_in2;
	real_T sum_out;
}sum_data;

// Type definitions used to pass data to the tasks
typedef struct airbag_args {
	int priority;
	airbag_data *airbag_data;
}airbag_args;

typedef struct collision_avoidance_args {
	int priority;
	collision_avoidance_data *collision_avoidance_data;
}collision_avoidance_args;

typedef struct cruise_control_args {
	int priority;
	cruise_control_data *cruise_control_data;
	derivative_data *derivative_data;
	traction_control_data *traction_control_data;
}cruise_control_args;

typedef struct traction_control_args {
	int priority;
	traction_control_data *traction_control_data;
	sum_data *sum_data;
}traction_control_args;

typedef struct derivative_args {
	int priority;
	derivative_data *derivative_data;
	airbag_data *airbag_data;
	collision_avoidance_data *collision_avoidance_data;
}derivative_args;

typedef struct sum_args {
	int priority;
	sum_data *sum_data;
	cruise_control_data *cruise_control_data;
}sum_args;

// These are tasks to be fingerprinted
extern void airbag_task(void* args);
extern void collision_avoidance_task(void* args);
extern void cruise_control_task(void* args);
extern void traction_control_task(void* args);
extern void derivative_task(void* args);
extern void sum_task(void* args);

// These two tasks are used to save the values of callee saved
// registers onto the stack before fingerprinting and restore them
// after fingerprinting
extern void context_switch(long *reg_stack);
extern void context_restore(long *reg_stack);

#endif /* CRITICAL_H_ */
