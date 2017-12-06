/*
 * Potentiometer to move the whiskers
 * Uses AN6 - 7 (B6-7)
 *
 */

#include "pot.h"

float pot_get_deg(int pot_num) {

  unsigned int degree_count;
  //int pot_read;
  //char msg[50];

  /* switch(pot_num) { */
  /* case 1: */
  /*   pot_read = Pot_pins.pot1_pin; */
  /*   break; */
  /* case 2: */
  /*   pot_read = Pot_pins.pot2_pin; */
  /*   break; */
  /* case 3: */
  /*   pot_read = Pot_pins.pot3_pin; */
  /*   break; */
  /* default: */
  /*   pot_read = Pot_pins.pot1_pin; */
  /*   break; */
  /* } */

  degree_count = adc_get_volts(pot_num);
  /* sprintf(msg, "pot reading: %d\r\n", degree_count); */
  /* NU32_WriteUART3(msg); */
  
  
  return (-((float) degree_count)*90.0/36.0 + 120.0);
}
