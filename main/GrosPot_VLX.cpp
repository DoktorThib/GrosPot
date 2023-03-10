#include "GrosPot_VLX.h"
#include <Wire.h>

#include "GrosPot_DriverPwm.h"

// VL15310x objects declaration
tof_obj tof_front;
tof_obj tof_back;

float last_detection;

/*Declare and init number of detection*/
nbDetecTOF frontTOF_detect = {0,0,0};
nbDetecTOF frontTOF_NOT_detect = {0,0,0};

nbDetecTOF backTOF_detect = {0,0,0};
nbDetecTOF backTOF_NOT_detect = {0,0,0};

void set_ID(){

  // all reset to LOW
  set_ToF_High_Low(LOW);
  delay(100);

  // all unreset to HIGH
  set_ToF_High_Low(HIGH);
  delay(100);

  // all reset to LOW
  set_ToF_High_Low(LOW);
  delay(100);

  /*Set ID for each ToF*/
  set_ID_error_handler(PIN_PWM_SHUT_AvtG, 1, &(tof_front.left), ADDR_I2C_VLX_AvtG);
  set_ID_error_handler(PIN_PWM_SHUT_AvtM, 2, &(tof_front.center), ADDR_I2C_VLX_AvtM);
  set_ID_error_handler(PIN_PWM_SHUT_AvtD, 3, &(tof_front.right), ADDR_I2C_VLX_AvtD);
 
  set_ID_error_handler(PIN_PWM_SHUT_ArrG, 4, &(tof_back.left), ADDR_I2C_VLX_ArrG);
  set_ID_error_handler(PIN_PWM_SHUT_ArrM, 5, &(tof_back.center), ADDR_I2C_VLX_ArrM);
  set_ID_error_handler(PIN_PWM_SHUT_ArrD, 6, &(tof_back.right), ADDR_I2C_VLX_ArrD);
}

/*argument
    int pin_TOF --> Xshut pin
    int tof_id --> number tof identificate it in Serial
    VL53L0X tof_obj --> tof object correponding to front or back, left, center or right
    int addr_TOF --> adress for I2C
    */
void set_ID_error_handler(int pin_TOF,int tof_id, VL53L0X* tof_obj, uint8_t addr_TOF){
  // activating RIGHT_TOF
  DRIVERPWM_setOnOff(pin_TOF, HIGH);
  delay(10);

  //Serial com pin_TOF
  Serial.print("Init ToF ");
  Serial.println(tof_id);

  //tof_right_front.setTimeout(500);
  
  while(!tof_obj->init(true)) {
    Serial.print("Failed to init pin_TOF");
    Serial.println(tof_id);
    delay(500);
  }

  tof_obj->setAddress(addr_TOF);
  Serial.print("ToF has been init ");
  Serial.print(tof_id);
  Serial.println(" -- SUCCESS !");
  delay(100);
}

void set_ToF_High_Low(int state){
  DRIVERPWM_setOnOff(PIN_PWM_SHUT_AvtG, state);
  DRIVERPWM_setOnOff(PIN_PWM_SHUT_AvtM, state);
  DRIVERPWM_setOnOff(PIN_PWM_SHUT_AvtD, state);
  
  DRIVERPWM_setOnOff(PIN_PWM_SHUT_ArrG, state);
  DRIVERPWM_setOnOff(PIN_PWM_SHUT_ArrM, state);
  DRIVERPWM_setOnOff(PIN_PWM_SHUT_ArrD, state);
}

void TOF_init(){
  Serial.println("Init All ToF");

  pinMode(PIN_PWM_SHUT_AvtG, OUTPUT);
  pinMode(PIN_PWM_SHUT_AvtM, OUTPUT);
  pinMode(PIN_PWM_SHUT_AvtD, OUTPUT);

  pinMode(PIN_PWM_SHUT_ArrG, OUTPUT);
  pinMode(PIN_PWM_SHUT_ArrM, OUTPUT);
  pinMode(PIN_PWM_SHUT_ArrD, OUTPUT);

  /*Set all Tof To LOW*/
  set_ToF_High_Low(LOW);//useless TO REMOVE set ID set to LOW at beginning
  set_ID();
  delay(10);

/*Start continous acquisition startContinuous(uint32_t period_ms)*/
/*period_ms == NULL, perma acquisition*/
  tof_front.left.startContinuous();
  delay(10);
  tof_front.center.startContinuous();
  delay(10);
  tof_front.right.startContinuous();
  delay(10);
  tof_back.left.startContinuous();
  delay(10);
  tof_back.center.startContinuous();
  delay(10);
  tof_back.right.startContinuous();
  delay(10);
}

