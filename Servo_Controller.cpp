#include "Libraries.h"
#include "Pin_Assignments.h"
#include "Analog_Reader.h"
#include "LCD_Controller.h"
#include "Servo_Controller.h"

#import <Arduino.h>

Servo brake_servo;

int i = 0;
int engage_step = 0;
int disengage_step = 0;
float voltage = 0.00;

void servoSetup(){

  brake_servo.attach(BRAKE_SERVO);
  brake_servo.write(ENGAGED);
  delay(ENGAGE_TIME);
  
}

int servoEngage(int control_array[2]){

  engage_step = 0;

  for(i = 0; i++; i <= 180){
    brake_servo.write(i);
    delay(STEP_TIME);
    voltage = brakeSensor();
    if (voltage > 3.00){
      engage_step = i;
      i = 0;
      brake_servo.write(ENGAGED);
      delay(ENGAGE_TIME);
      break;
    }
    else{
      i++;
    }
  }

  return engage_step;
}

void servoDisengage(int control_array[2]){

  disengage_step = 0;

  for(i = ENGAGED; i--; i >= DISENGAGED){
    brake_servo.write(i);
    delay(STEP_TIME);
    voltage = brakeSensor();
    if (voltage > 3.00){
      disengage_step = i;
      i = 0;
      brake_servo.write(DISENGAGED);
      delay(DISENGAGE_TIME);
      break;
    }
    else{
      i--;
    }
  }

  return disengage_step;
  
}
