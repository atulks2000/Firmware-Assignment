#include <elapsedMillis.h>  // Header file for elapsedMillis for led blinking

const int lm35Pin = A0;  // Analog pin for LM35 temperature sensor
const int ledPin = 13;   // Onboard LED pin of Arduino UNO

elapsedMillis blinkTimer;  // Create an elapsedMillis object

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as an output
  Serial.begin(9600);      // Initializing serial communication for debugging
}

void loop() {
  // Reading the temperature from the LM35 sensor
  int sensorValue = analogRead(lm35Pin);
  float temperature = (sensorValue * 0.48875);  // Converting the sensor value in degrees Celsius

  // Printing the temperature to the Serial Monitor (for debugging)
  Serial.print("Temperature: ");
  Serial.print(temperature); 
  Serial.println(" °C");

  // Checking the temperature and updating the LED blink interval
  if (temperature < 30.0) {
    if (blinkTimer >= 250) {
      toggleLED();
      blinkTimer = 0;
    }
  } else {
    if (blinkTimer >= 500) {
      toggleLED();
      blinkTimer = 0;
    }
  }
}

void toggleLED() {
  digitalWrite(ledPin, !digitalRead(ledPin));  // Toggling the LED state
}
