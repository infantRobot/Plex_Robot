// 
// 
// 
#include "Remote_Control.h"
#include "LiquidCrystal.h"

#define B0111111111111111 32767

extern LiquidCrystal lcd;

void EstablishConnection()
{
  //wait for a second to begin (keeps the communication line open in case a new program is being downloaded)
  delay(1000);

  //start up the communication
  Serial.begin(9600);

  //buffer to hold the incoming message
  int inputBuffer[40];

  //broadcast our id until someone responds
  while (true)
  {
    //broadcast id
    Serial.print("ROFI");

    //wait for a bit
    delay(100);

    //look for a response
    if (Serial.available() > 1)
    {
      for (int b = 0; b < 2; b++)
        inputBuffer[b] = Serial.read();

      // make sure someone friendly is on the line
      if (inputBuffer[0] == (int)'h' && inputBuffer[1] == (int)'i')
      {
        Serial.print("connected");
        break;
      }
    }
  }
}


bool ReadMessage(int rleg[5], int lleg[5])
{
  // buffer to hold the incoming message
  int inputBuffer[100];

  // read the message
  int index = 0;
  while (Serial.available() > 0)
  {
    inputBuffer[index] = Serial.read();
    index++;
  }

  // make sure the message starts with "cmd" ... otherwise it isn't a valid message
  if (inputBuffer[0] == (int)'c' && inputBuffer[1] == (int)'m' && inputBuffer[2] == (int)'d')
  {
    //set the servo positions
    for (int servo = 0; servo < 11; servo++)
    {
      // each servo position is sent as a 2 byte value (high byte, low byte) integer (from -32,768 to 32,767)
      // this number is encoding the angle of the servo. The number is 100 * the servo angle.  This allows for the
      // storage of 2 significant digits(i.e. the value can be from -60.00 to 60.00 and every value in between).
      // Also remember that the servos have a range of 120 degrees. The angle is written in positions
      // which range from a minimum of 800 (-60 degrees) and go to a maximum of 2200 (60 degrees)
      int value = word(inputBuffer[servo * 2 + 1 + 3], inputBuffer[servo * 2 + 0 + 3]);
      if (value > 6000)
      {
        value = 59536 - value;
        value = map(value, -100, -5900, -5900, -100); 
      }


      //My system only has 5 servos on the legs. Skip the hip and move to left leg
      if (servo != 5) {
        if (servo > 5) {
          lleg[servo - 6] = map(value, -6000, 6000, -60, 60);
        }
        else {
          //Right Leg servo is 0-4
          rleg[servo] = map(value, -6000, 6000, -60, 60);
        }
      }
        
    }
    // a valid messgae was received    
    return true;
  }
  else
    // the message wasn't valid
    return false;

}


void SendResponse()
{
  // Measure the distance 
  //unsigned int distance = MeasureDistance();
  unsigned int distance = 0;

  // Send the distance back (cast it to a byte array ... an int has a high and low byte).
  Serial.write((uint8_t*)&distance, 2);

  // Send the robot status (0 = happy).
  Serial.write((byte)0);

  // End the response.
  Serial.print("done");
}
