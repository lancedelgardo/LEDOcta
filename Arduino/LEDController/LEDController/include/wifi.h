#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>

// Load Wi-Fi library
#include <ESP8266WiFi.h>



class Wifi
{
    public:
        Wifi();
        void connect();
        bool isConnected();
        bool openedOwnAP();
        String currentWifiName();

    private:
        // Replace with your network credentials
        const char* ssid = "Hydra";
        const char* password = "L!uTwid%Ss58i!BA# ";

        // Set web server port number to 80
        WiFiServer *server;

        // Variable to store the HTTP request
        String header;

        bool hasConnectedToGivenSSID = false;
};

#endif  // WIFI_H