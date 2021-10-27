#include "Libraries.h"
#include "Pin_Assignments.h"
#include "Analog_Reader.h"
#include "LCD_Controller.h"
#include "Servo_Controller.h"

#import <Arduino.h>

Servo brake_servo;

void servoSetup(){

  brake_servo.attach(BRAKE_SERVO);
  brake_servo.write(ENGAGED);
  delay(ENGAGE_TIME);
  
}

void servoEngage(int control_array[2]){

  brake_servo.write(ENGAGED);
  delay(ENGAGE_TIME);
  
}

void servoDisengage(int control_array[2]){

  brake_servo.write(DISENGAGED);
  delay(DISENGAGE_TIME);
  
}
