
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT start");
}

void loop() {
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

      delay(500);
      }
}
