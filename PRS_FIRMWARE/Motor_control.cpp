// motor_control.cpp
#include "motor_control.hpp"

// Initialize motor control pins as outputs
void initializePins() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.println("Pins initialized");
}

// Turn off all motors
void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("Motors stopped");
}

// Set the speed of a motor (0-255)
void setMotorSpeed(int motor, int speed) {
  if (motor == MOTOR_A) {
    analogWrite(enA, speed);
  } else if (motor == MOTOR_B) {
    analogWrite(enB, speed);
  }
  Serial.print("Speed set for Motor ");
  Serial.print(motor == MOTOR_A ? "A" : "B");
  Serial.print(": ");
  Serial.println(speed);
}

// Set the direction of a motor
void setMotorDirection(int motor, bool direction1, bool direction2) {
  if (motor == MOTOR_A) {
    digitalWrite(in1, direction1);
    digitalWrite(in2, direction2);
  } else if (motor == MOTOR_B) {
    digitalWrite(in3, direction1);
    digitalWrite(in4, direction2);
  }
  Serial.print("Direction set for Motor ");
  Serial.print(motor == MOTOR_A ? "A" : "B");
  Serial.print(": ");
  Serial.print(direction1 ? "HIGH" : "LOW");
  Serial.print(", ");
  Serial.println(direction2 ? "HIGH" : "LOW");
}

// Perform valve cleaning with both motors
void performValveCleaning() {
  setMotorSpeed(MOTOR_A, 120);
  setMotorDirection(MOTOR_A, HIGH, LOW);
  Serial.println("Motor A VALVE CLEANING");
  delay(5000);
  stopMotors();

  setMotorSpeed(MOTOR_B, 120);
  setMotorDirection(MOTOR_B, HIGH, LOW);
  Serial.println("Motor B VALVE CLEANING");
  delay(5000);
  stopMotors();
}

// Spin motors in specific directions
void spinMotors() {
  setMotorSpeed(MOTOR_A, 150);
  setMotorDirection(MOTOR_A, LOW, HIGH);
  Serial.println("Motor A spinning in Anti-clockwise direction");

  setMotorSpeed(MOTOR_B, 120);
  setMotorDirection(MOTOR_B, HIGH, LOW);
  Serial.println("Motor B spinning in clockwise direction");

  delay(1000);
  //stopMotors();
}
