#ifndef SR04_H_
#define SR04_H_

#include <Arduino.h>
#include "param.h"

void SR04_init(void);

void SR04_dist_cm(int* dist0, int* dist1);

#endif