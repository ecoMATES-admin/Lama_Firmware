//## Pinning##
#define PUMP 3 //Turns pump on and off via relay
#define PUMPMODE 4 // activates test mode of stepper motor -> 30 rot/min

// !!!!! Is it enough to use PUMPMODE to turn pump on and off? ?????

//##Variables##
//#Debug#
#define DEBUG 1
bool testFlag = false;
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


void setup() {
  //#Objects
  Serial.begin(9600);
  //#Pins
  pinMode(PUMP, OUTPUT);
  pinMode(PUMPMODE, OUTPUT);
  digitalWrite(PUMP, HIGH);
  digitalWrite(PUMPMODE, LOW);
  delay(15000); // gives power supply time to launch
  digitalWrite(PUMP, LOW);

}

void loop() {
  unsigned long currentTime = millis();
  if ( currentTime - previousTime >= systemPeriod ) {
    previousTime = currentTime;

    //FSM
    FSM_Pump();

  }

}
