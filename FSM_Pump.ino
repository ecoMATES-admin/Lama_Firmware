
void FSM_Pump() {
  switch (pumpState) {
    case pumpStates::Idle:
      if (pumpOnFlag) {
        if(loadCellState == loadCellStates::Idle || loadCellState == loadCellStates::ReservoirFull){
          pumpOnFlag = false;
          pumpState = pumpStates::PumpOn;
        }else if(loadCellState == loadCellStates::ReservoirLow){
          pumpOnFlag = false;
          pumpState = pumpStates::SavingMode;
        }else if(loadCellState == loadCellStates::ReservoirEmpty){
          pumpOnFlag = false;
        }
      }
      break;
    case pumpStates::PumpOn:
      if (DEBUG) {
        Serial.println("pumpStates::PumpOn");
      }
      digitalWrite(PUMP, HIGH);
      pumpCounter++;
      if (pumpCounter >= (pumpTimeInSec * 1000 / systemPeriod)) {
        pumpCounter = 0;
        pumpState = pumpStates::Idle;
        digitalWrite(PUMP, LOW);
      }
      break;
    case pumpStates::SavingMode:
      if (DEBUG) {
        Serial.println("pumpStates::SavingMode");
      }
      digitalWrite(PUMP, HIGH);
      pumpCounter++;
      if (pumpCounter >= (savingModeFactor*pumpTimeInSec * 1000 / systemPeriod)) {
        pumpCounter = 0;
        pumpState = pumpStates::Idle;
        digitalWrite(PUMP, LOW);
      }
      break;
   default:
   Serial.println("Error: FSM_Pump");
  }
}
