// 
// 
// 

#include "Leg.h"

Leg::Leg(int one, int two, int three, int four, int five, bool rightL)
{
	//Declare servo in order of foot to hip.
	servoOne	= one;
	servoTwo	= two;
	servoThree	= three;
	servoFour	= four;
	servoFive	= five;
	
	//Initalize the parts of the leg foot to hip again
	ankle = rServo(servoOne, 0);
	shin = rServo(servoTwo, 0);
	knee = rServo(servoThree, 0);
	thigh = rServo(servoFour, 0);
	hip = rServo(servoFive, 0);

}

void Leg::leg(int a, int b, int c, int d, int e)
{
	if (isRightLeg) 
	{
		ankle.move(a);
		shin.move(b);
		knee.move(c);
		thigh.move(d);
		hip.move(e);
	}
	else {
		ankle.move(-a);
		shin.move(-b);
		knee.move(-c);
		thigh.move(-d);
		hip.move(-e);
	}
	
}

void Leg::adjLeg(int a, int b, int c, int d, int e)
{
	ankle.adjCenter(a);
	shin.adjCenter(b);
	knee.adjCenter(c);
	thigh.adjCenter(d);
	hip.adjCenter(e);
}
