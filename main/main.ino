//Libraries

#include "GrosPot_Led.h"
#include "GrosPot_Motor.h"
#include "GrosPot_SR04.h"
#include "GrosPot_InfraSensor.h"
#include "GrosPot_Buzzer.h"
#include "GrosPot_Serial.h"
#include "GrosPot_DriverPwm.h"
#include "GrosPot_VLX.h"

#include "param.h"

#define INIT 0
#define FUITE_AVANT 1
#define FUITE_ARRIERE 2
#define CHECK_ULTRASON 3
#define CHECK_VLX_AVANT 4
#define CHECK_VLX_ARRIERE 5


void check_capteur_ultrason(){
  int value=0, value1=1;
  SR04_dist_cm(&value, &value1);
  SERIAL_println("G %d D %d", value, value1);
}

bool sens_avant_robot=true;
int etat=INIT;

void setup() {
  SERIAL_init();
  DRIVERPWM_init();
  delay(100);
  TOF_init();
  SR04_init();
  LED_init ();
  MOTOR_init();

  /**** Wait Black table ****/
  while(check_ir_arriere()){
    delay(10);
  }

  /**** Wait White paper ****/
  while(!check_ir_arriere()){
    delay(10);
  }

  delay(5000);

  MOTOR_forward(10);
  sens_avant_robot=true;
}


void loop() {

  if(sens_avant_robot){
    if(check_ir_avant()){
      SERIAL_println("Avant");
    }
  }else{
    if(check_ir_arriere()){
      SERIAL_println("Arriere");
    }
  }


}
