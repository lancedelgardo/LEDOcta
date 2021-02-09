#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>

// Load Wi-Fi library
#include <ESP8266WiFi.h>

#include "ConfigData.h"



class Wifi
{
    public:
        Wifi();
        void connect();
        bool isConnected();
        bool openedOwnAP();
        String currentWifiName();
        void checkClient();

    private:
        // Replace with your network credentials
        const char* ssid = "Hydra";
        const char* password = "L!uTwid%Ss58i!BA#";
        //const char* ssid = "RGT Demo";
        //const char* password = "0a0b0c0d0e";

        // Set web server port number to 80
        WiFiServer *server;

        // Variable to store the HTTP request
        String header;

        bool hasConnectedToGivenSSID = false;

        // Current time
        unsigned long currentTime = millis();
        // Previous time
        unsigned long previousTime = 0; 
        // Define timeout time in milliseconds (example: 2000ms = 2s)
        const long timeoutTime = 2000;

        ConfigData cfgData;
};

#endif  // WIFI_H