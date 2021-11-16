#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT start");
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float f = dht.readTemperature(true);

  if ( isnan(t) || isnan(h)){
    Serial.println("something went wrong, can't read the sensor");
    } else {
      Serial.print("Temperature is: ");
      Serial.print(t);
      Serial.print("°C");
      Serial.print("\t");
      Serial.print("Humidity is: ");
      Serial.print(h);
      Serial.println("%");

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("t:");
      lcd.print(t);
      lcd.setCursor(8,0);      
      lcd.print("C");
      lcd.setCursor(0,1);
      lcd.print("h:");
      lcd.print(h);
      lcd.setCursor(8,1);      
      lcd.print("%");    
     
      
      delay(1000);
}}
