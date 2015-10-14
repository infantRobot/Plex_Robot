/*
** Base Level Servo control
** r for Robot not to be confused with arduio servo library
*/


#ifndef _RSERVO_h
#define _RSERVO_h

#include <Arduino.h>

#include <Wire.h>
#include "Adafruit_PWMServoDriver.h"

extern Adafruit_PWMServoDriver driver;


class rServo
{
public:
	//Contructor
	rServo();

	//Attach servos no need with the control board but still declares position
	void attach(int ServoNumber, int Offset = 0, int _min = -90, int _max = 90);

	//Moves the servo up and down from 0. -90 would is down and 90 is up, all from netrual.
	void move(int pos);
	//Center the servo
	void center() { move(0); }

	//Used to adjust the center of the servo and store that value
	void adjCenter(int r);		
	//Used to set hard limits that the servo should not go past 
	void adjLimit(int min, int max);
	//Adjust the servo min and max of the servo timing
	void adjTiming(int min, int max);

	//Returns the position the servo is moved to given the angle
	int position(int angle);

	
private:
	//Keeps the servo inside the hard limits
	int limitPos(int angle);

	//_variable for class
	short _servoAddress;
	int _servoOffest; //Positive for a positive offSet
	int _servoMinTiming = 115;
	int _servoMaxTiming = 560;
	int _servoMinPos = -90;
	int _servoMaxPos = 90;
	
};

#endif
