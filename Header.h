#ifndef CUSTOMFUNCTION_H
#define CUSTOMFUNCTION_H

#include "DHT.h"
#include <WiFi.h>
#include<Arduino.h>

// Pin definitions
#define relay_pin1 22  // Relay pin 1
#define relay_pin2 23   // Relay pin 2



// DHT Sensor Functions
void DHTsetup();
float getTemperature();

// LDR Sensor Functions
void LDRsetup();
bool isItLight();

// Ultrasonic Sensor Functions
void ultraSonicSensorsetup();
float getDistance();

// Relay Functions
void relaySetup();
void setRelay(uint8_t relay_num, uint8_t val);

// Declare the server variable
void wifiSetup();

void handleAutoMode();
bool handleManualMode(WiFiClient,bool);

#endif  // CUSTOMFUNCTION_H
