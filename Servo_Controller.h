#ifndef SERVO_CONTROLLER_H   
#define SERVO_CONTROLLER_H

void servoSetup();
int servoEngage(int control_array[2]);
void servoDisengage(int control_array[2]);

#endif
