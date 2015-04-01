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
#include "AirbagModel.h"
#include "CollisionAvoidance.h"
#include "CruiseControlSystem.h"
#include "FuelSensor.h"
#include "TractionControl.h"
#include "TransmissionControl.h"
#include "rtwtypes.h"                  /* MathWorks ty*/

void write_led(int count) {

	IOWR_ALTERA_AVALON_PIO_DATA(0x10, count);
}


#define UNLIMIT
#define MAXARRAY 10000
/* this number, if too large, will cause a seg. fault!! */

void critical_task(int priority) {

		enable_fprint_task(priority);


		disable_fprint_task(priority);

}

void preempt_task(int priority){

	enable_fprint_task(priority);


	disable_fprint_task(priority);
}
