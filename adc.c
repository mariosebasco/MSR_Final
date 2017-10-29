/*
 * adc functionality - using an0 (B0)
 *
 *
 */

#include "adc.h"

void adc_init() {
  AD1PCFGbits.PCFG0 = 0; //AN0 is an adc pin
  AD1CON3bits.ADCS = 2; //ADC clock period is Tad = 2*(ADCS+1)*Tpb = 2*3*12.5ns = 75ns
  AD1CON1bits.ADON = 1; //turn on A/D converter
}

unsigned int adc_sample_convert(int pin) { // sample & convert the value on the given
  unsigned int elapsed = 0, finish_time = 0;
  AD1CHSbits.CH0SA = pin; // connect chosen pin to MUXA for sampling
  AD1CON1bits.SAMP = 1; // start sampling
  elapsed = _CP0_GET_COUNT();
  finish_time = elapsed + ADC_SAMPLE_TIME;
  while (_CP0_GET_COUNT() < finish_time) {;}
  AD1CON1bits.SAMP = 0;
  while (!AD1CON1bits.DONE) {;}

  return ADC1BUF0;
}

unsigned int adc_get_volts(int sample_size) {

  unsigned int sum = 0;
  int i;
  for (i = 0;i < sample_size; i++) {
    sum += adc_sample_convert(0);
  }

  sum = sum/sample_size;
  
  //convert to value between 0 and 100
  sum = sum*100/1024;

  return sum;
    
}
  
