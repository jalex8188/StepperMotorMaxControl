#include <Stepper.h>
#define STEPS 100

Stepper stepper(STEPS, 8, 9, 10, 11);

int incomingByte = 0;
int dir = 0;
int pulseDelaySpeed = 500; //the lower this is the faster it will go

void setup() {
  // set the speed of the motor to 30 RPMs
  pinMode(9,OUTPUT); // set Pin9 as PUL
  pinMode(8,OUTPUT); // set Pin8 as DIR
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte != 10){
      Serial.print("I got:"); // ASCII printable characters
      Serial.println(incomingByte);
      if (incomingByte == 1){
        dir = 1;
        digitalWrite(8,HIGH); // set high level direction
      }
      else if (incomingByte == 0){
//        Serial.println("I got ZERO: "); // ASCII printable characters
        dir = 0;
      }
      else if (incomingByte == 2){
//        Serial.println("I got Two: "); // ASCII printable characters
        dir = 2;
        digitalWrite(8,LOW); // set high level direction
      }
      else if (incomingByte > 10){
        pulseDelaySpeed = (incomingByte - 10) * 10;
      }
//      Serial.print("INCOMING BYTE: "); // ASCII printable characters
//      Serial.println(incomingByte);
//      Serial.print("STEPPER STEP: "); // ASCII printable characters
//      Serial.println(val);
//      stepper.step(val);
    }
  }
  if (dir != 0){
    digitalWrite(9,HIGH); // Output high
    delayMicroseconds(pulseDelaySpeed); // set rotate speed
    digitalWrite(9,LOW); // Output low
    delayMicroseconds(pulseDelaySpeed); // set rotate speed
  }

}
