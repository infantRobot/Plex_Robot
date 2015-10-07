#include "Leg.h"
#include "rServo.h"

#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver(0x40);

int offSet[16] = { -6,7,-6,4,0,5,6,7,8,9,10,2,-2,-2,-9,-9 };

rServo ankle = rServo(11, 2);

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

}

void loop() {
	// put your main code here, to run repeatedly:
	ankle.move(0);
}