#include "rServo.h"


//Attach servos no need with the control board but still declares position
rServo::rServo(int ServoNumber, int Offset = 0)
{
	//declare starting place in servo chain
	_servoAddress = ServoNumber;
	//asign starting position for servo and move there
	_adjOffest(Offset);

	
}


//Moves the servo up and down from 0. -90 would is down and 90 is up, all from netrual.
void rServo::move(int pos)
{
	//ankle.setPWM(pos, 0, _servoAdress);
}

//Used to adjust the center of the servo and store that value
void rServo::adjCenter(int r)
{
	_servoOffset = r;
}

//Adjust the servo min and max of the servo timing
void rServo::adjTiming(int min = _servoMin, int max = _servoMax)
{
	_servoMin = min;
	_serovMax = max;
}

//Returns the position the servo is moved to given the angle
int rServo::position(int angle)
{

	return map(angle, 0, 180, _servoMin, _servoMax);
}