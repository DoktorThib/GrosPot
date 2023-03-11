#include "GrosPot_InfraSensor.h"

#include "GrosPot_Serial.h"


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

void check_capteur_ir() {

  int value =0, value1=1, value2=2, value3=3;

  INFRASENSOR_readDataAvG(&value);
  INFRASENSOR_readDataAvD(&value1);
  INFRASENSOR_readDataArG(&value2);
  INFRASENSOR_readDataArD(&value3);

  SERIAL_println("Avg %d AvD %d ArG %d Ard %d", value, value1, value2, value3);
}

bool check_ir_avant(){
  int value =0, value1=1;

  INFRASENSOR_readDataAvG(&value);
  INFRASENSOR_readDataAvD(&value1);

  return (value<LIM_WHITE) && (value1<LIM_WHITE);
}

bool check_ir_arriere(){
  int value =0, value1=1;

  INFRASENSOR_readDataArG(&value);
  INFRASENSOR_readDataArD(&value1);

  SERIAL_println("Avg %d AvD %d", value, value1);


  return (value<LIM_WHITE) && (value1<LIM_WHITE);
}
