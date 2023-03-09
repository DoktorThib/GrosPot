#include "GrosPot_InfraSensor.h"

void INFRASENSOR_readDataAvG(int* sensorValue){
    *sensorValue = analogRead(PIN_INFRASENSOR_AvG);
}

void INFRASENSOR_readDataAvD(int* sensorValue){
    *sensorValue = analogRead(PIN_INFRASENSOR_AvD);
}

void INFRASENSOR_readDataArG(int* sensorValue){
    *sensorValue = analogRead(PIN_INFRASENSOR_ArG);
}

void INFRASENSOR_readDataArD(int* sensorValue){
    *sensorValue = analogRead(PIN_INFRASENSOR_ArD);
}
