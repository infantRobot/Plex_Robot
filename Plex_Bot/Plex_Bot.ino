#include "Remote_Control.h"
#include "Leg.h"
#include "rServo.h"
#include "routines.h"
#include "Remote_Control.h"
#include <LiquidCrystal\LiquidCrystal.h>

#include <Wire.h>
#include "Adafruit_PWMServoDriver.h"



#define RIGHT 0
#define LEFT 1

#define RS_PIN 24
#define ENABLE_PIN 25
#define DB4_PIN 26
#define DB5_PIN 27
#define DB6_PIN 28
#define DB7_PIN 29




Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver(0x40);

LiquidCrystal lcd(RS_PIN, ENABLE_PIN, DB4_PIN, DB5_PIN, DB6_PIN, DB7_PIN);

//Makes the servo line up better 
int offSetList[16] = { -6,7,-6,4,0,5,6,7,8,9,10,2,-2,-2,-9,-9 };

//{footMin, footMax, shinMin, shingMax, ....., hipMin, hipMax}
int hardLegLimits[5 * 2] = { -25, 15, -40, 80, -40, 80, -40, 80, -15, 70 };

int rightOffSetList[10] = { -25, 15, -40, 80, -80, 45, -40, 80, -15, 70 };
int leftOffSetList[10] = { -25, 15, -40, 80, -80, 45, -40, 80, -15, 70 };

//Pointer to the two walking routines for each leg
int *routine[2] = { rWalk, lWalk };

//Useful for setting leg to center
int ZERO_A[5] = { 0 };

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

	//Initiate LCD
	lcd.begin(8, 2);
	lcd.print("PLEX BOT");

	//int tester[5] = { 15, -30, -25, 15, 15};
	//int tester2[5] = { 15, -30, -25, 15, 15 };

	right.leg(ZERO_A);
	left.leg(ZERO_A);
	delay(1000);

	EstablishConnection();
}

void loop() 
{
	lcd.setCursor(0, 0);
	lcd.print("Welcome ");
	lcd.setCursor(0, 1);
	lcd.print("User");

	int rLegTemp[5] = { 0 };
	int lLegTemp[5] = { 0 };
	
	while (true) {
		// check to see if there are enough bytes on the serial line for a message
		if (Serial.available() >= messageLength)
			// read the incoming message
			if (ReadMessage(rLegTemp, lLegTemp))
				// respond to the computer that is controlling the robot
				SendResponse();


		right.leg(rLegTemp);
		left.leg(lLegTemp);

	}
	
	
}