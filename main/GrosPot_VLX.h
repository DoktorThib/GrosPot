#ifndef VLX_H_
#define VLX_H_

#include <Arduino.h>

#include "param.h"

void VLX_init(void);

void VLX_getDistCm(int pin, float* value);

#endif