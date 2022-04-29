void FSM_LoadCell() {
  switch (loadCellState) {
    case loadCellStates::Idle:
      ledYellow.off();
      ledRed.off();
      if (timer.getCount() - weightSampleSnap >= (weightSampleTimeInSec * secInMilisec / systemPeriod)) {
        loadCellState = loadCellStates::SampleWeight;
      }
      break;
    case loadCellStates::SampleWeight:
      weight = loadCell.get_units();
      if(weight <= reservoirMinWeight){
        loadCellState = loadCellStates::ReservoirEmpty;
      }else if(reservoirMinWeight > weight < reservoirWarningWeight){
        loadCellState = loadCellStates::ReservoirLow;
      }else if(weight > reservoirMaxWeight){
        loadCellState = loadCellStates::ReservoirFull;
      }else{
        loadCellState = loadCellStates::Idle;
      }
      break;
    case loadCellStates::ReservoirEmpty:
      ledRed.on();
      ledYellow.off();
      if (timer.getCount() - weightSampleSnap >= (weightSampleTimeInSec * secInMilisec / systemPeriod)) {
        loadCellState = loadCellStates::SampleWeight;
      }
      break;
    case loadCellStates::ReservoirLow:
      ledRed.on();
      ledYellow.on();
      if (timer.getCount() - weightSampleSnap >= (weightSampleTimeInSec * secInMilisec / systemPeriod)) {
        loadCellState = loadCellStates::SampleWeight;
      }
      break;
    case loadCellStates::ReservoirFull:
      ledRed.off();
      ledYellow.on();
      if (timer.getCount() - weightSampleSnap >= (weightSampleTimeInSec * secInMilisec / systemPeriod)) {
        loadCellState = loadCellStates::SampleWeight;
      }
    break;
  default:
      Serial.println("Error: FSM_LoadCell");
    }
}
