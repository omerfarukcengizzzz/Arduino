#include <Servo.h>  //inlcude the servo library
int servoPin = 9;   //tell the arduino that the servo is hooked to digital pin 9
int servoAngle = 0;
int maxDeg = 170;   //the maximum angle is 170 degrees for my servo
int minDeg = 15;    //the minimum angle is 15 degrees for my servo
int servoDelay = 10; //delay for 12 microseconds

Servo sg90;   //the name of the servo is sg90

void setup() {
  pinMode(servoPin, OUTPUT);  //servoPin is an OUTPUT
  sg90.attach(servoPin);    //attach the sg90 to servoPin

}

void loop() {
  for(servoAngle = minDeg; servoAngle <= maxDeg; servoAngle = servoAngle +2){
    sg90.write(servoAngle);
    delay(servoDelay);
    }
    
  for(servoAngle = maxDeg; servoAngle >= minDeg; servoAngle = servoAngle -2){
    sg90.write(servoAngle);
    delay(servoDelay);
    }  
}
