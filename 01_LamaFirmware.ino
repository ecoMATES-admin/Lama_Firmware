#include "globalVariables.h"
#include <SoftwareSerial.h>

//##Object intialization##
//SoftwareSerial
SoftwareSerial NodeSerial(SW_RX, SW_TX); //(rx,tx)

void setup() {
  //#Objects
  Serial.begin(9600);
  //#Pins
  pinMode(PUMPMODE, OUTPUT);
  digitalWrite(PUMPMODE, LOW);
  //delay(15000); // gives power supply time to launch
  

}

void loop() {
  unsigned long currentTime = millis();
  if ( currentTime - previousTime >= systemPeriod ) {
    previousTime = currentTime;

    //FSM
    FSM_Test();
    FSM_Pump();
    FSM_DataLog();

  }

}

void FSM_Test(){
  switch(testState){
    case testStates::Idle:
      pumpCounter++;
      if(testCounter >= 6000){
        testCounter = 1;
        testState = testStates::StartTest;
        digitalWrite(PUMPMODE, HIGH);
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
