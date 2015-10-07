#include "rServo.h"

#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

void setup() {

	//Lets me know the code has started
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH); //LED pin

	// I2C Output enable
	pinMode(17, OUTPUT);
	digitalWrite(17, HIGH);
	
	//initiate the 16 Channel shield
	pwm.begin();
	pwm.setPWMFreq(60);

}

void loop() {
	// put your main code here, to run repeatedly:

	digitalWrite(17, LOW);
	for (int i = 0; i < 16; i++) {
		pwm.setPWM(i, 0, 325);
		delay(50);
	}
}