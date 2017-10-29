/*
 * mux code - Used to mux the pressure sensor and rat whisker data
 *
 *
 */


#ifndef MUX_H
#define MUX_H

#include "NU32.h"

void mux_set_pressure(int pump_num);
void mux_set_whisker(int whisker_num);


#endif
