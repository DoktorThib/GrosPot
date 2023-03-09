#ifndef SERIAL_H_
#define SERIAL_H_

#include <Arduino.h>
#include "param.h"

void SERIAL_init(void);

void SERIAL_println(const char* msg, ...);

#endif