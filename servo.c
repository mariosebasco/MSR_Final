/*
 *
 *
 *
 *
 */


#include "servo.h"

/* void servo_init() { //set the pwm frequencies that the servos are running to 50HZ */
/*   pwm_set_freq(100, ); */
/*   pwm_set_duty(15); */
/* } */

void servo_set_to_angle(float angle, int servo_num) {
  //angle zero = duty 3%
  //angle 180 = duty 12%
  //int servo_read;
  float output;

  /* switch(servo_num) { */
  /* case 1: */
  /*   servo_read = Whisker_pins.whisker1_pin; */
  /*   break; */
  /* case 2: */
  /*   servo_read = Whisker_pins.whisker2_pin; */
  /*   break; */
  /* case 3: */
  /*   servo_read = Whisker_pins.whisker3_pin; */
  /*   break; */
  /* default: */
  /*   servo_read = Whisker_pins.whisker1_pin; */
  /*   break;     */
  /* } */

  if(angle > 90.0) {angle = 90.0;}
  if(angle < -90.0) {angle = -90.0;}
  output = -angle*9.0/90.0 + 15.0;
  
  pwm_set_duty_servo(output, servo_num);

}
