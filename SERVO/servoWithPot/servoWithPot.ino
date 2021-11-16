#include <Servo.h>  //inlcude the servo library
int servoPin = 9;   //tell the arduino that the servo is hooked to digital pin 9
int servoAngle = 0;
int potPin = A0;
int potVal = 0;

Servo sg90;   //the name of the servo is sg90

void setup() {
  pinMode(servoPin, OUTPUT);  //servoPin is an OUTPUT
  pinMode(potPin, INPUT);
  sg90.attach(servoPin);    //attach the sg90 to servoPin

}

void loop() {
  potVal = analogRead(potPin);
  servoAngle = (155./1023.)* potVal + 15;   //some math stuff
  sg90.write(servoAngle);  
}
