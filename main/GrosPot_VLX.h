#ifndef VLX_H_
#define VLX_H_

#include <Arduino.h>
#include <VL53L0X.h>

#include "param.h"

#define MIN_DETECT 3
#define MIN_NOT_DETECT 4

// VL15310x object 
struct tof_obj{
  VL53L0X left;
  VL53L0X center;
  VL53L0X right;
};

//number of detection
struct nbDetecTOF{
  int left;
  int center;
  int right;
};

//Update struct ToF
struct dist_tof{
  int front_left;
  int front_center;
  int front_right;
  int back_left;
  int back_center;
  int back_right;
};

/*API*/
void TOF_init();
bool Update_tof(dist_tof dist_TOF );
boolean Is_bot(int front_back);
void Plot_tof();

/*Local function*/
void set_ID_error_handler(int pin_TOF,int tof_id, VL53L0X* tof_obj, uint8_t addr_TOF);
void set_ToF_High_Low(int state);
bool get_measure(VL53L0X tof_obj, int* measure);
boolean is_bot_direction(int* nb_detect, int* nb_NOT_detect );

#endif