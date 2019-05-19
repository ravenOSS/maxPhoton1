/*
 * Project maxPhoton1
 * Description: Second development version of Maxbotix reader
 * Author: David Richards / ravenIoT
 * Date: 5.13.19
 */

// global vars (why?)

 const int length = 4;
 char inBuf[length];
 char inChar;

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello ravenTT!");
  delay(250);
  Serial1.begin(9600, SERIAL_8N1);
  Serial.println("Sonar connected");
}

void loop()
{
  int range = readMax();
  Serial.print("Range: ");
  Serial.println(range);
  delay(1200); //set interval for sensor reading
}

int readMax()
{
  // flush and wait for a range reading
  // Serial1.flush();
 
  while (Serial1.available() > 0  && Serial1.read() != 'R') {
    inChar = Serial1.read();
    if (inChar == 'R') {
      for (int i = 0; i < 4; i++) {
        inBuf[i] = Serial1.read();
      }
    }
    return atoi(inBuf);
  }
  return 0;
}
