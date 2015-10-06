#include "main.h"
#include "rServo.h"

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver();
rServo ankle = rServo(0);

void setup() {
	// put your setup code here, to run once:
	ankle.move(10);

}

void loop() {
	// put your main code here, to run repeatedly:

}
