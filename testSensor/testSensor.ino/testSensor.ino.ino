/*
  3D scaner with infared sensor and two servo motors

  The motors will tilt and pan the sensor to take an image of the object and transmit to to a Matlab script that uses the data to plot.

  Created 20 Sep. 2017

*/
#include "Servo.h" // Included the Servo library

const int analogInPin = A0;  // Analog input pin that the sensor is attached to

Servo topServo;

int posTop = 0;              // Inital top servo position

float sensorValue = 0;        // value read from the pot
int outputValue1 = 0;        // value output to the PWM (analog out)
int outputValue2 = 0;        // value output to the PWM (analog out)

// Out 1 is for the base motor
// Out 2 is for the top motor

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}


void loop() {
    int read1 = 0;
 
    // initalizing average reading variables
  
        read1 = SensorRead();   
        Serial.println(read1); 
         
}
int SensorRead() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  return sensorValue;
}
