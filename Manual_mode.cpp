/*
 * Manual_mode.cpp
 *
 *  Created on: 27 Apr 2026
 *      Author: user1
 */

#include "Header.h"



bool handleManualMode(WiFiClient client,bool isManualMode){
	boolean currentLineIsBlank = true;
	String buffer = "";
	while (client.connected()) {
		if (client.available()) {
			char c = client.read();
			buffer += c;
			if (c == '\n' && currentLineIsBlank) {
				// Send HTML response
				client.println("HTTP/1.1 200 OK");
				client.println("Content-Type: text/html");
				client.println();
				client.print("<HTML><title>ESP32</title>");
				client.print("<body><h1>ESP32 Relay Control</h1>");
				client.print("<p>Light Control</p>");
				client.print("<a href=\"/?lightOn\"><button>ON</button></a>");
				client.print("<a href=\"/?lightOff\"><button>OFF</button></a>");
				client.print("<p>Fan Control</p>");
				client.print("<a href=\"/?fanOn\"><button>ON</button></a>");
				client.print("<a href=\"/?fanOff\"><button>OFF</button></a>");
				client.print("<p>Manual Control</p>");
				client.print("<a href=\"/?manualOn\"><button>ON</button></a>");
				client.print("<a href=\"/?manualOff\"><button>OFF</button></a>");
				client.print("</body></HTML>");
				break;
			}
			if (c == '\n') {
				currentLineIsBlank = true;
				buffer = "";
			} else if (c == '\r') {
				// Check HTTP requests and update relays or manual mode
			 if (buffer.indexOf("GET /?lightOff") >= 0)
					digitalWrite(relay_pin1, 1);

				// Check the remaining requests for the ON or OFF modes
			 else if (buffer.indexOf("GET /?lightOn") >= 0)
					digitalWrite(relay_pin1, 0);

			if (buffer.indexOf("GET /?fanOff") >= 0)
					digitalWrite(relay_pin2,1);

			else if (buffer.indexOf("GET /?fanOn") >= 0)
					digitalWrite(relay_pin2, 0);







			 if (buffer.indexOf("GET /?manualOn") >= 0)
					isManualMode = true;
				// Check the request for manual mode Off

				if (buffer.indexOf("GET /?manualOff") >= 0)
					isManualMode = false;


			} else {
				currentLineIsBlank = false;
			}
		}
	}
	client.stop();
	return isManualMode;
}



