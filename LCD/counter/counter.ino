#include <LiquidCrystal.h> // Include the LCD library

LiquidCrystal LCD(13, 12, 11, 10, 9, 8); // Define the RS, E, DB4, DB5,DB6, DB7 pins on LCD

int counter = 0;    // Initialize the counter variable
int second = 1000;  // 1000 microseconds equals to 1 second

void setup() {
  LCD.begin(16,2);      // Tell Arduino that LCD has 16 columns and 2 rows
  LCD.setCursor(0,0);   // Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("Hello World!");   // Print "Hello world" on the screen
  
}

void loop() {
    
  // Count 0 to 10 one by one every single second
   for (counter=0; counter<=10; counter=counter+1){
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("Counter:");   // Print "Hello world" on the screen
    LCD.setCursor(0,1);
    LCD.print(counter);
    LCD.print(" seconds");
    delay(1*second);
    }
    
  // Count 10 to 0 one by one every single second
   for (counter=10; counter>=0; counter=counter-1){
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("Counter:");
    LCD.setCursor(0,1);
    LCD.print(counter);
    LCD.print(" seconds");
    delay(1*second);
    }
}
