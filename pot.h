/*
 * Potentiometer to move the whiskers
 * Uses AN6 - 7 (B6-7)
 *
 */

#ifndef POT_H
#define POT_H

#include "adc.h"

float pot_get_deg(int pot_num);

#endif
