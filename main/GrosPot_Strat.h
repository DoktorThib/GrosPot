#ifndef STRAT_H_
#define STRAT_H_

#include <Arduino.h>
#include "param.h"

void STRAT_waiting_start(void);
void STRAT_forward_line_rotate(bool* sens);
void STRAT_backward_line_rotate(bool* sens);

#endif