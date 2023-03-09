#ifndef INFRASENSOR_H_
#define INFRASENSOR_H_

#include <Arduino.h>
#include "param.h"

void INFRASENSOR_readDataAvG(int* sensorValue);
void INFRASENSOR_readDataAvD(int* sensorValue);
void INFRASENSOR_readDataArG(int* sensorValue);
void INFRASENSOR_readDataArD(int* sensorValue);

#endif