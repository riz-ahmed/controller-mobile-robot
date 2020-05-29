#include<Stepper.h>

// define the number of steps required to complete 1 full rotation
#define STEPS 100

// initialize stepper library on pins 8 through 11
Stepper stepper(STEPS, 8,9,10,11);

void setup() {
  // set the speed at 90 rpm
  stepper.setSpeed(90);
  // initialize the serial port
  Serial.begin(9600);
}

void loop() {
  // spin clockwise
  Serial.println("shun");
  stepper.step(2048);
  delay(500);

  // spin cc-wise
  Serial.println("ni");
  stepper.step(-2048);
  delay(500);
}
