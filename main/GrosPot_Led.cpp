#include "GrosPot_Led.h"

void LED_init (){
    pinMode(PIN_LED_RED,    OUTPUT);
    pinMode(PIN_LED_YELLOW, OUTPUT);
    pinMode(PIN_LED_GREEN,  OUTPUT);

    digitalWrite(PIN_LED_RED,    HIGH);
    delay(50);
    digitalWrite(PIN_LED_YELLOW, HIGH);
    delay(50);
    digitalWrite(PIN_LED_GREEN,  HIGH);

    delay(300);

    digitalWrite(PIN_LED_RED,    LOW);
    delay(50);
    digitalWrite(PIN_LED_YELLOW, LOW);
    delay(50);
    digitalWrite(PIN_LED_GREEN,  LOW);
    delay(50);
}

void LED_red_on(){
    digitalWrite(PIN_LED_RED, HIGH);
}
void LED_yellow_on(){
    digitalWrite(PIN_LED_YELLOW, HIGH);
}
void LED_green_on(){
    digitalWrite(PIN_LED_GREEN, HIGH);
}

void LED_red_off(){
    digitalWrite(PIN_LED_RED, LOW);
}
void LED_yellow_off(){
    digitalWrite(PIN_LED_YELLOW, LOW);
}
void LED_green_off(){
    digitalWrite(PIN_LED_GREEN, LOW);
}