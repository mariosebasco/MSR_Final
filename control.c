/*
 * Main control loop - Change pump DC voltage 
 * given pressure sensor 
 *
 */

#include "control.h"

void control_loop(int pump_num, int P) {

  unsigned int actual_pressure, desired_pressure;
  unsigned int threshold = 25; //value from whisker lower than this will turn off the pumps
  int error, final_pressure, read_pump;
  int whisker_num = pump_num;
  

  //Depending on  pump number, we use the PIC to input the correct signals
  //Read pressure sensor and whisker data from the adc
  //Perform the control loop to adjust the output pressure

  switch(pump_num) {
  case 1:
    read_pump = Pump_pins.pump1_pin;
    break;
  case 2:
    read_pump = Pump_pins.pump2_pin;
    break;
  case 3:
    read_pump = Pump_pins.pump3_pin;
    break;
  default:
    read_pump = 1;
  }

  actual_pressure = adc_get_volts(read_pump);

  //update pressure
  //read whisker data, if below a certain threshold turn off the pump
  desired_pressure = whisker_get_data(whisker_num);
  if(desired_pressure < threshold) {
    //pot_set_resistance(pump_num, 0);
    pwm_set_duty(0);
  }
  else {
    error = desired_pressure - actual_pressure;
    final_pressure = actual_pressure + P*error;
    if(final_pressure > 100) {final_pressure = 100;}
    if(final_pressure < 0) {final_pressure = 0;}

    pwm_set_duty(final_pressure);
    //pot_set_resistance(final_pressure);
  }

}
