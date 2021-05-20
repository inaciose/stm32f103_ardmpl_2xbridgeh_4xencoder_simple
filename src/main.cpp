#include <Arduino.h>

#define SERIAL_BAUDS 115200

#include "motor.h"


#ifndef LED_BUILTIN
  #define LED_BUILTIN PC13
#endif

#define LED_PIN LED_BUILTIN
#define LED_TIME 1000
unsigned long ledTimer = 0;
bool blinkState = false;

//
// encoder control variables
//

#include "encoder.h"

#ifndef ENCODER_MOTOR_H
#define ENCODER_MOTOR_H

#define bodyEncoderSignal FALLING
#define bodyEncoderInputSignal INPUT_PULLUP

// encoder FrontLeftMotor
//#define bodyEncoderFrontLeftInt 0
#define bodyEncoderFrontLeftFunction bodyEncoderFrontLeftCounter
#define bodyEncoderFrontLeftPin PB15 // A pin the interrupt pin
#define bodyEncoderFrontLeftSignal bodyEncoderSignal
#define bodyEncoderFrontLeftInputSignal bodyEncoderInputSignal

// encoder FrontRightMotor
//#define bodyEncoderFrontRightInt 1
#define bodyEncoderFrontRightFunction bodyEncoderFrontRightCounter
#define bodyEncoderFrontRightPin PB14 // A pin: the interrupt pin
#define bodyEncoderFrontRightSignal bodyEncoderSignal
#define bodyEncoderFrontRightInputSignal bodyEncoderInputSignal

// encoder RearLeftMotor
//#define bodyEncoderRearLeftInt 0
#define bodyEncoderRearLeftFunction bodyEncoderRearLeftCounter
#define bodyEncoderRearLeftPin PB13 // A pin the interrupt pin
#define bodyEncoderRearLeftSignal bodyEncoderSignal
#define bodyEncoderRearLeftInputSignal bodyEncoderInputSignal

// encoder RearRightMotor
//#define bodyEncoderRearRightInt 1
#define bodyEncoderRearRightFunction bodyEncoderRearRightCounter
#define bodyEncoderRearRightPin PB12 // A pin: the interrupt pin
#define bodyEncoderRearRightSignal bodyEncoderSignal
#define bodyEncoderRearRightInputSignal bodyEncoderInputSignal

#endif

// encoder rotation direction
bool bodyEncoderFrontLeftDirection; 
bool bodyEncoderFrontRightDirection;
bool bodyEncoderRearLeftDirection; 
bool bodyEncoderRearRightDirection;

// encoder pulses
volatile signed long bodyEncoderFrontLeftTotalPulses = 0;
volatile signed long bodyEncoderFrontRightTotalPulses = 0;
volatile signed long bodyEncoderRearLeftTotalPulses = 0;
volatile signed long bodyEncoderRearRightTotalPulses = 0;

//
// encoder control
//

void bodyEncoderFrontLeftCounter() {
  if(bodyEncoderFrontLeftDirection)
    bodyEncoderFrontLeftTotalPulses ++;
  else
    bodyEncoderFrontLeftTotalPulses ++;
}
 
void bodyEncoderFrontRightCounter() {
  if(bodyEncoderFrontRightDirection)
    bodyEncoderFrontRightTotalPulses ++;
  else
    bodyEncoderFrontRightTotalPulses --;
}

void bodyEncoderRearLeftCounter() {
  if(bodyEncoderRearLeftDirection)
    bodyEncoderRearLeftTotalPulses ++;
  else
    bodyEncoderRearLeftTotalPulses ++;
}
 
void bodyEncoderRearRightCounter() {
  if(bodyEncoderRearRightDirection)
    bodyEncoderRearRightTotalPulses ++;
  else
    bodyEncoderRearRightTotalPulses --;
}

//
// setup function
// 

void setup()
{
  // for LED blink
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(SERIAL_BAUDS);
  Serial.println("Serial.begin done");

  // front left & right
  // set direction pins mode as output
  pinMode(frontLeftMotorForward, OUTPUT);
  pinMode(frontLeftMotorBackward, OUTPUT);
  pinMode(frontRightMotorForward, OUTPUT);
  pinMode(frontRightMotorBackward, OUTPUT);

  // set velocity pins mode as output
  pinMode(frontLeftMotorEn, PWM);
  pinMode(frontRightMotorEn, PWM);
  //pinMode(frontLeftMotorEn, OUTPUT);
  //pinMode(frontRightMotorEn, OUTPUT);

  // rear left & right
  // set direction pins mode as output
  pinMode(rearLeftMotorForward, OUTPUT);
  pinMode(rearLeftMotorBackward, OUTPUT);
  pinMode(rearRightMotorForward, OUTPUT);
  pinMode(rearRightMotorBackward, OUTPUT);

  // set velocity pins mode as output
  pinMode(rearLeftMotorEn, PWM);
  pinMode(rearRightMotorEn, PWM);
  //pinMode(rearLeftMotorEn, OUTPUT);
  //pinMode(rearRightMotorEn, OUTPUT);

  Serial.println("motors config done");

  // assure that motors are stoped
  bodyMotorsControl(0, 0, 0, 0);
  Serial.println("motor stop done");

  delay(3000);

  // encoders config
  bodyEncoderFrontLeftDirection = 1;
  attachInterrupt(bodyEncoderFrontLeftPin, bodyEncoderFrontLeftCounter, bodyEncoderFrontLeftSignal);

  bodyEncoderFrontRightDirection = 1;
  attachInterrupt(bodyEncoderFrontRightPin, bodyEncoderFrontRightCounter, bodyEncoderFrontRightSignal);

  bodyEncoderRearLeftDirection = 1;
  attachInterrupt(bodyEncoderRearLeftPin, bodyEncoderRearLeftCounter, bodyEncoderRearLeftSignal);

  bodyEncoderRearRightDirection = 1;
  attachInterrupt(bodyEncoderRearRightPin, bodyEncoderRearRightCounter, bodyEncoderRearRightSignal);
  
  Serial.println("encoders config done");

}

//
// loop function
// 

void loop()
{

  //Serial.println("Foreward");
  
  //bodyMotorsControl(35000, 0, 0, 0); // FL
  //bodyMotorsControl(0, 35000, 0, 0); // FR
  //bodyMotorsControl(0, 0, 35000, 0); // RL
  //bodyMotorsControl(0, 0, 0, 35000); // RR

  bodyMotorsControl(35000, 35000, 35000, 35000); // ALL F
  //bodyMotorsControl(-35000, -35000, -35000, -35000); // ALL B

  // activity led
  if(millis() > ledTimer) {
    ledTimer = millis() + LED_TIME;
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);

    Serial.print(bodyEncoderFrontLeftTotalPulses);
    Serial.print("\t");
    Serial.print(bodyEncoderFrontRightTotalPulses);
    Serial.print("\t");
    Serial.print(bodyEncoderRearLeftTotalPulses);
    Serial.print("\t");
    Serial.println(bodyEncoderRearRightTotalPulses);
  }

}