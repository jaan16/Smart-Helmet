// motor_dust_control.ino
#include "motor_control.hpp"
#include "dust_sensor.hpp"

void setup() {
    Serial.begin(9600); // Initialize serial communication

    // Initialize modules
    initializePins(); // Motor control pins
    initializeDustSensor(); // Dust sensor pins

    // Perform initial actions
    performValveCleaning();
}

void loop() {
    // Read dust density
    float dustDensity = readDustDensity();
    Serial.print("Air Quality: ");
    Serial.print(dustDensity);
    Serial.println(" ug/m3");

    // Perform motor actions based on air quality
    if (dustDensity > 100) { // Example threshold
        Serial.println("High dust detected! Spinning motors to circulate air.");
        spinMotors();
    } else {
        Serial.println("Air quality is good. Stopping motors.");
        stopMotors();
    }

    delay(1000); // Wait before next iteration
}
