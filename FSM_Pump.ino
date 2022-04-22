
void FSM_Pump(){
  switch(pumpState){
    case pumpStates::Idle:
      pumpCounter++;
      if(pumpCounter >= 80000){
        pumpCounter = 0;
        pumpState = pumpStates::PumpOn;
        digitalWrite(PUMPMODE, HIGH);
      }
    break;
    case pumpStates::PumpOn:
     if(DEBUG){
        Serial.println("pumpStates::PumpOn");
      }
    pumpCounter++;
      if(pumpCounter >= pumpTimeInCycles){
        pumpCounter = 0;
        pumpState = pumpStates::Idle;
        digitalWrite(PUMPMODE, LOW);
      }
    break;
  }
}
