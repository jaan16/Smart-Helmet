// motor_control.hpp
#ifndef MOTOR_CONTROL_HPP
#define MOTOR_CONTROL_HPP

#include <Arduino.h>

// Constants for motors
const int MOTOR_A = 1;
const int MOTOR_B = 2;

// Motor control pins
const int enA = 9;
const int in1 = 8;
const int in2 = 7;
const int enB = 3;
const int in3 = 5;
const int in4 = 4;

// Function Prototypes
void initializePins();
void stopMotors();
void setMotorSpeed(int motor, int speed);
void setMotorDirection(int motor, bool direction1, bool direction2);
void performValveCleaning();
void spinMotors();

#endif // MOTOR_CONTROL_HPP
