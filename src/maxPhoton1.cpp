#include "application.h"
#line 1 "/Users/raventt/MBP_Projects/arduino/maxPhoton1/src/maxPhoton1.ino"
/*
 * Project maxPhoton1
 * Description: Second development version of Maxbotix reader
 * Author: David Richards / ravenIoT
 * Date: 5.13.19
 */

void setup();
void loop();
int MAXread();
#line 8 "/Users/raventt/MBP_Projects/arduino/maxPhoton1/src/maxPhoton1.ino"
void setup()
{
  Serial.begin(9600);
  Serial.println("Hello ravenTT!");
  Serial1.begin(9600);
  Serial.println("Sonar connected");
}

void loop()
{
  int range = MAXread();
  Serial.print("Range: ");
  Serial.println(range);
  delay(1200); //set interval for sensor reading
}

int MAXread()
{
  uint8_t length = 4;
  char buffer[5];

  // flush and wait for a range reading
  Serial1.flush();

  while (!Serial1.available() || Serial1.read() != 'R');

  // read the range
  for (int i = 0; i < length; i++)
  {
    while (!Serial1.available());
  
    buffer[i] = Serial1.read();
  }

  return atoi(buffer);
}