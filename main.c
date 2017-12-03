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
#include "pot.h"

#define DT 2000000

#define PUMP 0
#define SERVO 1

int main(void) {

  signed short imu_data_array[7];
    
  //Initializations
  NU32_Startup();
  adc_init();
  pwm_init();
  //i2c_init();
  //float imu_offset = imu_init(imu_data_array);


  int P = 1;
  char msg[100];
  int pump_num = 1;
  float degree_count = 0.0;

  pwm_set_freq(20000, PUMP);
  pwm_set_duty(0, Pump_pins.pump1_pin);
  pwm_set_duty(0, Pump_pins.pump2_pin);
  
  pwm_set_freq(100, SERVO);
  pwm_set_duty(15, Whisker_pins.whisker1_pin); //was 15
  pwm_set_duty(15, Whisker_pins.whisker2_pin);

  whisker_init();  
  
  while(1) {

    //Testing
    /****************************** MAIN LOOP *************************************/
    //get degree data for whisker 1
    //imu_read(imu_data_array, 1);
    //degree_count += ((float) DT/7142857)*((imu_data_array[3]*0.0061) - imu_offset);
    //degree_count = pot_get_deg(Pot_pins.pot1_pin);
    
    //rotate whisker 1 accordingly
    //servo_set_to_angle(degree_count, Whisker_pins.whisker1_pin);

    //get degree data for whisker 2
    //imu_read(imu_data_array, 2);
    //degree_count += ((float) DT/7142857)*((imu_data_array[3]*0.0061) - imu_offset);
    //degree_count = pot_get_deg(Pot_pins.pot2_pin);
    
    //rotate whisker 2 accordingly
    //servo_set_to_angle(degree_count, Whisker_pins.whisker2_pin);
    
    //Haptic feedback control loop for pump 1
    control_loop(1, P);

    //Haptic feedback control loop for pump 2
    //control_loop(2, P);
    /******************************************************************************/
    
    //sprintf(msg, "output: %.2f\r\n", degree_count);
    //NU32_WriteUART3(msg);
    
    _CP0_SET_COUNT(0);
    while(_CP0_GET_COUNT() < DT) {}
  } 

  return 0;
}

