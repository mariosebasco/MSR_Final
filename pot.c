/*
 * Potentiometer to move the whiskers
 * Uses AN6 - 7 (B6-7)
 *
 */

#include "pot.h"

int pot_get_deg(int pot_num) {
  int degree_count;
  degree_count = adc_get_volts(pot_num);

  return (degree_count*180)/1024; //Change after testing*****
}
