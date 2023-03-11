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

void check_capteur_ir() {

  int value =0, value1=1, value2=2, value3=3;

  INFRASENSOR_readDataAvG(&value);
  INFRASENSOR_readDataAvD(&value1);
  INFRASENSOR_readDataArG(&value2);
  INFRASENSOR_readDataArD(&value3);

  SERIAL_println("Avg %d AvD %d ArG %d Ard %d", value, value1, value2, value3);
}

void check_capteur_ultrason(){
  int value=0, value1=1;
  SR04_dist_cm(&value, &value1);
  SERIAL_println("G %d D %d", value, value1);
}


void setup() {
  SERIAL_init();
  DRIVERPWM_init();
  delay(100);
  TOF_init();
  //SR04_init();
  //BUZZER_init ();
  //LED_init ();
  MOTOR_init();

  delay(1000);

  //delay(10000);

  //MOTOR_forward_boost(10);
}

void loop() {
  //MOTOR_rotateLeft(100);
  /*LED_on();
  delay(200);
  LED_off();
  check_capteur_ir();
  check_capteur_ultrason();*/
  //Plot_tof();
  //delay(1000);
  
  MOTOR_forward_boost (100);
  delay(200);

  /*delay(100);
  Serial.print("coucou");
  val = Serial.parseInt();   // lecture de la valeur passée par le port série
   if (Serial.available() > 0 && valPrec != val) {
    valPrec = val;
      Serial.println(val);
      escD.write(val);
      escG.write(val); 
   }
   delay(15);*/
  //MOTOR_forward(0);
  //MOTOR_forward_boost(0);
}
