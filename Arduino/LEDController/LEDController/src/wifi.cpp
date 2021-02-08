#include "wifi.h"



Wifi::Wifi()
{
    server = new WiFiServer(80);
}

void Wifi::connect()
{
    // Connect to Wi-Fi network with SSID and password
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    int count = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        count++;
        if(count == 10) break;
    }

    if(count < 10)
    {
         // Print local IP address and start web server
        Serial.println("");
        Serial.println("WiFi connected.");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
        server->begin();
        hasConnectedToGivenSSID = true;
    }
    else
    {
        Serial.print("Setting soft-AP ... ");
        boolean result = WiFi.softAP("ESPsoftAP_01", "pass-to-soft-AP");
        if(result == true)
        {
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