/*
 * pwm controller - set frequency and duty cycle (D0 - D4 for OC1 - OC4 resp.)
 * freq range using prescaler set to 16: ~20HZ - 0.625MHz
 * For different range, change the prescaler
 */

#include "pwm.h"

void pwm_init() {

  //Set up output compares 1-4 using timers 2 and 3

  int counts = 0;

  T2CONbits.TCKPS = 0b110;       //Timer 2 prescaler set to 64
  PR2 = counts;                  //set the period
  TMR2 = 0;                      //start timer at 0

  T3CONbits.TCKPS = 0b110;       //Timer 3 prescaler set to 64
  PR3 = counts;                  //set the period
  TMR3 = 0;                      //start timer at 0

  OC1CONbits.OCTSEL = 0;
  OC1CONbits.OCM = 0b110;        //PWM mode without fault pin
  OC1RS = 425;
  OC1R = 425;

  OC2CONbits.OCTSEL = 0;
  OC2CONbits.OCM = 0b110;        //PWM mode without fault pin
  OC2RS = 425;
  OC2R = 425;

  OC3CONbits.OCTSEL = 1;  
  OC3CONbits.OCM = 0b110;        //PWM mode without fault pin
  OC3RS = 425;
  OC3R = 425;

  OC4CONbits.OCTSEL = 1;  
  OC4CONbits.OCM = 0b110;        //PWM mode without fault pin
  OC4RS = 425;
  OC4R = 425;

  T2CONbits.ON = 1;               //turn on timer 2
  T3CONbits.ON = 1;               //turn on timer 3

  OC1CONbits.ON = 1;              //turn on OC1
  OC2CONbits.ON = 1;              //turn on OC2
  OC3CONbits.ON = 1;              //turn on OC3
  OC4CONbits.ON = 1;              //turn on OC4

}

void pwm_set_freq(int freq, int device) { //0: pump, 1: servo
  int PRVal = 1250000/freq;
  //int OCVal = PRVal/2;

  if (device == 0) {
    PR2 = PRVal;
    //OC1RS = OCVal;
  }
  else {
    PR3 = PRVal;
    //OC3RS = OCVal;
  }    
}

void pwm_set_duty(int duty_cycle, int device) {//pumps: 0-1 servos: 3:4 
  if (duty_cycle > 100) {duty_cycle = 100;}
  if (duty_cycle < 0) {duty_cycle = 0;}

  switch(device) {
  case 0:
    OC1RS =  (unsigned int) ((duty_cycle/100.0) * PR2);
    break;
  case 1:
    OC2RS =  (unsigned int) ((duty_cycle/100.0) * PR2);
    break;
  case 3:
    OC3RS =  (unsigned int) ((duty_cycle/100.0) * PR3);
    break;
  case 4:
    OC4RS =  (unsigned int) ((duty_cycle/100.0) * PR3);
    break;
  default:
    break;
  }
    
}
