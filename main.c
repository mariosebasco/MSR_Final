/*
 * Main file x
 * 
 *
 *
 */

#include "NU32.h"
#include "pwm.h"
//#include "gpio.h"
#include "i2c.h"
//#include "pot.h"
#include "adc.h"
//#include "mux.h"
#include "control.h"

#define NUM_WHISKERS 3

int main(void) {

  //Initializations
  NU32_Startup();
  pwm_init();
  i2c_init();
  //gpio_init();
  adc_init();

  int i;
  int P = 1;
  char msg[100];
  
  while(1) {
    //Testing
    //For each whisker you are going to run one control iteration
    for (i = 0; i < NUM_WHISKERS; i++) {
      control_loop(i, P);
      sprintf(msg, "Ran control iteration for whisker %d\r\n", i);
      NU32_WriteUART3(msg);
    }
    
    /* _CP0_SET_COUNT(0); */
    /* while(_CP0_GET_COUNT() < 5000000) {} */
    
    
  }

  return 0;
}

