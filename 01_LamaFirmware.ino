#include "globalVariables.h"
#include "timer.h"
#include "mosfet.h"
#include <SoftwareSerial.h>
#include "HX711.h"

//##Object intialization##
//SoftwareSerial
SoftwareSerial nodeSerial(SW_RX, SW_TX); //(rx,tx)
//LoadCell
HX711 loadCell;
//Timer
Timer timer;
//LEDs
Mosfet ledYellow(LED_YELLOW);
Mosfet ledRed(LED_RED);


void setup() {
  //#Objects
  Serial.begin(9600);
  nodeSerial.begin(115200);
  loadCell.begin(LOADCELL_DOUT, LOADCELL_SCK);
  loadCell.set_scale(calibrationFactor);
  //#Pins
  pinMode(PUMP, OUTPUT);
  digitalWrite(PUMP, LOW);

}

void loop() {
  unsigned long currentTime = millis();
  if ( currentTime - previousTime >= systemPeriod ) {
    previousTime = currentTime;
    timer.increaseCount();
    
    //FSM
    FSM_Test();
    //FSM_Pump();
    FSM_DataLog();

  }

}

void FSM_Test(){
  switch(testState){
    case testStates::Idle:
      testCounter++;
      if(testCounter >= 3000){
        testCounter = 1;
        tempTank++;
        Serial.println(tempTank);
        ph++;
        weight++;
        testState = testStates::StartTest;
      }
    break;
    case testStates::StartTest:
    if(DEBUG){
        Serial.println("testStates::StartTest");
      }
      testFlag= true;
      testState = testStates::Idle;
    break;
  }
  
}
