#include "Libraries.h"
#include "Pin_Assignments.h"
#include "Analog_Reader.h"
#include "LCD_Controller.h"
#include "Servo_Controller.h"

#import <Arduino.h>

float voltage = 0.00;
float pot_val = 0.00;
float EMA_PREVIOUS_BRAKE = 0.00;
float EMA_PREVIOUS_POT = 0.00;
int brake_status = 0;


void analogReaderSetup(){

  pinMode(TOGGLE_SWITCH, INPUT);
  pinMode(POT, INPUT);
  
  EMA_PREVIOUS_BRAKE = analogRead(BRAKE_SENSOR);
  EMA_PREVIOUS_POT = analogRead(POT);
  
}

void analogReader(int control_array[2]){

  pot_val = analogRead(POT);
  pot_val = (EMA_ALPHA*pot_val)+(EMA_PREVIOUS_POT*(1-EMA_ALPHA));
  EMA_PREVIOUS_POT = pot_val;

}

float brakeSensor(){

  voltage = analogRead(BRAKE_SENSOR);
  voltage = ((EMA_ALPHA*voltage)+(EMA_PREVIOUS_BRAKE*(1-EMA_ALPHA)))*VOLTAGE_MAP;
  EMA_PREVIOUS_BRAKE =  voltage;

  delay(1000);
  return voltage;

}
