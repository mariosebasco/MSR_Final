/*
 * adc functionality - using an0 (B0)
 *
 *
 */


#ifndef ADC_H
#define ADC_H

#include "NU32.h"

#define ADC_SAMPLE_TIME 10

void adc_init();
unsigned int adc_sample_convert(int pin);
unsigned int adc_get_volts(int sample_size);

#endif
