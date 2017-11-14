/*
 *
 *
 *
 *
 */


//#include "servo.h"

void servo_init() { //set the pwm frequencies that the servos are running to 50HZ
  pwm_set_freq(100);
  pwm_set_duty(15);
}

void servo_set_to_angle(int angle) {
  //angle zero = duty 3%
  //angle 180 = duty 12%
  int output;

  if(angle > 90) {angle = 90;}
  if(angle < -90) {angle = -90;}
  output = -angle*9/90 + 15;
  
  pwm_set_duty(output);

}
