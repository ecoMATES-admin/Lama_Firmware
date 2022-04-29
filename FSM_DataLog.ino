
void FSM_DataLog() {
  switch (dataLogState) {
    case dataLogStates::SendDummy: //admitedly whack fix for weird bug, that first value does not get uploaded to thinkspeak...
      nodeSerial.println("Dummy");
      dataLogState = dataLogStates::Idle;
      break;
    case dataLogStates::Idle:
      if (testFlag) {
        testFlag=false;
        dataLogState = dataLogStates::SendData;
      }
      break;
    case dataLogStates::SendData:
      if(DEBUG){
        Serial.println("dataLogStates::SendAll");
      }
      dtostrf(tempTank, 4, 2, dataBuffer);
      nodeSerial.print("Xa");
      nodeSerial.println(dataBuffer);
      memset(dataBuffer, 0, 6);
      dtostrf(ph, 4, 2, dataBuffer);
      nodeSerial.print("b");
      nodeSerial.println(dataBuffer);
      memset(dataBuffer, 0, 6);
      dtostrf(weight, 4, 2, dataBuffer);
      nodeSerial.print("c");
      nodeSerial.println(dataBuffer);
      memset(dataBuffer, 0, 6);
      dataLogState = dataLogStates::Idle;
      break;
    default:
      Serial.println("Error: FSM_DataLog()");
  }
}
