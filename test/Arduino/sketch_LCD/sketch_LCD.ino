#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
String strName = "Hello World!";

void setup() {
  // setup LCD's number of columns and rows
  lcd.begin(16,2);

  // print the message
  lcd.print(strName);
}

void loop() {

  // code for auto scrolling
  // first scroll left
//  for(int i = 0; i<strName.length(); i++){
//      lcd.scrollDisplayLeft();
//      delay(350);                 // 350ms wait
//    }
//  // then scroll to right
//    for(int i = 0; i<strName.length(); i++){
//      lcd.scrollDisplayRight();
//      delay(350);                 // 350ms wait
//    }
  
  // Set the LCD's cursor position
  // In the dispay, there are 16 rows and 2 columns, each cell of the display displays a character
  // cursor is set to second column where curently the display is empty
  lcd.setCursor(0,1);

  // millis() command is used to print the number of milli-seconds since arduino was reset, printed in seconds
  lcd.print(millis()/1000);
  lcd.print("s since reset");

}
