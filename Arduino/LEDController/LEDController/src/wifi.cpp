#include "wifi.h"

Wifi::Wifi()
{
    server = new WiFiServer(80);
}

void Wifi::connect()
{
    // Connect to Wi-Fi network with SSID and password
    int maxTry = 50;
    Serial.println("Load Data from EEPROM");

    cfgData.init();
    //cfgData.loadConfig();

    Serial.println("Connecting to ");
    Serial.println(cfgData.getSSID());
    Serial.println(cfgData.getPassword());
    //WiFi.begin(cfgData.getSSID(), cfgData.getPassword());
    WiFi.begin(cfgData.getSSID(), cfgData.getPassword());
    int count = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        count++;
        if(count == maxTry) break;
    }

    if(count < maxTry)
    {
         // Print local IP address and start web server
        Serial.println("");
        Serial.println("WiFi connected.");
        Serial.print("IP: ");
        Serial.println(WiFi.localIP());
        Serial.println(WiFi.hostname());
        server->begin();
        hasConnectedToGivenSSID = true;
    }
    else
    {
        Serial.println("Setting soft-AP ... ");
        Serial.print("SSID: ");
        Serial.println("ESPsoftAP_01");
        Serial.print("Password: ");
        Serial.println("pass-to-soft-AP");
        boolean result = WiFi.softAP("ESPsoftAP_01", "pass-to-soft-AP");
        if(result == true)
        {
            Serial.print("IP: ");
            Serial.println(WiFi.softAPIP());
            Serial.println("Ready");
        }
        else
        {
            Serial.println("Failed!");
        }
    }
}

bool Wifi::isConnected()
{
    return WiFi.isConnected();
}

bool Wifi::openedOwnAP()
{
    return !hasConnectedToGivenSSID;
}

String Wifi::currentWifiName()
{
    if(hasConnectedToGivenSSID) return WiFi.SSID();
    else return WiFi.softAPSSID();
}

void Wifi::checkClient()
{
    WiFiClient client = server->available();   // Listen for incoming clients

    if (client) 
    {                             // If a new client connects,
        //Serial.println("New Client.");          // print a message out in the serial port
        String currentLine = "";                // make a String to hold incoming data from the client
        currentTime = millis();
        previousTime = currentTime;
        while (client.connected() && currentTime - previousTime <= timeoutTime) 
        { // loop while the client's connected
            currentTime = millis();         
            if (client.available()) 
            {             // if there's bytes to read from the client,
                char c = client.read();             // read a byte, then
                //Serial.write(c);                    // print it out the serial monitor
                header += c;
                if (c == '\n') 
                {                    // if the byte is a newline character
                    // if the current line is blank, you got two newline characters in a row.
                    // that's the end of the client HTTP request, so send a response:
                    if (currentLine.length() == 0) 
                    {
                        // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
                        // and a content-type so the client knows what's coming, then a blank line:
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println("Connection: close");
                        client.println();
                        client.write("OK");
            
                        // turns the GPIOs on and off
                        if (header.indexOf("GET /5/on") >= 0) 
                        {
                            Serial.println("GPIO 5 on");
                            //output5State = "on";
                            //digitalWrite(LED_BUILTIN, LOW);
                        } 
                        else if (header.indexOf("GET /5/off") >= 0) 
                        {
                            Serial.println("GPIO 5 off");
                            //output5State = "off";
                            //digitalWrite(LED_BUILTIN, HIGH);
                        }
                        else if (header.indexOf("GET /read") >= 0) 
                        {
                            //cfgData.testRead();
                        }
                        else if (header.indexOf("GET /write") >= 0) 
                        {
                            //cfgData.testWrite();
                        }
                        else if (header.indexOf("GET /flush") >= 0) 
                        {
                            //cfgData.flushEEProm();
                        }
                        else if(header.indexOf("PUT /ssid=") >= 0)
                        {
                            int ssidIndex = header.indexOf("ssid=");
                            int pwIndex = header.indexOf("pw=");
                            int pwIndexEnd = header.indexOf(";");
                            String ssid;
                            String password;

                            for(int i = ssidIndex + 5; i < pwIndex; i++)
                            {
                                ssid += header[i];
                            }

                            for(int i = pwIndex + 3; i < pwIndexEnd; i++)
                            {
                                password += header[i];
                            }

                            cfgData.setSSID(ssid);
                            cfgData.setPassword(password);

                            cfgData.saveConfig();
                        }
                    }
                    else 
                    { // if you got a newline, then clear currentLine
                        currentLine = "";
                    }
                }
                else if (c != '\r')     
                {  // if you got anything else but a carriage return character,
                    currentLine += c;      // add it to the end of the currentLine
                }  
            }
        }
        header = "";
        // Close the connection
        client.stop();
        //Serial.println("Client disconnected.");
        //Serial.println("");
    }
}