/*
** Base Level Servo control
** r for Robot not to be confused with arduio servo library
*/


#ifndef rServo_h
#define rServo_h

#include "Arduino.h"

class rServo
{
public:
	//Attach servos no need with the control board but still declares position
	rServo(int ServoNumber, int Offset = 0);

	//Used to adjust the center of the servo and store that value
	void adjCenter(int r);		
	//Moves the servo up and down from 0. -90 would is down and 90 is up, all from netrual.
	void move(int pos);
	
private:
	int servoAddress;
	int servoOffest;
	
};

#endif