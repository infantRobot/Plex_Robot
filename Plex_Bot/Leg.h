// Leg.h
#ifndef _LEG_h
#define _LEG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "rServo.h"

class Leg
{
public:
	//Declare servo address and create rServo objects for leg
	void init(int one, int two, int three, int four, int five, bool rightL);

	//leg is the movement cure for the class. therfore moving the right leg looks like
	//right.leg(#,#,#,#,#);
	void leg(int a, int b, int c, int d, int e);
	//return leg to all center
	void center() { leg(0, 0, 0, 0, 0); }

	//Adjust the offsets for the servos.


	//rServo parts of the leg
	rServo ankle;
	rServo shin;
	rServo knee;
	rServo thigh;
	rServo hip;

private:
	uint8_t servoOne;
	uint8_t servoTwo;
	uint8_t servoThree;
	uint8_t servoFour;
	uint8_t servoFive;

	bool isRightLeg;
};

#endif

