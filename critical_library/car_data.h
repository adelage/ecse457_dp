/****************************************************************************
 * Copyright (c) 2015 Anthony Delage, Gregory Williamson, Alexander Lunan,	*
 * McGill University.      													*
 * All rights reserved. All use of this software and documentation is     	*
 * subject to the License Agreement located at the end of this file below.	*
 ***************************************************************************/

#ifndef CAR_INPUTS_H_
#define CAR_INPUTS_H_

#include "rtwtypes.h"                  /* MathWorks ty*/

// Type definition for structure holding car control loop inputs
typedef struct car_input {
	real_T radar_sensor;
	real_T pedal_speed;
	real_T current_speed_unpowered;
	real_T fuel_level;
	real_T trans_fuel_level;
}car_input;

typedef struct car_output {
	boolean_T ca_light_on;
	boolean_T activate_airbag;
	boolean_T fl_light_on;
	boolean_T tfl_light_on;
}car_output;

#endif /* CAR_INPUTS_H_ */