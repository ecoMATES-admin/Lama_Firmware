void FSM_MasterTimer() {
  switch (masterTimerState) {
    case masterTimerStates::Idle:
      if (masterCounter % (pumpIntervalInHours * hourInSec * secInMilisec / systemPeriod) == 0) {
        pumpTimingFlag = true;
      }
      if (masterCounter % (samplingIntervalInMin * minInSec * secInMilisec / systemPeriod) == 0) {
        sensorTimingFlag = true;
      }
      if (masterCounter % (dayInSec * secInMilisec / systemPeriod) == 0 ) {
        dayTimingFlag = true;
      }


      if (sensorTimingFlag) {
        masterTimerState = masterTimerStates::CmdSensors;
        sensorTimingFlag = false;
      } else if (pumpTimingFlag) {
        masterTimerState = masterTimerStates::CmdPump;
        pumpTimingFlag = false;
      } else if (dayTimingFlag) {
        masterTimerState = masterTimerStates::NewDay;
        dayTimingFlag = false;
      }
      break;
    case masterTimerStates::CmdPump:
      if (DEBUG) {
        Serial.println("CmdPump");
      }
      masterTimerState = masterTimerStates::Idle;
      break;
    case masterTimerStates::CmdSensors:
      if (DEBUG) {
        Serial.println("CmdSensors");
      }
      masterTimerState = masterTimerStates::Idle;
      break;
    case masterTimerStates::NewDay:
      if (DEBUG) {
        Serial.println("NewDay");
      }
      masterTimerState = masterTimerStates::Idle;
      break;
    default:
      Serial.println("Error: FSM_MasterTimer()");
  }
  masterCounter++;
}
