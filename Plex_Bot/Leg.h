// Leg.h
#ifndef _LEG_h
#define _LEG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "rServo.h"

//Read by the init funciton of the leg and offsets are automatic
extern int offSetList[16];

class Leg
{
public:
	//Declare servo address and create rServo objects for leg
	Leg(int address[5], bool rightL);

	//leg is the movement cure for the class. therfore moving the right leg looks like
	//right.leg(int move[5]);
	void leg(int move[5]);

	//return leg to all center
	//void center() { leg(int zero[5] = { 0 }); }


	//rServo parts of the leg
	rServo ankle;
	rServo shin;
	rServo knee;
	rServo thigh;
	rServo hip;

private:

	//Adjust the offsets for the servos. Only accesed at statup.
	//If you want each servo is public so you could ajust them one by one.
	void adjLeg(int adj[5]);

	int servoAddresses[5];

	bool isRightLeg;
};

#endif

