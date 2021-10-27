#include "Libraries.h"
#include "Pin_Assignments.h"
#include "Analog_Reader.h"
#include "LCD_Controller.h"
#include "Servo_Controller.h"

#import <Arduino.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void LCDSetup(){
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Cyc:");
  
  lcd.setCursor(10,0);
  lcd.print("EC:");
  
  lcd.setCursor(0,1);
  lcd.print("DC:");

  lcd.setCursor(10,1);
  lcd.print("EV:");

  lcd.setCursor(0,2);
  lcd.print("DV:");

  lcd.setCursor(9,2);
  lcd.print("ES:");
  
  lcd.setCursor(15,2);
  lcd.print("DS:");

  lcd.setCursor(0,3);
  lcd.print("ER:");

  lcd.setCursor(10,3);
  lcd.print("DR:");


  


  
}



void LCDDisplay(int toggle_switch,int pot_status, int engage_counter, float brake1, int disengage_counter, float brake2, int cycles, float engage_accuracy, float disengage_accuracy){

  lcd.setCursor(0,0);
  lcd.print("Cyc");
  lcd.setCursor(4,0);
  lcd.print(cycles);

  lcd.setCursor(10,0);
  lcd.print("EC:");
  lcd.setCursor(14,0);
  lcd.print(engage_counter);
  
  lcd.setCursor(0,1);
  lcd.print("DC:");

  lcd.setCursor(3,1);
  lcd.print(disengage_counter);

  lcd.setCursor(10,1);
  lcd.print("EV:");
  lcd.setCursor(13,1);
  lcd.print(brake1);
  lcd.setCursor(17,1);
  lcd.print("V");

  lcd.setCursor(0,2);
  lcd.print("DV:");
  lcd.setCursor(3,2);
  lcd.print(brake2);
  lcd.setCursor(7,2);
  lcd.print("V");

  lcd.setCursor(9,2);
  lcd.print("ES:");
  lcd.setCursor(12,2);
  lcd.print("123");

  lcd.setCursor(15,2);
  lcd.print("DS:");
  lcd.setCursor(18,2);
  lcd.print("10");


  lcd.setCursor(0,3);
  lcd.print("ER:");

  lcd.setCursor(3,3);
  lcd.print(engage_accuracy);

  lcd.setCursor(8,3);
  lcd.print("%");
  
  lcd.setCursor(10,3);
  lcd.print("DR:");

  lcd.setCursor(13,3);
  lcd.print(disengage_accuracy);

  lcd.setCursor(18,3);
  lcd.print("%");

  
  
  
}
