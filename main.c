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


int main(void) {

  //Initializations
  NU32_Startup();
  pwm_init();
  i2c_init();
  adc_init();
  whisker_init();
  imu_init();
  servo_init();

  signed short imu_data_array[7];
  
  int P = 1;
  char msg[100];
  int pump_num = 1;
  float degree_count = 0.0;

  /* pwm_set_freq(100); */
  /* pwm_set_duty(15); */
    
  while(1) {

    //Testing
    //Haptic feedback control loop
    //control_loop(pump_num, P);

    //get gyroscope data
    imu_read(imu_data_array);
    degree_count += ((float) DT/7142857)*(imu_data_array[3]*0.0061 + 1.16);

    //rotate whiskers accordingly
    servo_set_to_angle((int) degree_count);

    sprintf(msg, "G's: %.2f\r\n", degree_count);
    //sprintf(msg, "G's: %.2f\r\n", imu_data_array[3]*0.0061 + 1.2);

    NU32_WriteUART3(msg);
    
    _CP0_SET_COUNT(0);
    while(_CP0_GET_COUNT() < DT) {}
  } 

  return 0;
}

