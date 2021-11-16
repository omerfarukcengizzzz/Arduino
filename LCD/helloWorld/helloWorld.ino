#include <LiquidCrystal.h> // Include the LCD library

LiquidCrystal LCD(13, 12, 11, 10, 9, 8); // Define the RS, E, DB4, DB5,DB6, DB7 pins on LCD

void setup() {
  LCD.begin(16,2);      // Tell Arduino that LCD has 16 columns and 2 rows
  LCD.setCursor(0,0);   // Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("Hello World!");   // Print "Hello world" on the screen
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
