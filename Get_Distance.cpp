/*
 * Get_Distance.cpp
 *
 *  Created on: 27 Apr 2026
 *      Author: user1
 */

#include "Header.h"
#include <Arduino.h>

const int trigPin = 27;
const int echoPin = 26;
#define SOUND_SPEED 0.034

void ultraSonicSensorsetup() {
  //Set the mode of trigpin and echopin
	pinMode(trigPin,OUTPUT);
      	pinMode(echoPin,INPUT);

}

float getDistance() {
  //Calculate the Distance and return it

	digitalWrite(trigPin,LOW);
	delay(2);
	digitalWrite(trigPin,HIGH);
	delay(10);
	digitalWrite(trigPin,LOW);
	float time = pulseIn(echoPin,HIGH);
	float Distance = time * SOUND_SPEED/2;

	Serial.println("Distance"); // Print distance status to the Serial Monitor
	    Serial.println(Distance);


  return Distance;
}



