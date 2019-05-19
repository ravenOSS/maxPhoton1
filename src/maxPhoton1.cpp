#include "application.h"
#line 1 "/Users/raventt/MBP_Projects/arduino/maxPhoton1/src/maxPhoton1.ino"
/*
 * Project maxPhoton1
 * Description: Second development version of Maxbotix reader
 * Author: David Richards / ravenIoT
 * Date: 5.13.19
 */

void setup();
#line 8 "/Users/raventt/MBP_Projects/arduino/maxPhoton1/src/maxPhoton1.ino"
void setup()
{
  Serial.begin(9600);
  Serial.println("Hello ravenTT!");
  Serial1.begin(9600);
  Serial.println("Sonar connected");
}

// void loop()
// {
//   int range = readMax();
//   Serial.print("Range: ");
//   Serial.println(range);
//   delay(1200); //set interval for sensor reading
// }

// int readMax()
// {
//   uint8_t length = 4;
//   char inBuf[length];
//   char inByte;

//   // flush and wait for a range reading
//   Serial1.flush();
 
//   while (Serial1.available() > 0  && Serial1.read() != 'R') {
//     inByte = Serial1.read();
//     if (inByte == 'R') {
//       for (int i = 0; i < 3; i++) {
//         inBuf[i] = Serial1.read();
//       }
//     }
//     return atoi(inBuf);
//   }
//   return 0;
// }

// int readMax()   // following code is simply illogical && does not work
//                 // code extracted from another library
//                 // may not work because maxbotix.h (from original library) is deliberately not included
// {
//   uint8_t length = 4;
//   char buffer[5];

//   // flush and wait for a range reading
//   Serial1.flush();

//   while (Serial1.available() > 0 || Serial1.read() != 'R');

//   // read the range
//   for (int i = 0; i < length; i++)
//   {
//     while (!Serial1.available());
  
//     buffer[i] = Serial1.read();
//   }

//   return atoi(buffer);
// }