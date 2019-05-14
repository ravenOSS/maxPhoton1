/*
 * Project maxPhoton1
 * Description: Second development version of Maxbotix reader
 * Author: David Richards / ravenIoT
 * Date: 5.13.19
 */

void loop()
{
  char readByte(); // nothing to do in this sketch

  digitalWrite(maxOn, HIGH);
  if (Serial1.available()) {
  Serial.println(Serial1.read());
  delayMicroseconds(20);
  digitalWrite(maxOn, LOW);
  Serial.println("End");
  delay(700);
}
}
void loop()
{
  int range = MAXread();
  if (stringComplete)
  {
    stringComplete = false; //reset sringComplete ready for next reading
    Serial.print("Range: ");
    Serial.println(range);
    delay(1500); //set interval for sensor reading
  }
}

int MAXread()
{
  int result;
  char readByte();
  char inData[4]; //char array to read data into
  int index = 0;

  Serial1.flush(); // Clear cache ready for next reading

  while (stringComplete == false)
  {
    Serial.println("Read Sonar"); //debug line
    if (Serial1.available())
    {
    char readByte = Serial1.read();
      if(readByte == 'R');              //read serial input for "R" to mark start of data
      {
        Serial.println("readByte set");
        while (index < 3)               //read next 3 characters for range from sensor
        {
          inData[index] = Serial1.read();
          Serial.print("This is inData char: ");
          Serial.println(inData[index]); //Debug line
          index++;                       // Increment where to write next
        }
        inData[index] = 0x00;           //add a padding byte at end for atoi() function
      }

      readByte = 0;          //reset the readByte ready for next reading
      index = 0;             // Reset index ready for next reading
      stringComplete = true; // Set completion of read to true
      result = atoi(inData); // Changes string data into an integer for use
    }
    return result;
  }
}