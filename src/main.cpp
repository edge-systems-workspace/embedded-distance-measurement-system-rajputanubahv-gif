/**
 * @file main.cpp
 * @brief Ultrasonic distance measurement example for Arduino (HC-SR04)
 * @author Rajput Anubahv
 * @date 2026-03-17
 *
 * This sketch triggers an HC-SR04 ultrasonic sensor and measures the
 * round-trip time of the echo pulse, converting it to a distance in
 * centimeters. The measured distance is printed to Serial.
 */

#include <Arduino.h>

/** @brief Trigger pin for HC-SR04 ultrasonic sensor. */
#define trigPin 9

/** @brief Echo pin for HC-SR04 ultrasonic sensor. */
#define echoPin 10

/**
 * @brief Arduino setup function.
 *
 * Initializes the serial console and configures the trigger and echo pins.
 */
void setup()
{
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

/**
 * @brief Main loop: trigger the sensor, read echo, and print distance.
 *
 * @details Sends a 10 microsecond pulse on the trigger pin, measures the
 * duration of the echo pulse using pulseIn(), converts that duration to
 * a distance in centimeters using the speed of sound, and prints the
 * numeric distance value to the serial console.
 */
void loop()
{
    // Ensure trigger pin is low for a short time
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Send a 10µs HIGH pulse to trigger the measurement
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the duration (microseconds) of the echo pulse
    long duration = pulseIn(echoPin, HIGH);

    // Convert duration to distance in centimeters:
    // speed of sound = 343 m/s => 0.0343 cm/µs; divide by 2 for round trip
    long distance = duration * 0.0343 / 2;

    // Print a friendly, machine- and human-readable output
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Short delay between measurements
    delay(100);
}
