#include "GrosPot_Motor.h"

#include "Servo.h"

#include "GrosPot_DriverPwm.h"

#include "GrosPot_Serial.h"


Servo escG;   // Création de l'objet permettant le contrôle de l'ESC
Servo escD;   // Création de l'objet permettant le contrôle de l'ESC

int val = 0; // 
int valPrec = 0;

/*TO DO change digital to analog to transmit PWM, not full power*/
/*25 max 156 max 91 middle stop, over or under stop value*/
#define ESC_MIN_BACKWARD 90 //4096 => 2049
#define ESC_MAX_BACKWARD 25

#define ESC_MIN_FORWARD 92 //4096 => 2049
#define ESC_MAX_FORWARD 156


#define ESC_MAX_FORWARD 180 // 0 => 2047
#define ESC_ZERO 91 //0 ou 4096 ou 2048

void MOTOR_init(){
  //MOTOR_forward(0);

  escD.attach(3); // Attached to pin 3
  delay(15);
  escG.attach(5); // Attached to pin 5
  delay(15);

  escD.write(0);
  escG.write(0);
  delay(1000);
  escD.write(180);
  escG.write(180);
  delay(1000);
  escD.write(0);
  escG.write(0);

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

  int speed = map( speed,0,100,ESC_MIN_FORWARD, ESC_MAX_FORWARD);

  SERIAL_println("Value %d", speed);

  escG.write(100);
  escD.write(100);
}

void MOTOR_backward_boost(float speedMotor){

  int speed = map( speed,100,0,ESC_MIN_BACKWARD, ESC_MAX_BACKWARD);

  SERIAL_println("Value %d", speed);

  escG.write(25);
  escD.write(25);
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

void MOTOR_serial_command(){

    val = Serial.parseInt();   // lecture de la valeur passée par le port série
   if (Serial.available() > 0 && valPrec != val) {
    valPrec = val;
      Serial.println(val);
      escD.write(val);
      escG.write(val); 
   }
   delay(15);
}
