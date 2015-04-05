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
	airbag_data** ab_data = a->airbag_data;

	// Local (intermediate) variables
	real_T gain_out;
	real_T ab_sensor_displacement;

	// Fingerprinting task
	enable_fprint_task(a->priority);
	Gain_step(&gain_out, ab_data->gain_in);
	AirbagModel_step(&ab_sensor_displacement, &gain_out);
	Compare_step(ab_data->activate_airbag, &ab_sensor_displacement);
	disable_fprint_task(a->priority);
}

// Collision Avoidance task, calls CollisionAvoidance.c functions
void collision_avoidance_task(void* args) {

}

// Cruise Control task, calls CruiseControlSystem.c functions
void cruise_control_task(void* args) {

}

// Traction Control task, calls TractionControl.c functions
void traction_control_task(void* args) {
	
}

// Derivative task, calls Derivative.c functions
void derivative_task(void* args) {

}

// Sum task, calls Sum.c functions
void sum_task(void* args) {
	
}