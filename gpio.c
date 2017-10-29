/* 
 * Purpose: Talk to external GPIO board (MCP23008)
 * Set which finger and position will be turned on
 *
 * INDEX BOT - GPIO 0
 * INDEX MID - GPIO 1
 * INDEX TOP - GPIO 2
 * MIDDLE BOT - GPIO 3
 * MIDDLE MID - GPIO 4
 * MIDDLE TOP - GPIO 5
 */


#include "gpio.h"

void gpio_init() {
  //set finger struct to all zeros
  gpio_finger.INDEX_BOT = 0;
  gpio_finger.INDEX_MID = 0;
  gpio_finger.INDEX_TOP = 0;
  gpio_finger.MIDDLE_BOT = 0;
  gpio_finger.MIDDLE_MID = 0;
  gpio_finger.MIDDLE_TOP = 0;
  /* gpio_finger.RING_BOT = 0; */
  /* gpio_finger.RING_MID = 0; */
  /* gpio_finger.RING_TOP = 0; */
  /* gpio_finger.LITTLE_BOT = 0; */
  /* gpio_finger.LITTLE_MID = 0; */
  /* gpio_finger.LITTLE_TOP = 0; */
  /* gpio_finger.THUMB_BOT = 0; */
  /* gpio_finger.THUMB_MID = 0; */
  /* gpio_finger.THUMB_TOP = 0; */

  //I2C Init
  //Set up GP0-7 as outputs 
  i2c_master_start(); //send start signal
  i2c_master_send((GPIO_SLAVE_ADDR << 1)); //Send the address with a 0 bit to write
  i2c_master_send(0x00); //address register --> IODIR
  i2c_master_send(0b00000000); //set pins to outputs 
  i2c_master_stop(); //Finished, stop the master
  
}

void gpio_set_state(int *fingerInput, int state) {

  //Take pointer to struct member and set it equal to state
  *fingerInput = state;

  unsigned char output_state;
  output_state = (gpio_finger.MIDDLE_TOP << 5) + (gpio_finger.MIDDLE_MID << 4) + (gpio_finger.MIDDLE_BOT << 3) + (gpio_finger.INDEX_TOP << 2) + (gpio_finger.INDEX_MID << 1) + (gpio_finger.INDEX_BOT << 0);

  //I2C
  //Write new state to GPIO expander
  i2c_master_start(); //send start signal
  i2c_master_send((GPIO_SLAVE_ADDR << 1)); //Send the address with a 0 bit to write
  i2c_master_send(0x0A); //address register --> OLAT
  i2c_master_send(output_state); //set pins to high/low 
  i2c_master_stop(); //Finished, stop the master

}
