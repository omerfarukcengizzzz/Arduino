#include <FastLED.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

#define NUM_LEDS 21
#define DATA_PIN 9
#define CLOCK_PIN 13

#define DHTTYPE DHT22  
#define DHTPIN 10  

CRGB leds[NUM_LEDS];
DHT_Unified dht(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

uint32_t delayMS;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();

  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  
  for(int i = 0; i <= NUM_LEDS; i++){
    //leds[i] = CRGB::Pink;
    leds[i] = CHSV( 100,110, 100);
    FastLED.show();
  }

  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;

    
    delay(1000);
    lcd.setCursor(0, 0);
    lcd.print("Initializing the");
    lcd.setCursor(0, 1);
    lcd.print("system");
    delay(1000);
    lcd.setCursor(7, 1);
    lcd.print(".");
    delay(1000);
    lcd.setCursor(8, 1);
    lcd.print(".");
    delay(1000);
    lcd.setCursor(9, 1);
    lcd.print(".");
    delay(1000);

    lcd.clear();
    delay(1000);
    
    lcd.setCursor(0, 0);
    lcd.print("All systems GO!");

    delay(2000);
    lcd.clear();
    
    
}

void loop() {
  // put your main code here, to run repeatedly:
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));

    lcd.setCursor(0, 0);
    lcd.print("tmp: ");
    lcd.setCursor(5 , 0);
    lcd.print(event.temperature);
    lcd.print(" C");
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));

    lcd.setCursor(0, 1);
    lcd.print("hmd: ");
    lcd.setCursor(5 , 1);
    lcd.print(event.relative_humidity);
    lcd.print(" %");
  }

  Serial.println("\n");
  Serial.println("_____________________");
  Serial.println("\n");

   
  

}
