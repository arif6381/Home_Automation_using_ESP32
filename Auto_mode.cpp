/*
 * Auto_mode.cpp
 *
 *  Created on: 27 Apr 2026
 *      Author: user1
 */


#include "Header.h"

// Auto mode control function
void handleAutoMode() {
                     float Distance =  getDistance(); 		 // get the distance to check presence of Human
                     float Temperature =  getTemperature();	 //get temperature
                     int Light =  isItLight(); 			 //get the lighting condition of the room

  //Check the required conditions to turn ON or OFF the FAN and LIGHT

		     if (Distance <=  10 )
		     {
		    	if( Light == 1)               // light 1 == dark
		    	{
				digitalWrite(relay_pin1,0);
		    	}
		     }
		    else

		    {

				digitalWrite(relay_pin1,1);
		    }


		     if( Distance <= 10)
		     {
		    	 if( Temperature >= 28)
		    	 {
				digitalWrite(relay_pin2,0);
		    	 }
		     }

		    else
		     {
				digitalWrite(relay_pin2,1);
		     }



}


