// Leg.h
#ifndef _LEG_h
#define _LEG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "rServo.h"
#include "routines.h"
#include "Functions.h"

//Read by the init funciton of the leg and offsets are automatic
extern int offSetList[16];
//Automatic reads in the hard leg limits
extern int rightOffSetList[10];
extern int leftOffSetList[10];

class Leg
{
public:
	//Declare servo address and create rServo objects for leg
	Leg(int address[5], bool rightL);

	//leg is the movement cure for the class. therfore moving the right leg looks like
	//right.leg(int move[5]);
	void leg(int move[5]);

	//Functions for playing the given routines
	//first element of the array, array end element 
	void routine(int *first, int *last);

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

	int _servoAddresses[5];

	bool _isRightLeg;
};

#endif

