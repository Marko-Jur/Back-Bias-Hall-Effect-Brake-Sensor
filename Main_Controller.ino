#include "Libraries.h"
#include "Pin_Assignments.h"
#include "Analog_Reader.h"
#include "LCD_Controller.h"
#include "Servo_Controller.h"

int control_array[2]={0,0}; // Toggle Switch, Potentiometer
float brake1 = 0.00;
float brake2 = 0.00;

//Counters:

int engage_counter = 0;
int disengage_counter = 0;
int cycles = 0;
int engage_accuracy = 0;
int disengage_accuracy = 0;

void setup() {
  
  Serial.begin(9600);
  
  servoSetup();

  analogReaderSetup();
  
  LCDSetup();
  
}

void loop() {

  analogReader(control_array);

  servoEngage(control_array);

  brake1 = brakeSensor();

  if (brake1 > 3){
    engage_counter++;
  }
  else{
    engage_counter = engage_counter;
  }

  servoDisengage(control_array);

  brake2 = brakeSensor();
  
  if (brake2 < 1.5 ){
    disengage_counter++;
  }
  else{
    disengage_counter = disengage_counter;
  }

  cycles++;

  engage_accuracy = float(float(engage_counter)/float(cycles))*100.00;
  disengage_accuracy = float(float(disengage_counter)/float(cycles))*100.00;

  LCDDisplay(control_array[1],control_array[2], engage_counter, brake1, disengage_counter, brake2, cycles, engage_accuracy, disengage_accuracy);

  /*
  Serial.print("Engage Counter: "); Serial.print(engage_counter); Serial.print("\t");
  Serial.print("Engage Voltage: "); Serial.print(brake1); Serial.print("\t");
  Serial.print("Disengage Counter: "); Serial.print(disengage_counter); Serial.print("\t");
  Serial.print("Disengage Voltage: "); Serial.print(brake2); Serial.print("\t");
  Serial.print("Cycles: "); Serial.print(cycles); Serial.print("\t");
  Serial.print("Engage accuracy: "); Serial.print(engage_accuracy);Serial.print("%"); Serial.print("\t");
  Serial.print("Disengage accuracy: "); Serial.print(disengage_accuracy);Serial.print("%"); Serial.println();
  */

  
  
}
