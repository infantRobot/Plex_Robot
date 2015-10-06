#include "rServo.h"


//Attach servos no need with the control board but still declares position
rServo(int ServoNumber, int Offset = 0)
{
	//declare starting place in servo chain
	servoAddress = ServoNumber;
	//asign starting position for servo and move there
	adjOffset(Offset);
}


//Moves the servo up and down from 0. -90 would is down and 90 is up, all from netrual.
void move(int pos)
{

}

//Used to adjust the center of the servo and store that value
void adjCenter(int r)
{
	servoOffset = r;
}

//Adjust the servo min and max of the servo timing
void adjTiming(int min = servoMin, int max = servoMax)
{
	servoMin = min;
	serovMax = max;
}

//Returns the position the servo is moved to given the angle
int position(int angle)
{

	return map(angle, 0, 180, servoMin, servoMax);
}