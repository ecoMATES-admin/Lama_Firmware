
void FSM_DataLog() {
  switch (dataLogState) {
    case dataLogStates::Idle:
      if (testFlag) {
        testFlag=false;
        dataLogState = dataLogStates::SendData;
        break;
      }
      break;
    case dataLogStates::SendData:
      if(DEBUG){
        Serial.println("dataLogStates::SendAll");
      }
      dtostrf(tempTank, 4, 2, dataBuffer);
      NodeSerial.print("VXa");
      NodeSerial.println(dataBuffer);
      memset(dataBuffer, 0, 6);
      dtostrf(ph, 4, 2, dataBuffer);
      NodeSerial.print("b");
      NodeSerial.println(dataBuffer);
      memset(dataBuffer, 0, 6);
      dtostrf(weight, 4, 2, dataBuffer);
      NodeSerial.print("c");
      NodeSerial.println(dataBuffer);
      memset(dataBuffer, 0, 6);
      dataLogState = dataLogStates::Idle;
      break;
    default:
      Serial.println("Error: FSM_DataLog()");
  }
}
