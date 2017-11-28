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
#include "imu.h"
#include "servo.h"

#define DT 2000000

#define PUMP 0
#define SERVO 1

int main(void) {

  signed short imu_data_array[7];
    
  //Initializations
  NU32_Startup();
  pwm_init();
  i2c_init();
  adc_init();
  whisker_init();
  float imu_offset = imu_init(imu_data_array);
  //servo_init();

  int P = 1;
  char msg[100];
  int pump_num = 1;
  float degree_count = 0.0;

  pwm_set_freq(20000, PUMP);
  pwm_set_duty(10, Pump_pins.pump1_pin);
  pwm_set_duty(50, Pump_pins.pump2_pin);
  
  pwm_set_freq(100, SERVO);
  pwm_set_duty(25, Whisker_pins.whisker1_pin); //was 15
  pwm_set_duty(75, Whisker_pins.whisker2_pin);
  
  while(1) {

    //Testing
    //Haptic feedback control loop
    //control_loop(pump_num, P);

    //get gyroscope data
    //imu_read(imu_data_array);
    //degree_count += ((float) DT/7142857)*((imu_data_array[3]*0.0061) - imu_offset);
    //rotate whiskers accordingly
    //servo_set_to_angle((int) degree_count, Whisker_pins.whisker1_pin);

    //sprintf(msg, "output: %.2f\r\n", degree_count);
    //NU32_WriteUART3(msg);
    
    _CP0_SET_COUNT(0);
    while(_CP0_GET_COUNT() < DT) {}
  } 

  return 0;
}

