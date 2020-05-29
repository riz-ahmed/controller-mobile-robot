#include <Servo.h>

Servo myServo;            // define an objet for the servo
int servoControlPin = 9;  // Servo control pin
int pos = 0;              // define position number
int potSensePin = A0;     // analog A0 is for the potentio
int val=0;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoControlPin);   // associate pin 9 to servo control signal
  //myServo.write(0);
}

void loop() {
//
//  // 1. rotate from 0 to 180 deg
//  for(pos=0; pos<180; pos+=1){
//      myServo.write(pos);
//      delay(15);                      // settling time for servo motors dynamics
//    }
//
//  // 2. rotate from 180 to 0 deg
//  for(pos=180; pos>1; pos-=1){
//      myServo.write(pos);
//      delay(15);                      // settling time for servo motors dynamics
//    }

    val = analogRead(potSensePin);
    val = map(val, 0, 1023, 0, 180);
    Serial.println(val);
    myServo.write(val);
    delay(15);
}
