/*
 * critical.c
 *
 *  Created on: 2014-03-02
 *      Author: Jonah Caplan, Anthony Delage
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <altera_avalon_pio_regs.h>
#include "critical.h"
#include "gp.h"

/* Mathworks headers */
#include "rtwtypes.h"                  /* MathWorks ty*/
#include "AirbagModel.h"
#include "CollisionAvoidance.h"
#include "CruiseControlSystem.h"
#include "FuelSensor.h"
#include "TractionControl.h"
#include "TransmissionControl.h"
#include "Gain.h"
#include "Sum.h"
#include "Derivative.h"
#include "Compare.h"

// Tasks to be fingerprinted

// Airbag task, calls AirbagModel.c, Gain.c and Compare.c functions
void airbag_task(void* args) {
	// Get data from input arguments
	airbag_args* a = (airbag_args*)args;
	airbag_data* ab_data = a->airbag_data;

	// Local (intermediate) variables
	real_T gain_out;
	real_T ab_sensor_displacement;

	// Fingerprinting task
	enable_fprint_task(a->priority);
	Gain_step(&gain_out, *(ab_data->gain_in);
	AirbagModel_step(&ab_sensor_displacement, &gain_out);
	Compare_step(*(ab_data->activate_airbag), &ab_sensor_displacement);
	disable_fprint_task(a->priority);
}

// Collision Avoidance task, calls CollisionAvoidance.c functions
void collision_avoidance_task(void* args) {
	// Get data from input arguments
	collision_avoidance_args* a = (collision_avoidance_args*)args;
	collision_avoidance_data* ca_data = a->collision_avoidance_data;

	// Fingerprinting task
	enable_fprint_task(a->priority);
	CollisionAvoidance_step(ca_data->ca_light_on, ca_data->ca_radar_sensor, ca_data->ca_acceleration);
	disable_fprint_task(a->priority);
}

// Cruise Control task, calls CruiseControlSystem.c functions
void cruise_control_task(void* args) {
	// Get data from input arguments
	cruise_control_args* a = (cruise_control_args*)args;
	cruise_control_data* cc_data = a->cruise_control_data;
	derivative_data* d_data = a->derivative_data;
	traction_control_data* tc_data = a->traction_control_data;

	// Fingerprinting task
	enable_fprint_task(a->priority);
	CruiseControlSystem_step(cc_data->cc_current_speed, cc_data->cc_desired_speed);
	disable_fprint_task(a->priority);

	// Pass output to subsequent stages (DOES THIS HAVE TO BE FINGERPRINTED?)
	d_data->deriv_in = cc_data->cc_current_speed;
	tc_data->current_speed_powered = cc_data->cc_current_speed;
}

// Traction Control task, calls TractionControl.c functions
void traction_control_task(void* args) {
	// Get data from input arguments
	traction_control_args* a = (traction_control_args*)args;
	traction_control_data* tc_data = a->traction_control_data;
	sum_data* s_data = a->sum_data;

	// Fingerprinting task
	enable_fprint_task(a->priority);
	TractionControl_step(tc_data->traction_control_feedback, tc_data->current_speed_powered, tc_data->current_speed_unpowered);
	disable_fprint_task(a->priority);

	// Pass output to subsequent stages (DOES THIS HAVE TO BE FINGERPRINTED?)
	s_data->sum_in2 = tc_data->traction_control_feedback; // Note that input is negative for negative feedback effect
}

// Derivative task, calls Derivative.c functions
void derivative_task(void* args) {
	// Get data from input arguments
	derivative_args* a = (derivative_args*)args;
	derivative_data* d_data = a->derivative_data;
	airbag_data* ab_data = a->airbag_data;
	collision_avoidance_data* ca_data = a->collision_avoidance_data;

	// Fingerprinting task
	enable_fprint_task(a->priority);
	Derivative_step(d_data->deriv_out, d_data->deriv_in);
	disable_fprint_task(a->priority);

	// Pass output to subsequent stages (DOES THIS HAVE TO BE FINGERPRINTED?)
	ab_data->gain_in = d_data->deriv_out;
	ca_data->ca_acceleration = d_data->deriv_out;
}

// Sum task, calls Sum.c functions
void sum_task(void* args) {
	// Get data from input arguments
	sum_args* a = (sum_args*)args;
	sum_data* s_data = a->sum_data;
	cruise_control_data* cc_data = a->cruise_control_data;

	// Fingerprinting task
	enable_fprint_task(a->priority);
	Sum_step(s_data->sum_out, s_data->sum_in1, s_data->sum_in2);
	disable_fprint_task(a->priority);

	// Pass output to subsequent stages (DOES THIS HAVE TO BE FINGERPRINTED?)
	cc_data->cc_desired_speed = s_data->sum_out;
}