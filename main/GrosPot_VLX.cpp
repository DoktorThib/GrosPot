#include "GrosPot_VLX.h"
#include <Wire.h>

#include <Adafruit_VL53L0X.h>
#include "GrosPot_DriverPwm.h"


Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void VLX_init(void){

  DRIVERPWM_setOnOff(PIN_PWM_SHUT_AvtG, false);
  DRIVERPWM_setOnOff(PIN_PWM_SHUT_AvtM, false);
  DRIVERPWM_setOnOff(PIN_PWM_SHUT_AvtD, false);
  DRIVERPWM_setOnOff(PIN_PWM_SHUT_ArrG, false);
  DRIVERPWM_setOnOff(PIN_PWM_SHUT_ArrM, false);
  DRIVERPWM_setOnOff(PIN_PWM_SHUT_ArrD, false);
}

void VLX_getDistCm(int pin, float* value){

}
