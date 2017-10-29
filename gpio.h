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


#ifndef GPIO_H
#define GPIO_H

#include "NU32.h"
#include "i2c.h"

#define GPIO_SLAVE_ADDR 0x20

struct Gpio_finger {
  int INDEX_BOT;
  int INDEX_MID;
  int INDEX_TOP;
  int MIDDLE_BOT;
  int MIDDLE_MID;
  int MIDDLE_TOP;
  /* int RING_BOT; */
  /* int RING_MID; */
  /* int RING_TOP; */
  /* int LITTLE_BOT; */
  /* int LITTLE_MID; */
  /* int LITTLE_TOP; */
  /* int THUMB_BOT; */
  /* int THUMB_MID; */
  /* int THUMB_TOP; */
};

struct Gpio_finger gpio_finger;

void gpio_init();
void gpio_set_state(int *fingerInput, int state);

#endif
