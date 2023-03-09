#ifndef DRIVERPWM_H_
#define DRIVERPWM_H_

#include <Arduino.h>

#include "param.h"

void DRIVERPWM_init(void);

void DRIVERPWM_setPwm(int pin, float value);
void DRIVERPWM_setOnOff(int pin, bool value);

#endif