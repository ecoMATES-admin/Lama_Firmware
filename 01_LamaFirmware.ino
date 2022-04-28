#include "globalVariables.h"
#include <SoftwareSerial.h>

//##Object intialization##
//SoftwareSerial
SoftwareSerial NodeSerial(SW_RX, SW_TX); //(rx,tx)

void setup() {
  //#Objects
  Serial.begin(9600);
  NodeSerial.begin(115200);
  //#Pins
  pinMode(PUMP, OUTPUT);
  digitalWrite(PUMP, LOW);

}

void loop() {
  unsigned long currentTime = millis();
  if ( currentTime - previousTime >= systemPeriod ) {
    previousTime = currentTime;

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
