/*
 * Main control loop - Change pump DC voltage 
 * given pressure sensor 
 *
 */

#include "control.h"

void control_loop(int pump_num, int P) {

  unsigned int actual_pressure, desired_pressure;
  unsigned int threshold = 10; //value from whisker lower than this will turn off the pumps
  int error, final_pressure;
  

  //Depending on  pump number, we use the mux to input the correct signals
  //Read pressure sensor and whisker data from the adc
  //Perform the control loop to adjust the output pressure

  //change mux output to read pressure sensor - wait some clock ticks before reading?
  mux_set_pressure(pump_num);
  actual_pressure = adc_get_volts(5);

  //update pressure
  //read whisker data, if below a certain threshold turn off the pump
  desired_pressure = whisker_get_data(pump_num);
  if(desired_pressure < threshold) {
    pot_set_resistance(pump_num, 0);
  }
  else {
    error = desired_pressure - actual_pressure;
    final_pressure = actual_pressure + P*error;
    if(final_pressure > 100) {final_pressure = 100;}
    if(final_pressure < 0) {final_pressure = 0;}
    
    pot_set_resistance(final_pressure);
  }

}
