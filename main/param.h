#ifndef PARAM_H_
#define PARAM_H_

#include <Arduino.h>

#define PIN_LED 13
#define PIN_BUZZER 8

#define PIN_TRIGGER 9
#define PIN_ECHOG 10
#define PIN_ECHOD 11

#define PIN_INFRASENSOR_AvG A2
#define PIN_INFRASENSOR_AvD A0
#define PIN_INFRASENSOR_ArG A3
#define PIN_INFRASENSOR_ArD A1

#define PIN_PWM_M11 0 // => IN3 => Motor B
#define PIN_PWM_M12 1 // => IN4 => Motor B
#define PIN_PWM_M21 3 // => IN1 => Motor A
#define PIN_PWM_M22 2 // => IN2 => Motor A

#define PIN_PWM_SHUT_AvtG 5
#define PIN_PWM_SHUT_AvtM 6
#define PIN_PWM_SHUT_AvtD 7
#define PIN_PWM_SHUT_ArrG 9
#define PIN_PWM_SHUT_ArrM 10
#define PIN_PWM_SHUT_ArrD 11

#define PIN_PWM_ESCG 3
#define PIN_PWM_ESCD 5

#define ADDR_I2C_PWM 0x40
#define ADDR_I2C_VLX_DEFAULT 0x29
#define ADDR_I2C_VLX_AvtG 0x30 
#define ADDR_I2C_VLX_AvtM 0x31 
#define ADDR_I2C_VLX_AvtD 0x32 
#define ADDR_I2C_VLX_ArrG 0x33 
#define ADDR_I2C_VLX_ArrM 0x34 
#define ADDR_I2C_VLX_ArrD 0x35 


#endif