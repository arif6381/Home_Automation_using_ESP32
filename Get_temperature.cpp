/*
 * Get_temperature.cpp
 *
 *  Created on: 27 Apr 2026
 *      Author: user1
 */

#include "Header.h"

#include <DHT.h>  // Include the DHT library

// Define DHT sensor parameters
#define DHTPIN 2         // Pin where the DHT sensor is connected
#define DHTTYPE DHT11    // Define the type of DHT sensor (e.g., DHT11)

// Create a DHT object with specified pin and type
    DHT dht(DHTPIN,DHTTYPE);
// Setup function for DHT sensor initialization
void DHTsetup() {
  // Initialize the DHT sensor
  dht.begin();
}

// Function to get the temperature reading from the DHT sensor
float getTemperature() {
  // Wait for sensor to stabilize before reading
   delay(100);


  // Read temperature in Celsius
  float temperature = dht.readTemperature();


  // Check if the readings are valid (not nan)
  // Return 0 if reading fails
  if (isnan (temperature))
  {
      Serial.println("failed to read from DHT sensor");
      return 0;
    }

  // Print temperature to the Serial Monitor
    Serial.print("Temperature is : ");
    Serial.print(temperature);
    Serial.println(" C");
  return  temperature;  // Return the temperature reading
}



