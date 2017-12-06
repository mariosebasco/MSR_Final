/*
 * pwm controller - set frequency and duty cycle (D0)
 * freq range using prescaler set to 4: ~310HZ - 10MHz
 * For different range, change the prescaler
 */


#ifndef PWM_H
#define PWM_H

#include "NU32.h"

void pwm_init(void);
void pwm_set_freq(int freq, int device);
void pwm_set_duty(int duty_cycle, int device);
void pwm_set_duty_sevo(float duty_cycle, int device);

#endif
