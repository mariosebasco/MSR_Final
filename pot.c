/*
 * Potentiometer file
 * To be used to measure angle of rotation of the finger
 * pot 1 connects to pin 6 on the PIC32
 * pot 2 connects to pin 7 on the PIC32
 */

#include "pot.h"

int pot_get_deg(int pot_number) {

  int degree_count;

  degree_count = adc_get_volts(pot_number);
  
  //convert from volt input to deg ***** FIX THIS AFTER TESTING PROTOTYPE
  return ((degree_count*180)/1024);
}
