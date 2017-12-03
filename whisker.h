/*
 * read and analyze incoming data from whiskers
 * output value: 0 - 100
 *
 */


#ifndef WHISKER_H
#define WHISKER_H

#include "NU32.h"
#include "adc.h"

unsigned int WHISKER1_BASELINE;
unsigned int WHISKER2_BASELINE;
unsigned int WHISKER3_BASELINE;

void whisker_init();
unsigned int whisker_get_data(int whisker_num);

#endif
