#include "GrosPot_SR04.h"

#include "HCSR04.h"

UltraSonicDistanceSensor distanceSensor0(PIN_TRIGGER, PIN_ECHOD);
UltraSonicDistanceSensor distanceSensor1(PIN_TRIGGER, PIN_ECHOG);

void SR04_init(void){}

void SR04_dist_cm(int* dist0, int* dist1){
    *dist0 = distanceSensor0.measureDistanceCm();
    *dist1 = distanceSensor1.measureDistanceCm();
}



/*
int SR04_conv_time_to_dist(unsigned long duration);
int SR04_dist_cm(int pin);

unsigned short maxDistanceCm = 80;
unsigned short maxTimeoutMicroSec = 0;
float speedOfSoundInCmPerMicroSec = 0.03313 + 0.0000606 * 19.307; // Cair ≈ (331.3 + 0.606 ⋅ ϑ(temperature ambiante)) m/s 

unsigned long maxDistanceDurationMicroSec;

void SR04_init(void){
    pinMode(PIN_TRIGGER, OUTPUT);
    pinMode(PIN_ECHOD, INPUT);
    pinMode(PIN_ECHOG, INPUT);

    // Compute max delay based on max distance with 25% margin in microseconds
    maxDistanceDurationMicroSec = 2.5 * maxDistanceCm / speedOfSoundInCmPerMicroSec;
    if (maxTimeoutMicroSec > 0) {
    	maxDistanceDurationMicroSec = min(maxDistanceDurationMicroSec, maxTimeoutMicroSec);
    }

}

int SR04_conv_time_to_dist(unsigned long duration){
    float distanceCm = duration / 2.0 * speedOfSoundInCmPerMicroSec;
    if (distanceCm == 0 || distanceCm > maxDistanceCm) {
        return -1.0 ;
    } else {
        return distanceCm;
    }
}

int SR04_dist_cm(int pin){
    
   // Make sure that trigger pin is LOW.
    digitalWrite(PIN_TRIGGER, LOW);
    delayMicroseconds(2);
    // Hold trigger for 10 microseconds, which is signal for sensor to measure distance.
    digitalWrite(PIN_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIGGER, LOW);

    // Measure the length of echo signal, which is equal to the time needed for sound to go there and back.
    unsigned long durationMicroSec = pulseIn(pin, HIGH, maxDistanceDurationMicroSec); // can't measure beyond max distance
    
    return SR04_conv_time_to_dist(durationMicroSec);
}

void SR04_dist_cm(int* dist0, int* dist1){    
    *dist0 = SR04_dist_cm(PIN_ECHOD);
    *dist1 = 0; //SR04_dist_cm(PIN_ECHOG);
}
*/