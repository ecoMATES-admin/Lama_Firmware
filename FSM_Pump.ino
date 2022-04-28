
void FSM_Pump() {
  switch (pumpState) {
    case pumpStates::Idle:
      if (pumpOnFlag) {
        pumpOnFlag = false;
        pumpState = pumpStates::PumpOn;
        digitalWrite(PUMP, HIGH);
      }
      break;
    case pumpStates::PumpOn:
      if (DEBUG) {
        Serial.println("pumpStates::PumpOn");
      }
      pumpCounter++;
      if (pumpCounter >= (pumpTimeInSec * 1000 / systemPeriod)) {
        pumpCounter = 0;
        pumpState = pumpStates::Idle;
        digitalWrite(PUMP, LOW);
      }
      break;
  }
}
