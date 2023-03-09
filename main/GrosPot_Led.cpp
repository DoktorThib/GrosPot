#include "GrosPot_Led.h"


void LED_init (){
    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_LED, HIGH);
}

void LED_on(){
    digitalWrite(PIN_LED, HIGH);
}

void LED_off(){
    digitalWrite(PIN_LED, LOW);
}