/*
 * Digital potentiometer control
 * uses i2c
 *
 *
 */

#ifndef POT_H
#define POT_H

#include "NU32.h"
#include "i2c.h"

#define POT_SLAVE_ADDR1 0b0101110

//unsigned char pot_convert_volts(float volts);
void pot_set_resistance(int pump_num, int magnitude); //0 - 100: zero volt output - max volt output

#endif
