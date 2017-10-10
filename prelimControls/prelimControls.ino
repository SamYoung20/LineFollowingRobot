#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotorL = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorR = AFMS.getMotor(2);

int floorThresh = 500;
const int analogInPin0 = A0;  // Analog input pin that the sensor on the left tape is attatched
const int analogInPin1 = A1;  // Analog input pin that the other sensor is attached to

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  AFMS.begin();
  myMotorL->setSpeed(2);
  myMotorR->setSpeed(2);
}


void loop() {
  int readLeft = 0; // initalizing reading variable
  int readRight = 0; // initalizing reading variable
  readL = SensorRead(analogInPin0);
  readR = SensorRead(analogInPin1);
  Serial.println(readL);
  Serial.println(readR);
  // Check incoming Serial input!

  if (Serial.available() > 0) {
    // read incoming serial data:
    String inChar = Serial.readString();
    long number = stringToLong(inChar); //notice the function change to atoL
    // Type the next ASCII value from what you received:
    number++;
    floorThresh = number;
    Serial.println(number);
  }
  ///
  
  if (readL < floorThresh) {
   myMotorL->run(FORWARD);
   delay(50);
   myMotorR->run(BACKWARD);
   delay(50);
  }
  else {
   myMotorL->run(BACKWARD);
   delay(50);
   myMotorR->run(FORWARD);
   delay(50);
  }
}

int SensorRead(analogIn) {
  // read the analog in value:
  sensorValue = analogRead(analogIn);
  return sensorValue;
}

long stringToLong(String value) {
  long outLong = 0;
  long inLong = 1;
  int c = 0;
  int idx = value.length() - 1;
  for (int i = 0; i <= idx; i++) {

    c = (int)value[idx - i];
    outLong += inLong * (c - 48);
    inLong *= 10;
  }
  return outLong;
}

