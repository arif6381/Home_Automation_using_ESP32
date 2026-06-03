/*
 * Rlay.cpp
 *
 *  Created on: 27 Apr 2026
 *      Author: user1
 */


#include "Header.h"

// Relay setup function to initialize relay pins
void relaySetup() {
   pinMode(relay_pin1,OUTPUT);  // Set relay_pin1 as an output (e.g., for light)
   pinMode(relay_pin2,OUTPUT);  // Set relay_pin2 as an output (e.g., for fan) // @suppress("Function cannot be resolved")

  // Set initial state of relays (assuming HIGH means OFF)

   digitalWrite(relay_pin1,0);  // Turn off relay_pin1 initially

   digitalWrite(relay_pin2,0); // Turn off relay_pin2 initially
}

// Function to set the relay state
void setRelay() {
                                        	// Check if relay_pin1 is targeted
	if (relay_pin1 != 0)
        {
                                        	// Invert value if LOW = OFF and HIGH = ON
	        digitalWrite(relay_pin1,0);
         }
   else
        {
            digitalWrite(relay_pin1,1);
       }
	// Set relay_pin1 to the specified value



    if (relay_pin2 != 0)                  //check if relay_pin2 is targeted
        {

	        digitalWrite(relay_pin2,0);
         }
    else
        {
            digitalWrite(relay_pin2,1);
        }


	// Set relay_pin2 to the specified value

}


