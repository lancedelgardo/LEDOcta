#ifndef CONFIGDATA_H
#define CONFIGDATA_H

#include <Arduino.h>

class ConfigData
{
    public:
        ConfigData();
        void init();

        String getSSID();
        String getPassword();
        String getIpAddress();
        void setSSID(const String &ssid);
        void setPassword(const String &pw);
        void setIpAddress(const String &ip);

        void saveConfig();
        void loadConfig();

    private:
        void flushEEProm();

        String _ssid = "UPC9438918_EXT";
        String _password = "fhhsyar6hppQ";
        String _ipAddress;
};

#endif  // CONFIGDATA_H