/*
 * read and analyze incoming data from whiskers
 * output value: 0 - 100
 *
 */


#include "whisker.h"

void whisker_init() {
  WHISKER1_BASELINE = adc_get_volts(Whisker_pins.whisker1_pin);
  WHISKER2_BASELINE = adc_get_volts(Whisker_pins.whisker2_pin);
  //WHISKER3_BASELINE = adc_get_volts(Whisker_pins.whisker3_pin);
}

unsigned int whisker_get_data(int whisker_num) {

  int read_whisker;
  int gain = 13;
  unsigned int whisker_data, whisker_output, whisker_baseline;
  char msg[50];
  
  switch(whisker_num) {
  case 1:
    read_whisker = Whisker_pins.whisker1_pin;
    whisker_baseline = WHISKER1_BASELINE;
    break;
  case 2:
    read_whisker = Whisker_pins.whisker2_pin;
    whisker_baseline = WHISKER2_BASELINE;
    break;
  case 3:
    read_whisker = Whisker_pins.whisker3_pin;
    whisker_baseline = WHISKER3_BASELINE;
    break;
  default:
    read_whisker = 3; //first whisker
    whisker_baseline = 5;
    break;
  }

  whisker_data = adc_get_volts(read_whisker);

  whisker_output = abs(whisker_data - whisker_baseline)*gain;
  /* sprintf(msg, "init: %d actual: %d diff: %d\r\n", whisker_baseline, whisker_data, whisker_output); */
  /* NU32_WriteUART3(msg); */

  return whisker_output;
    
}
