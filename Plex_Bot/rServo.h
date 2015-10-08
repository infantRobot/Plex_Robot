/*
** Base Level Servo control
** r for Robot not to be confused with arduio servo library
*/


#ifndef rServo_h
#define rServo_h

#include <Arduino.h>

#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"

extern Adafruit_PWMServoDriver driver;


class rServo
{
public:
	//Contructor
	rServo();

	//Attach servos no need with the control board but still declares position
	void attach(int ServoNumber, int Offset = 0);

	//Moves the servo up and down from 0. -90 would is down and 90 is up, all from netrual.
	void move(int pos);
	//Center the servo
	void center() { move(0); }

	//Used to adjust the center of the servo and store that value
	void adjCenter(int r);		
	//Adjust the servo min and max of the servo timing
	void adjTiming(int min, int max);

	//Returns the position the servo is moved to given the angle
	int position(int angle);

	
private:

	//_variable for class
	short _servoAddress;
	int _servoOffest; //Positive for a positive offSet
	int _servoMin = 115;
	int _servoMax = 560;
	
};

#endif
