#include <LiquidCrystal.h> // Include the LCD library

LiquidCrystal LCD(23, 25, 27, 29, 31, 33); // Define the RS, E, DB4, DB5,DB6, DB7 pins on Liquid display which is called LCD

int trigPin = 24;         // Tell Arduino that trigPin is hooked to 13
int echoPin = 22;         // Tell Arduino that echoPin is hooked to 12

float pingTime;           // Define the pingTime varaible
float distance;           // Define the distance varaible
float speedOfSound = 1264.07;  // Speed of sound is 346.13 m/s at 25 C which is 1246.07 km/h

int redPin = 4;
int greenPin = 3;
int bluePin = 2;
int buzzerPin = 7;

void setup() {
  Serial.begin(9600);     // Start the serial monitor

  pinMode(trigPin, OUTPUT);   // trigPin is an OUTPUT
  pinMode(echoPin, INPUT);    // echoPin is an INPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  LCD.begin(16,2);      // Tell Arduino that LCD has 16 columns and 2 rows
    
}

void loop() {
  
  digitalWrite(trigPin, LOW);    // Set the trigPin initially to LOW
  delayMicroseconds(2000);       // Wait for 2 miliseconds 
  digitalWrite(trigPin, HIGH);   // Set the trigPin to HIGH
  delayMicroseconds(20);         // Send trigger for 20 microseconds 
  digitalWrite(trigPin, LOW);    // Stop sending trigger

  pingTime = pulseIn(echoPin, HIGH);    // Start to listen the triggers from echoPin
  pingTime = pingTime / 1000000.;           // 1 second is equal to 10^6 microseconds
  pingTime = pingTime / 3600.;

  distance = pingTime * speedOfSound;   // Distance = Speed x Time
  distance = distance / 2.;              
  distance = distance * 100000.;           // Convert to cm

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");



 if(distance <= 10){
   digitalWrite(redPin, LOW);
   digitalWrite(buzzerPin, HIGH);   
    }
     if(25 > distance > 10){
      digitalWrite(redPin, HIGH);
      digitalWrite(buzzerPin, LOW);
      delay(75);
      digitalWrite(redPin, LOW);
      digitalWrite(buzzerPin, HIGH);
      delay(75);
      }
       if(40 > distance >= 25){
        digitalWrite(greenPin, HIGH);
        digitalWrite(buzzerPin, LOW);
        delay(150);
        digitalWrite(greenPin, LOW);
        digitalWrite(buzzerPin, HIGH);
        delay(150);
        }
         if(55 > distance >= 40){
          digitalWrite(bluePin, HIGH);
          digitalWrite(buzzerPin, LOW);
          delay(300);
          digitalWrite(bluePin, LOW);
          digitalWrite(buzzerPin, HIGH);
          delay(300);
          }
          else {
            digitalWrite(redPin, HIGH);
            digitalWrite(greenPin, HIGH);
            digitalWrite(bluePin, HIGH);
            digitalWrite(buzzerPin, LOW);
            delay(300);
            }
   
  
//LCD.noCursor();   delay(500);   LCD.cursor();   delay(500); 
  LCD.clear();          // Clear the screen
  LCD.setCursor(0,0);   // Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("The Distance is:");  
  LCD.setCursor(0,1);   // Set LCD cursor to lower left corner, column 0, row 1
  LCD.print(distance);
  LCD.print("cm");


}
