#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN1 9
#define PIN2 10
#define PIN3 11

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(25, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(25, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(41, PIN3, NEO_GRB + NEO_KHZ800);


void setup() {
   #if defined (__AVR_ATtiny85__)
   if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
   #endif
  
  strip1.begin();
  strip1.show(); 

  strip2.begin();
  strip2.show(); 

  strip3.begin();
  strip3.show(); 
}

void loop() {
  
  rainbowCycle(0);
  
}


void rainbowCycle(uint8_t wait) {
  
  uint16_t i, j;
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip3.numPixels(); i++) {
      strip3.setPixelColor(i, Wheel(((i * 256 / strip3.numPixels()) + j) & 255));
    }
    }
    
  uint16_t ia, ja;
  for(ja=0; ja<256*5; ja++) { // 5 cycles of all colors on wheel
    for(ia=0; ia< strip2.numPixels(); ia++) {
      strip2.setPixelColor(ia, Wheel(((ia * 256 / strip2.numPixels()) + ja) & 255));
    }
    }
    
  uint16_t ib, jb;
  for(jb=0; jb<256*5; jb++) { // 5 cycles of all colors on wheel
    for(ib=0; ib< strip1.numPixels(); ib++) {
      strip1.setPixelColor(ib, Wheel(((ib * 256 / strip1.numPixels()) + jb) & 255));
    }
    }
    
    strip3.show();
    delay(1);
    strip2.show();
    delay(1);
    strip1.show();
    delay(1);
}





// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip2.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip2.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip2.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
