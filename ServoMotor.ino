#include <Servo.h>
Servo servoFront1;
Servo servoBack1;
Servo servoFront2;
Servo servoBack2;
const int pinButton = 7;
const int releaseTime = 3;

void setup()
{ 
  pinMode(pinButton, INPUT);
  servoFront1.attach(11);
  servoBack1.attach(0);
  servoFront1.write(0);
  servoBack1.write(0);
  servoFront2.attach(10);
  servoBack2.attach(0);
  servoFront2.write(0);
  servoBack2.write(0);
}

void loop()
{

  if(digitalRead(pinButton)== HIGH){
    releaseCan();
  }
}

void releaseCan() {
  int pos;
  for(pos = 0; pos < 90; pos++) {
    servoFront1.write(pos);
    servoFront2.write(pos);
    delay(releaseTime);
  }
  delay(0);
  for(pos = 90; pos >= 0; pos--) {
    servoFront1.write(pos);
    servoFront2.write(pos);
    delay(releaseTime);
  }
  prepareNextCan();
}

void prepareNextCan() {
  int pos;
  for(pos = 0; pos < 90; pos++) {
    servoBack1.write(pos);
    servoBack2.write(pos);
    delay(releaseTime);
  }
  delay(0);
  for(pos = 90; pos >= 0; pos--) {
    servoBack1.write(pos);
    servoBack2.write(pos);
    delay(releaseTime);
  }
}