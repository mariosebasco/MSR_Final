

# Final Project for MSR 

## Overview. 
The aim of this project is to design and build a system which will give a user control over an array of  <a href="http://hartmann.mech.northwestern.edu/index.php" target="blank">robotic rat whiskers</a>, and accurately and intuitively relate sensory information back in the form of haptic feedback.

## File Descriptions

### main.c
Main file. Initialize everything, interact with user to start/end tests and set important parameters.

### control.c
Main control loop. Reads data from whiskers and pressure sensor. Calculate error and adjust pump pressure accordingly.

### adc.c
Read value from the ADC on the PIC32

### pot.c
potentiometer data is used in deciding how far the user has rotated his finger. From here we get degrees which is later passed on to the servo motors.

### whisker.c
Read and process data coming from the whiskers.

### pwm.c
pwm control using OC1-4 and Timers 2-3 on the PIC32. Adjustable parameters include frequency and duty cycle.

### i2c.c
Control of the I2C 1 peripheral on the PIC32. Uses SDA1 (D9) SCL1 (D10).

### gpio.c
External I/O expander control using I2C (MCP23008). Might not use in project.

### imu.c
Files created to be able to control the whiskers at a distance. The gyroscope data from the user moving his hand will control the servo. (using potentiometer instead of gyro)

### servo.c
Control of the servo motors used to move the rat whiskers.
