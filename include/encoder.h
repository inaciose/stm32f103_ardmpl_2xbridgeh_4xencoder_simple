#ifndef ENCODER_MOTOR_H
#define ENCODER_MOTOR_H

#define bodyEncoderSignal FALLING
#define bodyEncoderInputSignal INPUT_PULLUP

// encoder FrontLeftMotor
#define bodyEncoderFrontLeftFunction bodyEncoderFrontLeftCounter
#define bodyEncoderFrontLeftPin PB12 // A pin the interrupt pin
#define bodyEncoderFrontLeftSignal bodyEncoderSignal
#define bodyEncoderFrontLeftInputSignal bodyEncoderInputSignal

// encoder FrontRightMotor
#define bodyEncoderFrontRightFunction bodyEncoderFrontRightCounter
#define bodyEncoderFrontRightPin PB14 // A pin: the interrupt pin
#define bodyEncoderFrontRightSignal bodyEncoderSignal
#define bodyEncoderFrontRightInputSignal bodyEncoderInputSignal

// encoder RearLeftMotor
#define bodyEncoderRearLeftFunction bodyEncoderRearLeftCounter
#define bodyEncoderRearLeftPin PB13 // A pin the interrupt pin
#define bodyEncoderRearLeftSignal bodyEncoderSignal
#define bodyEncoderRearLeftInputSignal bodyEncoderInputSignal

// encoder RearRightMotor
//#define bodyEncoderRearRightInt 1
#define bodyEncoderRearRightFunction bodyEncoderRearRightCounter
#define bodyEncoderRearRightPin PB15 // A pin: the interrupt pin
#define bodyEncoderRearRightSignal bodyEncoderSignal
#define bodyEncoderRearRightInputSignal bodyEncoderInputSignal

#endif