// Remote_Control.h

#ifndef _REMOTE_CONTROL_h
#define _REMOTE_CONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
const int numberOfServos = 12;
const int messageLength = 3 + numberOfServos * 2;

//Initiates connection with Poser application
void EstablishConnection();

bool ReadMessage(int rleg[5], int lleg[5]);

void SendResponse();


#endif

