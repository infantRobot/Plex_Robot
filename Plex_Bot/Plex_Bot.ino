#include "Leg.h"
#include "rServo.h"
#include "routines.h"

#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"

#define RIGHT 0
#define LEFT 1

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver(0x40);

//Makes the servo line up better 
int offSetList[16] = { -6,7,-6,4,0,5,6,7,8,9,10,2,-2,-2,-9,-9 };

//{footMin, footMax, shinMin, shingMax, ....., hipMin, hipMax}
int hardLegLimits[5 * 2] = { -25, 15, -40, 80, -40, 80, -40, 80, -15, 70 };

//Pointer to the two walking routines for each leg
int *routine[2] = { rWalk, lWalk };

//Useful for setting leg to center
int zero[5] = { 0 };

/*
ankle constraint (30,-15)
*/

//Leg is init. leg moves the servoes
int lLeg[5] = { 0, 1, 2, 3, 4 };
int rLeg[5] = { 15, 14, 13, 12, 11 };

Leg right = Leg(rLeg, true);
Leg left = Leg(lLeg, false);

void setup() {

	//Lets me know the code has started
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH); //LED pin

	// I2C Output enable
	pinMode(17, OUTPUT);
	digitalWrite(17, LOW);
	
	//initiate the 16 Channel shield
	driver.begin();
	driver.setPWMFreq(60);

	int tester[5] = { 15, -30, -25, 15, 15};
	int tester2[5] = { 15, -30, -25, 15, 15 };

	right.leg(zero);
	left.leg(zero);
}

void loop() 
{
	int rLegTemp[5];
	int lLegTemp[5];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//right leg
			rLegTemp[j] = rWalk[i*SERVOS + j];
			lLegTemp[j] = rWalk[i*SERVOS + j + 5];

 		}
		right.leg(rLegTemp);
		left.leg(lLegTemp);

		delay(3000);
	}
}