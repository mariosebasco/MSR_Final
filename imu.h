/*
 *
 *
 *
 */

#ifndef IMU_H_
#define IMU_H_

#include "i2c.h"

#define IMU_SLAVE_ADDR 0b1101010

//signed short data_array[7];

float imu_init(signed short *data_array);
signed short concatenate(unsigned char LOW, unsigned char HIGH);
void imu_read(signed short *data_array);


#endif
