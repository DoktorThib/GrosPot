#ifndef MOTOR_H_
#define MOTOR_H_

#include <Arduino.h>
#include "Servo.h"

#include "param.h"

void MOTOR_init(void);

// 0=>100%
void MOTOR_forward(float speedMotor);
void MOTOR_backward(float speedMotor);

void MOTOR_forward_boost(float speedMotor);
void MOTOR_backward_boost(float speedMotor);

void MOTOR_rotateRight(float speedMotor);
void MOTOR_rotateLeft(float speedMotor);

void MOTOR_serial_command();

extern Servo escG;   // Création de l'objet permettant le contrôle de l'ESC
extern Servo escD;   // Création de l'objet permettant le contrôle de l'ESC


#endif