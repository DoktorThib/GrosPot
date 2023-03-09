#include "GrosPot_Serial.h"

void SERIAL_init(void){
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while(!Serial){
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void SERIAL_println(const char* msg, ...){
  char buffer[40];
  va_list arg;

  va_start(arg,msg);
  vsnprintf(buffer, 40, msg, arg);
  va_end(arg);
  Serial.println(buffer);
}
