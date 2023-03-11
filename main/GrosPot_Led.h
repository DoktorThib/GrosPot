#ifndef LED_H_
#define LED_H_

#include <Arduino.h>
#include "param.h"

/*API functions*/
void LED_init (void);

void LED_red_on(void);
void LED_yellow_on(void);
void LED_green_on(void);

void LED_red_off(void);
void LED_yellow_off(void);
void LED_green_off(void);

#endif