#include "Leg.h"
#include "rServo.h"
#include "routines.h"

#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver(0x40);

int offSetList[16] = { -6,7,-6,4,0,5,6,7,8,9,10,2,-2,-2,-9,-9 };

int *routine[2] = { rWalk, lWalk };

//Leg is init. leg moves the servoes
Leg right = Leg(0, 1, 2, 3, 4, true);
Leg left = Leg(15, 14, 13, 12, 11, false);

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

	right.leg(0, 0, 0, 0, 0);
	left.leg(0, 0, 0, 0, 0);

	delay(1000);
}

void loop() {
	for (int i = 0; i < SERVOS; i++)
	{
		for (int j = 0; j < LWALKSTEPS; j++)
		{
			right.leg(*(routine[0] + i*j), *(routine[0] + i*j), *(routine[0] + i*j), *(routine[0] + i*j), *(routine[0] + i*j));

		}
	}
}