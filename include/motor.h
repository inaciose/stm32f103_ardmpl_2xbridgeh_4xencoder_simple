
#ifndef BRIDGEH_MOTOR_H
#define BRIDGEH_MOTOR_H

// right motors pins
#define BIN1 PA2
#define BIN2 PA3
#define BIN3 PA0
#define BIN4 PA1
#define BENA PB0
#define BENB PB1

// left motors pins
#define AIN1 PB9
#define AIN2 PB5
#define AIN3 PA11
#define AIN4 PA12
#define AENA PB8 // PB5
#define AENB PA8 // PB4

/*
// Front LeftMotor
#define frontLeftMotorEn AENA
#define frontLeftMotorForward AIN2
#define frontLeftMotorBackward AIN1

// Front RightMotor
#define frontRightMotorEn BENA
#define frontRightMotorForward BIN1
#define frontRightMotorBackward BIN2

// Rear LeftMotor
#define rearLeftMotorEn AENB
#define rearLeftMotorForward AIN4
#define rearLeftMotorBackward AIN3

// Rear RightMotor
#define rearRightMotorEn BENB
#define rearRightMotorForward BIN4
#define rearRightMotorBackward BIN3
*/

// Front LeftMotor
#define frontLeftMotorEn BENA
#define frontLeftMotorForward BIN1
#define frontLeftMotorBackward BIN2

// Front RightMotor
#define frontRightMotorEn AENA
#define frontRightMotorForward AIN1
#define frontRightMotorBackward AIN2

// Rear LeftMotor
#define rearLeftMotorEn BENB
#define rearLeftMotorForward BIN4
#define rearLeftMotorBackward BIN3

// Rear RightMotor
#define rearRightMotorEn AENB
#define rearRightMotorForward AIN3
#define rearRightMotorBackward AIN4


void bodyMotorsControl( int frontLeftMotorPwmOut, int frontRightMotorPwmOut, int rearLeftMotorPwmOut, int rearRightMotorPwmOut);

void setBodyMotorFrontLeftForward(void);

void setBodyMotorFrontLeftBackward(void);

void setBodyMotorFrontRightForward(void);

void setBodyMotorFrontRightBackward(void);

void setBodyMotorFrontLeftStop(void);

void setBodyMotorFrontRightStop(void);

void setBodyMotorFrontLeftBrake(void);

void setBodyMotorFrontRightBrake(void);


void setBodyMotorRearLeftForward(void);

void setBodyMotorRearLeftBackward(void);

void setBodyMotorRearRightForward(void);

void setBodyMotorRearRightBackward(void);

void setBodyMotorRearLeftStop(void);

void setBodyMotorRearRightStop(void);

void setBodyMotorRearLeftBrake(void);

void setBodyMotorRearRightBrake(void);

#endif