/*
 * Main control loop - Change pump DC voltage 
 * given pressure sensor 
 *
 */

#ifndef CONTROL_H
#define CONTROL_H

#include "NU32.h"
#include "adc.h"

void control_loop(int pump_num, int P);



#endif
