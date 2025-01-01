// dust_sensor.cpp
#include "dust_sensor.hpp"

// Variables for sensor readings
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

// Initializes the dust sensor pins
void initializeDustSensor() {
    pinMode(LED_POWER_PIN, OUTPUT);
}

// Reads the dust density from the sensor
float readDustDensity() {
    digitalWrite(LED_POWER_PIN, LOW); // Power on the LED
    delayMicroseconds(SAMPLING_TIME);

    // Read the sensor output
    voMeasured = analogRead(MEASURE_PIN);

    delayMicroseconds(DELTA_TIME);
    digitalWrite(LED_POWER_PIN, HIGH); // Turn off the LED
    delayMicroseconds(SLEEP_TIME);

    // Convert the analog reading to voltage
    calcVoltage = voMeasured * (5.0 / 1024.0);

    // Calculate the dust density using the sensor's linear equation
    dustDensity = 170 * calcVoltage - 0.1;

    return dustDensity;
}
