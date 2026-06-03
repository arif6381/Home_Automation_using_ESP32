/*
 * GET_light.cpp
 *
 *  Created on: 27 Apr 2026
 *      Author: user1
 */

#include "Header.h"


// Define the pin connected to the LDR sensor
#define LDR_PIN 16

// Setup function to initialize the LDR pin
void LDRsetup() {
  pinMode(LDR_PIN,INPUT); //  Set the LDR pin as an input
}

// Function to check if it is light or dark based on LDR reading
bool isItLight() {
   int ldrValue =  digitalRead (LDR_PIN); // Read the digital state of the LDR pin

    Serial.println("light status"); // Print light status to the Serial Monitor
    Serial.println(ldrValue);
    if (ldrValue != 0)
     {
     // Return true if it is light, false if it is dark
    return true ;
     }
    else
    {
    return false ;
    }
}



