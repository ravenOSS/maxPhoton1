/*
 * Project maxPhoton1
 * Description: Second development version of Maxbotix reader
 * Author: David Richards / ravenIoT
 * Date: 5.13.19
 */

// global vars (why?)
int maxOn = D7; // Photon output pin to toggle pin 4 on Maxbotix
// char range[3];
// char _inputChar;
// int distance;
// int i = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello ravenTT!");
  Serial1.begin(9600);
  Serial.println("Sonar connected");
  pinMode(maxOn, OUTPUT);
  // digitalWrite(maxOn, LOW); // Stop continuous reading mode on sensor
}

void loop() {
  // digitalWrite(maxOn, HIGH); // Stop continuous reading mode on sensor
  // delay(1200);
  //   digitalWrite(maxOn, LOW); // Stop continuous reading mode on sensor
}
// void loop()
// {
//   int distance = getdistance();
//   Serial.println(distance);
//   delay(1500);
// }

// // Trigger sensor read
// void triggerOne()
// {
//   digitalWrite(maxOn, HIGH);
//   delay(200);
//   digitalWrite(maxOn, LOW);
// }

// Get the 4 characters; if a carriage return is encountered, start fresh
// from the beginning.
// Time differences are unsigned; rollovers are a non-issue when differencing

// int getdistance() {
//   Serial1.flush();
//   triggerOne();

//   while ((Serial1.available() > 0)) {
//     _inputChar = Serial1.read();
//     Serial.println(_inputChar); //DEBUG!
//       if (_inputChar == 'R') {
//             // Test if ASCII number
//             if ((_inputChar >= 48) && (_inputChar <= 57)) {
//               Serial.print(" Valid"); //DEBUG!
//           //     range[i] = _inputChar;
//           //     i += 1;
//           //   }
//           //   else if (_inputChar == 13) {
//           //     // Serial.print(" Reset"); //DEBUG!
//           //     i = 0; // reset to the start of a measurement
//           //   }
//           // }
//           // // Break if enough characters are recorded
//           // // Serial.print("i = "); Serial.println(i); //DEBUG!
//           // if (i == 4)
//           // {
//           //   Serial.println(range);
//           //   distance = atoi(range);
//           //   return distance;
//           // }
//               }
//       }
//   }
// }
  // Serial.println("END!"); //DEBUG!
  // Serial1.end(); //DEBUG!

  // const int length = 5;
  // char inBuf[length];
  // char inChar;

  // int maxOn = D0; // Photon output pin to toggle pin 4 on Maxbotix

  // char buf[5]; // Create buffer to handle RxxxCR

  // void setup()
  // {
  //   pinMode(maxOn, OUTPUT);
  //   Serial.begin(9600);
  //   Serial.println("Hello ravenTT!");
  //   Serial1.begin(9600);
  //   Serial.println("Sonar connected");
  //   digitalWrite(maxOn, LOW); // Stop continuous reading mode on sensor
  // }

  // void loop()
  // {
  //   int range = readMax();
  //   Serial.print("Range: ");
  //   Serial.println(range);
  //   delay(1200); //set interval for sensor reading
  // }

  // int readMax()
  // {
  //   while (Serial1.available() > 0 && Serial1.read() != 'R') {
  //     inChar = Serial1.read();
  //     {
  //     if (inChar == 'R')

  //       // Serial.println("We got an R");
  //       for (int i = 0; i < 5; i++)
  //       {
  //       inBuf[i] = Serial1.read();
  //       Serial.println(inBuf[i]);
  //       }
  //     }
  //   }
  //   return atoi(inBuf);
  // }
