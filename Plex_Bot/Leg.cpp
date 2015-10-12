// 
// 
// 

#include "Leg.h"

Leg::Leg(int address[5] , bool rightL)
{

	int limitTemp[10];
	
	for (int i = 0; i < 5; i++) {
		//Declare servo in order of foot to hip.
		servoAddresses[i] = address[i];

		
	}	

	for (int i = 0; i < 10; i++) {
		//create limit array
		if (isRightLeg) {
			limitTemp[i] = rightOffSetList[i];
		}
		else {
			limitTemp[i] = leftOffSetList[i];
		}
	}
	//Initalize the parts of the leg foot to hip again
	ankle.attach(servoAddresses[0], offSetList[servoAddresses[0]],limitTemp[0],limitTemp[1]);
	shin.attach(servoAddresses[1], offSetList[servoAddresses[1]], limitTemp[2], limitTemp[3]);
	knee.attach(servoAddresses[2], offSetList[servoAddresses[2]], limitTemp[4], limitTemp[5]);
	thigh.attach(servoAddresses[3], offSetList[servoAddresses[3]], limitTemp[6], limitTemp[7]);
	hip.attach(servoAddresses[4], offSetList[servoAddresses[4]], limitTemp[8], limitTemp[9]);

	//set the Right leg status
	isRightLeg = rightL;

}

void Leg::leg(int move[5])
{
	if (isRightLeg) 
	{
		ankle.move(-move[0]);
		shin.move(-move[1]);
		knee.move(-move[2]);
		thigh.move(move[3]);
		hip.move(move[4]);
	}
	else {
		ankle.move(move[0]);
		shin.move(move[1]);
		knee.move(move[2]);
		thigh.move(-move[3]);
		hip.move(-move[4]);
	}
	
}

void Leg::adjLeg(int adj[5])
{
	ankle.adjCenter(adj[1]);
	shin.adjCenter(adj[2]);
	knee.adjCenter(adj[3]);
	thigh.adjCenter(adj[4]);
	hip.adjCenter(adj[5]);
}
