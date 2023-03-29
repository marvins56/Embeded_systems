
#include <LiquidCrystal.h>
int resval = 0;  // holds the value
int respin = A5; // sensor pin used
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
   Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(8, 2);

}

void loop() {


  lcd.setCursor(0, 0); 
lcd.println("w-levels");

  resval = analogRead(respin); //Read data from analog pin and store it to resval variable
  
 
  if (resval <= 100) {
    Serial.println("S"+ resval );
    lcd.print("wL_SAFE");
  }
  else if (resval > 100 && resval <= 300) {
lcd.setCursor(0, 1);    
    lcd.print("wL_SAFE");
      
  }
  else if (resval > 300 && resval <= 330) {
    lcd.setCursor(0, 1); 
  lcd.print("wL_WARN");
  }
  else if (resval > 330) {
    lcd.setCursor(0, 1); 
   lcd.print("l_DANGER");
  }
 
  delay(500);
   // clear screen for the next loop:
  lcd.clear();
}
