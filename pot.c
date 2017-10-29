/*
 *
 * File to control potentiometer (MCP4561)
 * Set to output any voltage between 0 - 3.3V
 */

#include "pot.h"

/* unsigned char pot_convert_volts(float volts) { */
/*   if (volts > 3.3) {volts = 3.3;} */
/*   if (volts < 0) {volts = 0;} */
  
/*   unsigned char resistance = volts*255/3.3; */

/*   return resistance; */
/* } */

void pot_set_resistance(int pump_num, int magnitude) {// magnitude: 0 - 100
  
  //pump number selects the pot_slave_addr
  unsigned char addr;
  switch(pump_num) {
  case 1:
    addr = POT_SLAVE_ADDR1;
  default:
    addr = POT_SLAVE_ADDR1;
  }
  
  //The value sent to the pot is between 0 and 255
  unsigned char resistance = magnitude*255/100;
  
  i2c_master_start(); //send start signal
  i2c_master_send((addr << 1)); //Send the address with a 0 bit to write
  i2c_master_send(0x0); //address 'volatile wiper 0'
  i2c_master_send(resistance); //send the resistance you want
  i2c_master_stop(); //Finish


}
