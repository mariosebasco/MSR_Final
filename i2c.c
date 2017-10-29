
/*
 * I2C interface
 * 100KHz, using SDA1 (D9) and SCL1 (D10)
 * Connect to 3.3V through resistors and to the slave
 *
 *
 */

#include "i2c.h"

void i2c_init() {
  I2C1BRG = 390; //set 100KHz freq clock
  I2C1CONbits.ON = 1; //turn on I2C
}

void i2c_master_start() {
  I2C1CONbits.SEN = 1; //Send the start bit
  while(I2C1CONbits.SEN) {;} //wait for the start bit to be sent
}

void i2c_master_restart(void) {
  I2C1CONbits.RSEN = 1;
  while(I2C1CONbits.RSEN) { ; }
}

void i2c_master_send(unsigned char byte) {
  I2C1TRN = byte; //data being transferred
  while(I2C1STATbits.TRSTAT) {;} //wait for data to be transferred
  if(I2C1STATbits.ACKSTAT) {
    NU32_WriteUART3("I2C1 Master: failed to receive ACK\n"); 
  } //if false slave has not acknowledged
}

unsigned char i2c_master_recv(void) {
  I2C1CONbits.RCEN = 1;
  while(!I2C1STATbits.RBF) {;}
  return I2C1RCV;
}

void i2c_master_ack(int val) {
  I2C1CONbits.ACKDT = val;
  I2C1CONbits.ACKEN = 1;
  while(I2C1CONbits.ACKEN) {;}
}

void i2c_master_stop() {
  I2C1CONbits.PEN = 1; //send a stop
  while(I2C1CONbits.PEN) {;} //wait for stop bit to be received
}
