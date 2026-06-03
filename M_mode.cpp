bool handleManualMode(WiFiClient client, bool isManualMode, bool lightState, bool fanState) {
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
                
                // Build status text with colors
                String lightStatus = lightState ? "<span style='color:#2d6a4f;font-weight:bold;'>ON</span>" : "<span style='color:#d62828;font-weight:bold;'>OFF</span>";
                String fanStatus = fanState ? "<span style='color:#2d6a4f;font-weight:bold;'>ON</span>" : "<span style='color:#d62828;font-weight:bold;'>OFF</span>";
                String modeStatus = isManualMode ? "<span style='color:#1d4e79;font-weight:bold;'>Manual</span>" : "<span style='color:#00b4d8;font-weight:bold;'>Auto</span>";
                
                client.print("<!DOCTYPE html><html><head>");
                client.print("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
                client.print("<title>Smart Home Control</title>");
                client.print("<style>");
                client.print("*{margin:0;padding:0;box-sizing:border-box;font-family:Arial,sans-serif;}");
                client.print("body{background:#f0f2f5;display:flex;justify-content:center;align-items:center;min-height:100vh;padding:20px;}");
                client.print(".container{background:#fff;border-radius:15px;box-shadow:0 4px 20px rgba(0,0,0,0.1);padding:30px;width:100%;max-width:500px;text-align:center;}");
                client.print("h1{color:#1d4e79;font-size:28px;margin-bottom:5px;}");
                client.print(".subtitle{color:#6c757d;font-size:14px;margin-bottom:25px;}");
                client.print(".grid{display:grid;grid-template-columns:1fr 1fr;gap:15px;margin-bottom:20px;}");
                client.print(".btn{display:block;padding:18px 20px;border-radius:6px;text-decoration:none;color:#fff;font-size:16px;font-weight:bold;transition:transform 0.1s;border:none;cursor:pointer;}");
                client.print(".btn:active{transform:scale(0.98);}");
                client.print(".on{background:#2d6a4f;}");
                client.print(".off{background:#d62828;}");
                client.print(".manual{background:#1d4e79;}");
                client.print(".auto{background:#00b4d8;}");
                client.print(".status{background:#f1f3f5;padding:12px;border-radius:6px;color:#6c757d;font-size:14px;margin-top:10px;}");
                client.print("</style>");
                client.print("</head><body>");
                
                client.print("<div class='container'>");
                client.print("<h1>Smart Home Control</h1>");
                client.print("<div class='subtitle'>ESP32 IoT Home Automation System</div>");
                
                client.print("<div class='grid'>");
                client.print("<a href='/?lightOn' class='btn on'>Light ON</a>");
                client.print("<a href='/?lightOff' class='btn off'>Light OFF</a>");
                client.print("<a href='/?fanOn' class='btn on'>Fan ON</a>");
                client.print("<a href='/?fanOff' class='btn off'>Fan OFF</a>");
                client.print("<a href='/?manualOn' class='btn manual'>Manual Mode</a>");
                client.print("<a href='/?manualOff' class='btn auto'>Auto Mode</a>");
                client.print("</div>");
                
                client.print("<div class='status'>Status: Light " + lightStatus + " | Fan " + fanStatus + " | Mode: " + modeStatus + "</div>");
                client.print("</div>");
                
                client.print("</body></html>");
                break;
            }
            if (c == '\n') {
                currentLineIsBlank = true;
                buffer = "";
            } else if (c == '\r') {
                if (buffer.indexOf("GET /?lightOff") >= 0) {
                    digitalWrite(relay_pin1, 1);
                    lightState = false;
                } else if (buffer.indexOf("GET /?lightOn") >= 0) {
                    digitalWrite(relay_pin1, 0);
                    lightState = true;
                }
                
                if (buffer.indexOf("GET /?fanOff") >= 0) {
                    digitalWrite(relay_pin2, 1);
                    fanState = false;
                } else if (buffer.indexOf("GET /?fanOn") >= 0) {
                    digitalWrite(relay_pin2, 0);
                    fanState = true;
                }
                
                if (buffer.indexOf("GET /?manualOn") >= 0)
                    isManualMode = true;
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