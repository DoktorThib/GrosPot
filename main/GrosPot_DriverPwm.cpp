#include "GrosPot_DriverPwm.h"
#include <Wire.h>


#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(ADDR_I2C_PWM);

#define MIN_PULSE_WIDTH       0
#define MAX_PULSE_WIDTH       4096
#define DEFAULT_PULSE_WIDTH   1500
#define FREQUENCY             50

int DRIVERPWM_conv(float value);


void DRIVERPWM_init(){
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);  // Analog servos run at ~50 Hz updates
}

int DRIVERPWM_conv(float value){
  return (int)(value/100.0*(MAX_PULSE_WIDTH-MIN_PULSE_WIDTH)+MIN_PULSE_WIDTH);
}

void DRIVERPWM_setPwm(int pin, float value){
  pwm.setPWM(pin, DRIVERPWM_conv(value), DRIVERPWM_conv(100.0F-value));
}

void DRIVERPWM_setOnOff(int pin, bool value){
  pwm.setPWM(pin, value?MAX_PULSE_WIDTH:MIN_PULSE_WIDTH, value?MIN_PULSE_WIDTH:MAX_PULSE_WIDTH);
}