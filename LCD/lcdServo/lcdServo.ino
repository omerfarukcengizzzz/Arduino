#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);
Servo sg90;

int servoPin = 6;
int potPin = A0;
int servoAngle = 0;
int potVal = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  sg90.attach(servoPin);

  pinMode(servoPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  potVal = analogRead(potPin);
  servoAngle = (155./1023.)* potVal + 15;   //some math stuff
  sg90.write(servoAngle);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Servo Angle is:");
  lcd.setCursor(0,1);
  lcd.print(servoAngle);
  delay(200);

}
