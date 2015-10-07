// 
// 
// 

#include "Leg.h"

void Leg::init(int one, int two, int three, int four, int five, bool rightL)
{
	//Declare servo in order of foot to hip.
	servoOne	= one;
	servoTwo	= two;
	servoThree	= three;
	servoFour	= four;
	servoFive	= five;
	
	//Initalize the parts of the leg foot to hip again
	ankle = rServo(servoOne, offSetList[one]);
	shin = rServo(servoTwo, offSetList[two]);
	knee = rServo(servoThree, offSetList[three]);
	thigh = rServo(servoFour, offSetList[four]);
	hip = rServo(servoFive, offSetList[five]);

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