/*argument
    float* measure --> data read for distance
    VL53L0X tof_obj --> tof object correponding to front or back, left, center or right
    */
bool get_measure(VL53L0X tof_obj, int* measure){
  /*Gat distance read by tof_obj*/
  *measure = tof_obj.readRangeContinuousMillimeters();
  /* return true is data is available OR false if data is not readable*/
   return !(tof_obj.timeoutOccurred() || measure ==0);
}

/*argument
struct contain all distance --> API
dist_tof dist_TOF --> get all distance in struct*/
/*TO DO err data*/
bool Update_tof(dist_tof* dist_TOF ){

  int measure = 0;
  bool err = false;

  err = get_measure(tof_front.left, &measure);
  dist_TOF->front_left = measure;

  err = get_measure(tof_front.center, &measure);
  dist_TOF->front_center = measure;

  err = get_measure(tof_front.right, &measure);
  dist_TOF->front_right = measure;

  err = get_measure(tof_back.left, &measure);
  dist_TOF->back_left = measure;

  err = get_measure(tof_back.center, &measure);
  dist_TOF->back_center = measure;

  err = get_measure(tof_back.right, &measure);
  dist_TOF->back_right = measure;

  return err;
}

/*argument
  int front_back --> 0 front / 1 back*/
boolean Is_bot(int front_back){
  bool l = false, c = false, r = false;
  bool detected = false;

  /*IF looking in front of us*/
  if(0 == front_back){
    l = is_bot_direction(&frontTOF_detect.left, &frontTOF_NOT_detect.left);
    c = is_bot_direction(&frontTOF_detect.center, &frontTOF_NOT_detect.center);
    r = is_bot_direction(&frontTOF_detect.right,&frontTOF_NOT_detect.right);
  }
  /*IF we are looking behind us*/
  else if (1 == front_back){
    l = is_bot_direction(&backTOF_detect.left, &backTOF_NOT_detect.left);
    c = is_bot_direction(&backTOF_detect.center, &backTOF_NOT_detect.center);
    r = is_bot_direction(&backTOF_detect.right, &backTOF_NOT_detect.right);
  }
  else{
    /*Add error ?*/
  }

  /*IF one detected something*/
  if(l || c || r){
    last_detection = millis();
    detected = true;
  }
  else{
    /*TO DO timer to verify between two values*/
    if(millis() - last_detection < 1500){
      detected = true;
    }
    else{
      detected = false;
    }
  }
  return detected;
}

/*Description : this function filter wrong data by reading multiple value in raw*/
boolean is_bot_direction(int* nb_detect, int nb_NOT_detect ){
  int measure = 0.0f;
  bool distOK = false;
  bool detected = false;
  get_measure(tof_front.left,&measure);

  /**TO DO check value between 30 and 150, maybe problem with rouleau compresseur*/
  /*TO DO check float in comparaison in "if"*/
  /*IF distance is over 30mm OR between 150mm to 800mm AND dist OK*/
  if((measure < 30 || (measure > 150 && measure < 800)) && false == distOK ){
    /*Got a new detection*/
    nb_detect ++;
    /*IF nb detection is OVER required nb times to detect*/
    if(*nb_detect >= MIN_DETECT){
      /*RESET value and prepared to return seing object*/
      nb_NOT_detect = 0;
      *nb_detect = MIN_DETECT;
      detected = true;
    }
    else{
      detected = false;
    }
  }else{
    nb_NOT_detect ++;
    if(nb_NOT_detect >= MIN_NOT_DETECT){
      nb_detect = 0;
      nb_NOT_detect = MIN_NOT_DETECT;
      detected = false;
    }else{
      detected = true;
    }
  }
  return detected;
}

void Plot_tof(){
  /*Receive dist from all ToF*/
  dist_tof dist_TOF_lcl = {0, 0, 0, 0, 0, 0};
  Update_tof(&dist_TOF_lcl);

  Serial.print("ToF_Left front: ");
  Serial.println(dist_TOF_lcl.front_left);
  Serial.print("ToF_Center front: ");
  Serial.println(dist_TOF_lcl.front_center);
  Serial.print("ToF_Right front: ");
  Serial.println(dist_TOF_lcl.front_right);

  Serial.print("ToF_Left back: ");
  Serial.println(dist_TOF_lcl.back_left);
  Serial.print("ToF_Center back: ");
  Serial.println(dist_TOF_lcl.back_center);
  Serial.print("ToF_Right back: ");
  Serial.println(dist_TOF_lcl.back_right);
  Serial.println();
  Serial.println();
}