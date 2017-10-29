

# Final Project for MSR

## File Descriptions

### main
Main file. Initialize everything, interact with user to start/end tests and set important parameters

### control.c
Main control loop. Reads data from whiskers and pressure sensor. Calculate error and adjust pump pressure accordingly

### adc.c
Read value of the ADC in the PIC32

### mux.c
Mux the value going into the ADC. So far this includes which pressure sensor is read, as well as which whisker.

### pot.c
Control over the potentiometer using I2C (MCP4561 right now). The potentiometer is used to control the pressure the pump outputs.

### whisker.c
Read and process data coming from the whiskers.

### pwm.c
pwm control using OC1 and Timer 2 on the PIC32. Adjustable parameters include frequency and duty cycle.

### i2c.c
Control of the I2C 1 peripheral on the PIC32. Uses SDA1 (D9) SCL1 (D10).

### gpio.c
External I/O expander control using I2C (MCP23008). Might not use in project.
