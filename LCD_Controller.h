#ifndef LCD_CONTROLLER_H   
#define LCD_CONTROLLER_H

void LCDSetup();
void LCDDisplay(int toggle_status,int pot_status, int engage_counter, float brake1, int disengage_counter, float brake2, int cycles, float engage_accuracy, float disengage_accuracy);

#endif
