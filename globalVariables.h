#ifndef GLOBAL_VAR
#define BLOBAL_VAR

//## Pinning##
#define PUMP 2 // activates test mode of stepper motor -> 30 rot/min
#define LOADCELL_DOUT  6
#define LOADCELL_SCK  5
#define LED_YELLOW 14
#define LED_RED 15

//#Bus
#define SW_TX 4
#define SW_RX 3

//##Variables##
//#Debug#
#define DEBUG 1

//#Test#
bool testFlag = false;
int testCounter = 2000;
enum class testStates:uint8_t{
  Idle, StartTest
};
testStates testState = testStates::Idle;

//#Flags#
//MasterTimer
bool pumpTimingFlag = false;
bool sensorTimingFlag = false;
bool dayTimingFlag = false;
//FSM_Pump
bool pumpOnFlag = false;

//#Sensor data#
float tempTank = 0;
float tempMat = 0;
float ph = 0;
float weight = 0;

//#SystemClock#
unsigned long previousTime = 0; 
const unsigned long systemPeriod = 100; // milliseconds

//#FSM_MasterTimer#
//Timing
uint32_t newDaySnap = 0;
uint32_t pumptimeSnap = 0;
uint32_t sampletimeSnap = 0;
const uint32_t dayInSec = 86400;
const uint16_t hourInSec = 3600;
const uint8_t minInSec = 60;
const uint16_t secInMilisec = 1000;
//States
enum class masterTimerStates:uint8_t{
  Idle, CmdPump, CmdSensors, NewDay
};
masterTimerStates masterTimerState = masterTimerStates::Idle;

//FSM_LoadCell
uint16_t weightSampleSnap = 0;
const uint8_t weightSampleTimeInSec = 5;
float reservoirMaxWeight = 20; //to be adjusted
float reservoirWarningWeight = 6;
float reservoirMinWeight = 1.5; //to be adjusted
float calibrationFactor = 44170;
enum class loadCellStates:uint8_t{
  Idle, SampleWeight, ReservoirEmpty, ReservoirLow, ReservoirFull
};
loadCellStates loadCellState = loadCellStates::Idle;

//#FSM_Pump#
const uint8_t pumpIntervalInHours = 4;
const uint16_t pumpTimeInSec = 100; //100 sec == 1 liter
const float savingModeFactor = 0.5; //percentage of regular volume for saving mode
uint16_t pumpCounter = 0;
//States
enum class pumpStates:uint8_t{
  Idle, PumpOn, SavingMode
};
pumpStates pumpState = pumpStates::Idle;

//FSM_Sensordata
const uint8_t samplingIntervalInMin = 30;

//#FSM_DataLog#
char dataBuffer[6] = {0};
//States
enum class dataLogStates:uint8_t{
  SendDummy, Idle, SendData
};
dataLogStates dataLogState = dataLogStates::SendDummy;

#endif
