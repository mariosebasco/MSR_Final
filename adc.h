/*
 * adc functionality - using an0 (B0)
 *
 *
 */


#ifndef ADC_H
#define ADC_H

#include "NU32.h"

#define ADC_SAMPLE_TIME 10
#define SAMPLE_SIZE 5

struct _Pump_pins {
  int pump1_pin;
  int pump2_pin;
  int pump3_pin;
} Pump_pins;

struct _Whisker_pins {
  int whisker1_pin;
  int whisker2_pin;
  int whisker3_pin;
} Whisker_pins;

struct _Pot_pins {
  int pot1_pin;
  int pot2_pin;
  int pot3_pin;
} Pot_pins;

void adc_init();
unsigned int adc_sample_convert(int pin);
unsigned int adc_get_volts(int pin);

#endif
