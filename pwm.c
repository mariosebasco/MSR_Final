
/*
 * pwm controller - set frequency and duty cycle
 * freq range using prescaler set to 4: ~310HZ - 10MHz
 * For different range, change the prescaler
 */

#include "pwm.h"

void pwm_init() {

  int counts = 849;              //for 23.5KHz

  T2CONbits.TCKPS = 2;           //Timer 2 prescaler set to 4
  PR2 = counts;                    //set the period
  TMR2 = 0;                      //start timer at 0

  OC1CONbits.OCM = 0b110;        //PWM mode without fault pin
  OC1RS = 425;                   //for 50% duty cycle
  OC1R = 425;

  T2CONbits.ON = 1;               //turn on timer 2
  OC1CONbits.ON = 1;              //turn on OC1

}

void pwm_set_freq(int freq) {
  int PRVal = 20000000/freq;
  int OCVal = PRVal/2;

  PR2 = PRVal;
  OC1RS = OCVal;
}

void pwm_set_duty(int duty_cycle) {
  if (duty_cycle > 100) {duty_cycle = 100;}
  if (duty_cycle < 0) {duty_cycle = 0;}

  OC1RS =  (unsigned int) ((duty_cycle/100.0) * PR2);

}
