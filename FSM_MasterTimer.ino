void FSM_MasterTimer() {
  switch (masterTimerState) {
    case masterTimerStates::Idle:
      if (timer.getCount() - pumptimeSnap >= (pumpIntervalInHours * hourInSec * secInMilisec / systemPeriod)) {
        pumptimeSnap = timer.getCount();
        pumpTimingFlag = true;
      }
      if (timer.getCount() - sampletimeSnap >= (samplingIntervalInMin * minInSec * secInMilisec / systemPeriod)) {
        sampletimeSnap = timer.getCount();
        sensorTimingFlag = true;
      }
      if (timer.getCount() - newDaySnap >= (dayInSec * secInMilisec / systemPeriod)) {
        newDaySnap = timer.getCount();
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
}
