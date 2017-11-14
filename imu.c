/*
 *
 *
 *
 */

#include "imu.h"

void imu_init() {
    //Need to change three registers
    i2c_master_start(); //send start signal
    i2c_master_send((IMU_SLAVE_ADDR << 1)); //Send the address with a 0 bit to write
    i2c_master_send(0x10); //address register --> CTRL1_XL
    i2c_master_send(0b10000010); //set CTRL1_XL to the right values
    i2c_master_stop(); //Finished, stop the master
    
    i2c_master_start(); //Now we're going to change the CTRL2_G register
    i2c_master_send((IMU_SLAVE_ADDR << 1));
    i2c_master_send(0x11);
    i2c_master_send(0b10001000);
    i2c_master_stop();   
    
    i2c_master_start(); //Now we're going to change the CTRL3_C register
    i2c_master_send((IMU_SLAVE_ADDR << 1));
    i2c_master_send(0x12);
    i2c_master_send(0x04);
    i2c_master_stop();
}

signed short concatenate(unsigned char LOW,unsigned char HIGH) {
    signed short concat_short;
    concat_short = (HIGH << 8) | LOW;
    
    return concat_short;
    
}

void imu_read(signed short *data_array) {
    //Going to read all seven values -- temp, position, and angle
    //These values are each 16 bytes so we need to grab them as 8 bytes and then concatenate them
    unsigned char master_read_L;
    unsigned char master_read_H;
    signed short concat_short;
    //signed short data_array[7];
    int i;
    i2c_master_start();
    i2c_master_send((IMU_SLAVE_ADDR << 1));
    i2c_master_send(0x20); //We are going to start by reading from the temp register
    i2c_master_restart();
    i2c_master_send((IMU_SLAVE_ADDR << 1) | 1); //Gonna start reading
    for (i = 0;i < 14; i++) {
        if (i%2 == 0) { // if zero you are reading LOW data
            master_read_L = i2c_master_recv();
            i2c_master_ack(0); //Keep sending bytes
        }
        else { //you are reading HIGH data
            master_read_H = i2c_master_recv();
            concat_short = concatenate(master_read_L,master_read_H);
            data_array[i/2] = concat_short;
            if (i == 13) {
                i2c_master_ack(1); //master wants no more readings
            }
            else {
                i2c_master_ack(0); //Keep sending data
            }
        }
    }
    
    i2c_master_stop();

}

float imu_gyro_deg(float gyro_data) {

  static float tot_deg = 0.0; //total degrees the gyro has turned per second

  tot_deg += gyro_data;

  return tot_deg;
}
