#include <Arduino.h>

#include "motor.h"


void bodyMotorsControl( int frontLeftMotorPwmOut, int frontRightMotorPwmOut, int rearLeftMotorPwmOut, int rearRightMotorPwmOut) {

  // brake control vars
  static bool leftBrake = false;
  static bool rightBrake = false;
  
  //
  // Front left & right
  //

  // set motor front left direction & speed
  if(frontLeftMotorPwmOut == 0) {

    if(leftBrake) {
      setBodyMotorFrontLeftBrake();
      //setBodyMotorFrontLeftStop();
      pwmWrite(frontLeftMotorEn,64000);
      //analogWrite(frontLeftMotorEn, 4095);            
    } else {
      //setBodyMotorFrontLeftBrake();
      setBodyMotorFrontLeftStop();
      pwmWrite(frontLeftMotorEn, 0);
      //analogWrite(frontLeftMotorEn, 0); 
    }
    
  } else if(frontLeftMotorPwmOut > 0) {
    setBodyMotorFrontLeftForward();
    pwmWrite(frontLeftMotorEn, frontLeftMotorPwmOut);
    //analogWrite(frontLeftMotorEn, frontLeftMotorPwmOut);            
  } else {
    setBodyMotorFrontLeftBackward();
    pwmWrite(frontLeftMotorEn, abs(frontLeftMotorPwmOut)); 
    //analogWrite(frontLeftMotorEn, abs(frontLeftMotorPwmOut));            
  }

  // set motor right direction & speed
  if(frontRightMotorPwmOut == 0) {

    if(rightBrake) {
      setBodyMotorFrontRightBrake();
      //setBodyMotorFrontRightStop();
      pwmWrite(frontRightMotorEn, 64000);
      //analogWrite(frontRightMotorEn, 4095);            
    } else {
      setBodyMotorFrontRightStop();
      //setBodyMotorFrontRightBrake();
      pwmWrite(frontRightMotorEn, 0);
      //analogWrite(frontRightMotorEn, 0);            
    }

  } else if(frontRightMotorPwmOut > 0) {
    setBodyMotorFrontRightForward();
    pwmWrite(frontRightMotorEn, frontRightMotorPwmOut);
    //analogWrite(frontRightMotorEn, frontRightMotorPwmOut);            
  } else {
    setBodyMotorFrontRightBackward();    
    pwmWrite(frontRightMotorEn, abs(frontRightMotorPwmOut));
    //analogWrite(frontRightMotorEn, abs(frontRightMotorPwmOut));            
  }

  //
  // REAR left & right
  //

  // set motor front left direction & speed
  if(rearLeftMotorPwmOut == 0) {

    if(leftBrake) {
      setBodyMotorRearLeftBrake();
      //setBodyMotorLeftStop();
      pwmWrite(rearLeftMotorEn,64000);
      //analogWrite(rearLeftMotorEn, 4095);            
    } else {
      //setBodyMotorLeftBrake();
      setBodyMotorRearLeftStop();
      pwmWrite(rearLeftMotorEn, 0);
      //analogWrite(rearLeftMotorEn, 0); 
    }
    
  } else if(rearLeftMotorPwmOut > 0) {
    setBodyMotorRearLeftForward();
    pwmWrite(rearLeftMotorEn, rearLeftMotorPwmOut);
    //analogWrite(rearLeftMotorEn, rearLeftMotorPwmOut);            
  } else {
    setBodyMotorRearLeftBackward();
    pwmWrite(rearLeftMotorEn, abs(rearLeftMotorPwmOut));    
    //analogWrite(rearLeftMotorEn, abs(rearLeftMotorPwmOut));            
  }

  // set motor right direction & speed
  if(rearRightMotorPwmOut == 0) {

    if(rightBrake) {
      setBodyMotorRearRightBrake();
      //setBodyMotorRearRightStop();
      pwmWrite(rearRightMotorEn, 64000);
      //analogWrite(rearRightMotorEn, 4095);            
    } else {
      setBodyMotorRearRightStop();
      //setBodyMotorRightBrake();
      pwmWrite(rearRightMotorEn, 0);
      //analogWrite(rearRightMotorEn, 0);            
    }

  } else if(rearRightMotorPwmOut > 0) {
    setBodyMotorRearRightForward();
    pwmWrite(rearRightMotorEn, rearRightMotorPwmOut);
    //analogWrite(rearRightMotorEn, rearRightMotorPwmOut);            
  } else {
    setBodyMotorRearRightBackward();    
    pwmWrite(rearRightMotorEn, abs(rearRightMotorPwmOut));
    //analogWrite(rearRightMotorEn, abs(rearRightMotorPwmOut));            
  }

  /*  
  Serial.print(frontLeftMotorPwmOut);
  Serial.print(" ");
  Serial.print(frontRightMotorPwmOut);
  Serial.print(" ");
  Serial.print(rearLeftMotorPwmOut);
  Serial.print(" ");
  Serial.println(rearRightMotorPwmOut);
  */
  
}

