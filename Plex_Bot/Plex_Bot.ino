#ifndef Wire_h
#define Wire_h
#endif

#include "rServo.h"

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver(0x40);
rServo ankle = rServo(0);

void setup() {
	// put your setup code here, to run once:
	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);


	//driver.setPWMFreq(60);

	digitalWrite(13, HIGH);
	delay(1000);


	driver.setPWM(0, 0, map(120,0, 180, 115, 560));
	Serial.print("Hello");
	//driver.move(ankle);
}

void loop() {
	// put your main code here, to run repeatedly:

}
