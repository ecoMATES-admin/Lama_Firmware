#ifndef GLOBAL_VAR
#define BLOBAL_VAR

//## Pinning##
//#define PUMP 3 //Turns pump on and off via relay
#define PUMPMODE 4 // activates test mode of stepper motor -> 30 rot/min

// !!!!! Is it enough to use PUMPMODE to turn pump on and off? ?????
//--> yes, it is

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

//#Sensor data#
float tempTank = 0;
float tempMat = 0;
float ph = 0;
float weight = 0;

//#SystemClock#
unsigned long previousTime = 0; 
unsigned long systemPeriod = 10; // milliseconds


//#FSM_Pump#
const uint32_t pumpIntervalInCyles = 100*60*15; // 100 cycles/second * 60 seconds * 15 min --> 1 pump cycle every 15 min
const uint32_t pumpTimeInCycles = 100*100; //100 cycles/second * 100 seconds --> 1 pump cycle duration = 100 sec
uint32_t pumpCounter = 74000;
enum class pumpStates:uint8_t{
  Idle, PumpOn
};
pumpStates pumpState = pumpStates::Idle;

//#FSM_DataLog#
char dataBuffer[6] = {0};
enum class dataLogStates:uint8_t{
  SendDummy, Idle, SendData
};
dataLogStates dataLogState = dataLogStates::SendDummy;

#endif
