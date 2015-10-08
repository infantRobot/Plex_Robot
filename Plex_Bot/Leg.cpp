// 
// 
// 

#include "Leg.h"

Leg::Leg(int address[5] , bool rightL)
{
	//Declare servo in order of foot to hip.
	for (int i = 0; i < 5; i++) {
		servoAddresses[i] = address[i];
	}
	
	//Initalize the parts of the leg foot to hip again
	ankle.attach(servoAddresses[0], offSetList[servoAddresses[0]]);
	shin.attach(servoAddresses[1], offSetList[servoAddresses[1]]);
	knee.attach(servoAddresses[2], offSetList[servoAddresses[2]]);
	thigh.attach(servoAddresses[3], offSetList[servoAddresses[3]]);
	hip.attach(servoAddresses[4], offSetList[servoAddresses[4]]);

	//set the Right leg status
	isRightLeg = rightL;

}

void Leg::leg(int move[5])
{
	if (isRightLeg) 
	{
		ankle.move(constrain(-move[0],-25,15));
		shin.move(constrain(-move[1], -40,80));
		knee.move(constrain(-move[2], -40, 80));
		thigh.move(constrain(move[3], -40, 80));
		hip.move(constrain(move[4], -15, 70));
	}
	else {
		ankle.move(constrain(move[0], -25, 15));
		shin.move(constrain(move[1], -40, 80));
		knee.move(constrain(move[2], -40, 80));
		thigh.move(constrain(-move[3], -40, 80));
		hip.move(constrain(-move[4], -15, 70));
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
