
void FSM_Pump(){
  switch(pumpState){
    case pumpStates::Idle:
    Serial.println("IDLE");
      pumpCounter++;
      if(pumpCounter >= 80000){
        pumpCounter = 0;
        pumpState = pumpStates::PumpOn;
        digitalWrite(PUMPMODE, HIGH);
      }
    break;
    case pumpStates::PumpOn:
    Serial.println("PumpOn");
    pumpCounter++;
      if(pumpCounter >= pumpTimeInCycles){
        pumpCounter = 0;
        pumpState = pumpStates::Idle;
        digitalWrite(PUMPMODE, LOW);
      }
    break;
  }
}