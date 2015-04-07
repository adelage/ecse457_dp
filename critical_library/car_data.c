/****************************************************************************
 * Copyright (c) 2015 Anthony Delage, Gregory Williamson, Alexander Lunan,	*
 * McGill University.      													*
 * All rights reserved. All use of this software and documentation is     	*
 * subject to the License Agreement located at the end of this file below.	*
 ***************************************************************************/

#include "rtwtypes.h"                  /* MathWorks ty*/
#include "car_data.h"
#include "critical.h"

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


