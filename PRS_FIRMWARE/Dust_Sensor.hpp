// dust_sensor.hpp
#ifndef DUST_SENSOR_HPP
#define DUST_SENSOR_HPP

#include <Arduino.h>

// Pin Definitions
const int MEASURE_PIN = A0; // Analog pin connected to the sensor's output
const int LED_POWER_PIN = 4; // Digital pin to control the sensor's LED

// Timing Constants
const int SAMPLING_TIME = 280;
const int DELTA_TIME = 40;
const int SLEEP_TIME = 9680;

// Function Prototypes
void initializeDustSensor();
float readDustDensity();

#endif // DUST_SENSOR_HPP

