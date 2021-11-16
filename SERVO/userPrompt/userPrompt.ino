#include <Servo.h> //including the servo library
int servoPin = 9;  //tell arduino that servo is hooked to pin 9
int servoAngle = 0;  //declare the servoAngle 

Servo sg90; //naming the servo

void setup() {
   Serial.begin(9600); //start the serial monitor on channel 9600
   
   pinMode(servoPin, OUTPUT);  //servoPin is an OUTPUT
   sg90.attach(servoPin);
 }

void loop() {
  Serial.println("What would you wanna set your servo angle?");  //ask the question
  while(Serial.available()==0){}  //wait until the question is answered
  servoAngle = Serial.parseInt(); //read the integers from the user
  sg90.write(servoAngle);  //set the sg90 to servoAngle 

}
