#include "rServo.h"


//Attach servos no need with the control board but still declares position
rServo::rServo(int ServoNumber, int Offset)
{
	//declare starting place in servo chain
	_servoAddress = ServoNumber;
	//asign starting position for servo and move there
	adjCenter(Offset);

	
}


//Moves the servo up and down from 0. -90 would is down and 90 is up, all from netrual.
void rServo::move(int pos)
{
	//driver.setPWM(pos, 0, (short) _servoAddress);
}

//Used to adjust the center of the servo and store that value
void rServo::adjCenter(int r)
{
	_servoOffest = r;
}

//Adjust the servo min and max of the servo timing
void rServo::adjTiming(int min, int max)
{
	_servoMin = min;
	_servoMax = max;
}

//Returns the position the servo is moved to given the angle
int rServo::position(int angle)
{

	return map(angle, 0, 180, _servoMin, _servoMax);
}
