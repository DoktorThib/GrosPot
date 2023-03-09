#include "GrosPot_Motor.h"

#include "GrosPot_DriverPwm.h"

#include "GrosPot_Serial.h"


/*TO DO change digital to analog to transmit PWM, not full power*/

#define ESC_MAX_BACKWARD 2047 //4096 => 2049
#define ESC_MAX_FORWARD 2047 // 0 => 2047
#define ESC_ZERO 4096 //0 ou 4096 ou 2048

void MOTOR_init(){
  MOTOR_forward(0);
  MOTOR_forward_boost(0);
  delay(1000);
  MOTOR_backward_boost(0);
  delay(1000);
  MOTOR_forward_boost(0);

}

void MOTOR_forward(float speedMotor){
  DRIVERPWM_setPwm(PIN_PWM_M11, speedMotor);
  DRIVERPWM_setPwm(PIN_PWM_M12, 0);
  DRIVERPWM_setPwm(PIN_PWM_M21, speedMotor);
  DRIVERPWM_setPwm(PIN_PWM_M22, 0);

}

void MOTOR_backward(float speedMotor){
  DRIVERPWM_setPwm(PIN_PWM_M11, 0);
  DRIVERPWM_setPwm(PIN_PWM_M12, speedMotor);
  DRIVERPWM_setPwm(PIN_PWM_M21, 0);
  DRIVERPWM_setPwm(PIN_PWM_M22, speedMotor);
}

void MOTOR_forward_boost(float speedMotor){

  int value = (int)(speedMotor/100.0*ESC_MAX_FORWARD);

  SERIAL_println("Value %d", value);

  DRIVERPWM_setPwm(PIN_PWM_ESCG, value);
  DRIVERPWM_setPwm(PIN_PWM_ESCD, value);
}

void MOTOR_backward_boost(float speedMotor){

  int value = (int)(ESC_ZERO - speedMotor/100.0*ESC_MAX_BACKWARD);

  DRIVERPWM_setPwm(PIN_PWM_ESCG, value);
  DRIVERPWM_setPwm(PIN_PWM_ESCD, value);
}


void MOTOR_rotateRight(float speedMotor){
  DRIVERPWM_setPwm(PIN_PWM_M11, speedMotor);
  DRIVERPWM_setPwm(PIN_PWM_M12, 0);
  DRIVERPWM_setPwm(PIN_PWM_M21, 0);
  DRIVERPWM_setPwm(PIN_PWM_M22, speedMotor);
}

void MOTOR_rotateLeft(float speedMotor){
  DRIVERPWM_setPwm(PIN_PWM_M11, 0);
  DRIVERPWM_setPwm(PIN_PWM_M12, speedMotor);
  DRIVERPWM_setPwm(PIN_PWM_M21, speedMotor);
  DRIVERPWM_setPwm(PIN_PWM_M22, 0);
}