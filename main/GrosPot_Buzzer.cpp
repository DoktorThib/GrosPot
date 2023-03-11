#include "GrosPot_Buzzer.h"

void BUZZER_init (){
  pinMode (PIN_BUZZER, OUTPUT);
}

void BUZZER_init_TOF_ok(){
  tone(PIN_BUZZER, 3000, 100);
  delay(100);
  tone(PIN_BUZZER, 2000, 100);
  delay(100);
  tone(PIN_BUZZER, 5000, 100);
  delay(100);
  tone(PIN_BUZZER, 4000, 100);
  delay(100);
  tone(PIN_BUZZER, 5000, 100);
}

void BUZZER_detected_ennemy(){
  tone(PIN_BUZZER, 1000, 300);
  delay(100);
  tone(PIN_BUZZER, 800, 800);
  delay(100);
}