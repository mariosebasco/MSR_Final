

# Final Project for MSR

## Overview
The aim of this project is to design and build a system which will give a user control over an array of  <a href="http://hartmann.mech.northwestern.edu/index.php" target="blank">robotic rat whiskers</a>, and accurately and intuitively relate sensory information back in the form of haptic feedback.

## File Descriptions

### main.c
Main file. Initialize everything, interact with user to start/end tests and set important parameters.

### control.c
Main control loop. Reads data from whiskers and pressure sensor. Calculate error and adjust pump pressure accordingly.

### adc.c
Read value from the ADC on the PIC32

### pot.c
Control over the MCP4561 potentiometer using I2C. The potentiometer is used to control the pressure the pump outputs.

### whisker.c
Read and process data coming from the whiskers.

### pwm.c
pwm control using OC1 and Timer 2 on the PIC32. Adjustable parameters include frequency and duty cycle.

### i2c.c
Control of the I2C 1 peripheral on the PIC32. Uses SDA1 (D9) SCL1 (D10).

### gpio.c
External I/O expander control using I2C (MCP23008). Might not use in project.
