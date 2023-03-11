#include "GrosPot_Strat.h"
#include "GrosPot_InfraSensor.h"
#include "GrosPot_Motor.h"

void STRAT_waiting_start(){
      /**** Wait Black table ****/
  while(check_ir_arriere()){
    delay(10);
  }

  /**** Wait White paper ****/
  while(!check_ir_arriere()){
    delay(10);
  }
}

void STRAT_forward_line_rotate(bool* sens){
    /*ADD Void possibilities, higher limit value ?*/
    if (!check_ir_avant()){
        MOTOR_forward(60);
        /*ADD BOOST IF DETECTION ?*/
        delay(5);
    }
    else{
        *sens=SENS_BACKWARD;
        MOTOR_backward(30);
        MOTOR_backward_boost(50);
        delay(300);
        MOTOR_stop_boost();
        /*MOTOR_rotateRight(70);
        delay(500);*/
    }
}

void STRAT_backward_line_rotate(bool* sens){
    /*ADD Void possibilities, higher limit value ?*/
    if (!check_ir_arriere()){
        MOTOR_backward(60);
        /*ADD BOOST IF DETECTION ?*/
        delay(5);
    }
    else{
        *sens=SENS_FORWARD;
        MOTOR_forward(30);
        MOTOR_forward_boost(50);
        delay(300);
        MOTOR_stop_boost();
        /*MOTOR_rotateLeft(70);
        delay(500);*/
    }
}