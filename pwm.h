

#ifndef PWM_H
#define PWM_H

#include "NU32.h"

void pwm_init(void);
void pwm_set_freq(int freq);
void pwm_set_duty(int duty_cycle);

#endif
