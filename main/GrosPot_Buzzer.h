#ifndef BUZZER_H_
#define BUZZER_H_

#include <Arduino.h>
#include "param.h"

void BUZZER_init (void);
void BUZZER_detected_ennemy(void);
void BUZZER_init_TOF_ok(void);

#endif