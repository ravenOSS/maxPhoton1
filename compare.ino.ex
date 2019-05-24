  softSerial.begin(9600);

  // Input range is in the format R####<\r>
  // R + 4 chars + carriage return + null = 7
  // I will accept only ASCII numeric values, so will shorten this to 5
  // 4 chars between 48 and 57 (inclusive) + null
  char range[5];
  char _tmpchar;
  bool success_flag = false;
  int16_t rangeInt;
  // counter
  uint8_t i=0;
  // Timeout: this should be long enough for 4 readings, and should be
  // triggered iff something has gone really wrong
  //Fix?? Needs to be unisgned long due to size comparison? 
  unsigned long timeout = 20; //Message transmit time
  unsigned long wait = 200; //Up to ~125ms between transmissions

  // Remove junk from the serial line -- this may be a lot if there is no
  // excitation applied and power has been on for a while
  serialBufferClear();

  //Excite the sensor to produce a pulse, if you have selected to do so.
  if (ExPin >= 0){
    pinMode(ExPin, OUTPUT);
    digitalWrite(ExPin, HIGH);
    delay(1);
    digitalWrite(ExPin, LOW);
  }
  
  // Get the 4 characters; if a carriage return is encountered, start fresh
  // from the beginning.
  // Time differences are unsigned; rollovers are a non-issue when differencing

  uint32_t start_time = millis();

  while ( (millis() - start_time) < wait && _tmpchar != 'R'){
    _tmpchar = softSerial.read();
  }
  if(_tmpchar == 'R') {
    start_time = millis();
    while ( (millis() - start_time) < timeout ){ //DEBUG!
      if(softSerial.available()){
        //Fix, Wait for 'R'
        _tmpchar = softSerial.read();
        // Serial.println(_tmpchar); //DEBUG!
        // Test if ASCII number
        if ( (_tmpchar >= 48) && (_tmpchar <= 57) ){
          // Serial.print(" Valid"); //DEBUG!
          range[i] = _tmpchar;
          i += 1;
        }
        else if (_tmpchar == 13){
          // Serial.print(" Reset"); //DEBUG!
          i = 0; // reset to the start of a measurement
        }
      }
      // Break if enough characters are recorded
      // Serial.print("i = "); Serial.println(i); //DEBUG!
      if (i == 4){
        success_flag = true;
        break; 
      }
    }
  }
  // Serial.println("END!"); //DEBUG!
  softSerial.end(); //DEBUG!