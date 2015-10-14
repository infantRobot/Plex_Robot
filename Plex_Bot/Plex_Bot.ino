#include "rServo.h"
#include "routines.h"
#include "Remote_Control.h"
#include "Leg.h"
#include <LiquidCrystal.h>

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




Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver();

LiquidCrystal lcd(RS_PIN, ENABLE_PIN, DB4_PIN, DB5_PIN, DB6_PIN, DB7_PIN);

//Makes the servo line up better 
int offSetList[16] = { -2,7,-6,4,0,5,6,7,8,9,10,2,-2,-2,-3,-8 };

//{footMin, footMax, shinMin, shingMax, ....., hipMin, hipMax}
int hardLegLimits[5 * 2] = { -25, 15, -40, 80, -40, 80, -40, 80, -15, 70 };

int rightOffSetList[10] = { -25, 15, -40, 80, -80, 45, -40, 80, -15, 70 };
int leftOffSetList[10] = { -25, 15, -40, 80, -80, 45, -40, 80, -15, 70 };


//Useful for setting leg to center
int ZERO_A[5] = { 0, 0, 0, 0, 0 };

/*
ankle constraint (30,-15)
*/

//Leg is init. leg moves the servoes
int lLegAddress[5] = { 0, 1, 2, 3, 4 };
int rLegAddress[5] = { 15, 14, 13, 12, 11 };

Leg right = Leg(rLegAddress, true);
Leg left = Leg(lLegAddress, false);

rServo serv;

void setup() {

	//Lets me know the code has started
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH); //LED pin

	// I2C Output enable
	pinMode(17, OUTPUT);
	digitalWrite(17, HIGH);
	
	//initiate the 16 Channel shield
	driver.begin();
	driver.reset();
	driver.setPWMFreq(60);

	digitalWrite(17, LOW);
	for (int i = 0; i < 16; i++) {
		driver.setPWM(i, 0, pulse(100));
	}
	driver.setPWM(2, 0, 180);
	right.leg(ZERO_A);
	left.leg(ZERO_A);
	delay(500);

	//Initiate LCD
	lcd.begin(8, 2);
	lcd.print("PLEX BOT");

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


	/*
	for (int i = 0; i < 7; i++)
	{
	for (int j = 0; j < 5; j++)
	{
	//right leg
	//rLegTemp[j] = rWalk[i*SERVOS + j];
	//lLegTemp[j] = rWalk[i*SERVOS + j + 5];
	rLegTemp[j] = 0;
	lLegTemp[j] = 0;
	}
	right.leg(rLegTemp);
	left.leg(lLegTemp);
	delay(500);
	}*/

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


int pulse(int degree)
{
	return map(70, 0, 180, 115, 560);
}