//
// Front left & right
//

void setBodyMotorFrontLeftForward() {
  digitalWrite(frontLeftMotorForward, HIGH);
  digitalWrite(frontLeftMotorBackward, LOW);
}

void setBodyMotorFrontLeftBackward() {
  digitalWrite(frontLeftMotorForward, LOW);
  digitalWrite(frontLeftMotorBackward, HIGH);
}

void setBodyMotorFrontRightForward() {
  digitalWrite(frontRightMotorForward, HIGH);
  digitalWrite(frontRightMotorBackward, LOW);
}

void setBodyMotorFrontRightBackward() {
  digitalWrite(frontRightMotorForward, LOW);
  digitalWrite(frontRightMotorBackward, HIGH);
}

void setBodyMotorFrontLeftStop() {
  digitalWrite(frontLeftMotorForward, LOW);
  digitalWrite(frontLeftMotorBackward, LOW);
}

void setBodyMotorFrontRightStop() {
  digitalWrite(frontRightMotorForward, LOW);
  digitalWrite(frontRightMotorBackward, LOW);
}

void setBodyMotorFrontLeftBrake() {
  digitalWrite(frontLeftMotorForward, HIGH);
  digitalWrite(frontLeftMotorBackward, HIGH);
}

void setBodyMotorFrontRightBrake() {
  digitalWrite(frontRightMotorForward, HIGH);
  digitalWrite(frontRightMotorBackward, HIGH);
}


//
// REAR left & right
//

void setBodyMotorRearLeftForward() {
  digitalWrite(rearLeftMotorForward, HIGH);
  digitalWrite(rearLeftMotorBackward, LOW);
}

void setBodyMotorRearLeftBackward() {
  digitalWrite(rearLeftMotorForward, LOW);
  digitalWrite(rearLeftMotorBackward, HIGH);
}

void setBodyMotorRearRightForward() {
  digitalWrite(rearRightMotorForward, HIGH);
  digitalWrite(rearRightMotorBackward, LOW);
}

void setBodyMotorRearRightBackward() {
  digitalWrite(rearRightMotorForward, LOW);
  digitalWrite(rearRightMotorBackward, HIGH);
}

void setBodyMotorRearLeftStop() {
  digitalWrite(rearLeftMotorForward, LOW);
  digitalWrite(rearLeftMotorBackward, LOW);
}

void setBodyMotorRearRightStop() {
  digitalWrite(rearRightMotorForward, LOW);
  digitalWrite(rearRightMotorBackward, LOW);
}

void setBodyMotorRearLeftBrake() {
  digitalWrite(rearLeftMotorForward, HIGH);
  digitalWrite(rearLeftMotorBackward, HIGH);
}

void setBodyMotorRearRightBrake() {
  digitalWrite(rearRightMotorForward, HIGH);
  digitalWrite(rearRightMotorBackward, HIGH);
}