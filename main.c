/*
 * Main file 
 * 
 *
 *
 */

#include "NU32.h"
#include "pwm.h"
#include "adc.h"
#include "control.h"
#include "whisker.h"


int main(void) {

  //Initializations
  NU32_Startup();
  pwm_init();
  i2c_init();
  adc_init();
  whisker_init();

  int P = 1;
  char msg[100];
  unsigned int adc_data, whisker_output;
  int pump_num = 1;
    
  while(1) {

    //Testing
    control_loop(pump_num, P);
    
  /*   adc_data = adc_get_volts(pin, 5); */
  /*   sprintf(msg,"adc data: %d\r\n", adc_data); */
  /*   NU32_WriteUART3(msg); */
    _CP0_SET_COUNT(0);
    while(_CP0_GET_COUNT() < 4000000) {}
  } 

  return 0;
}

