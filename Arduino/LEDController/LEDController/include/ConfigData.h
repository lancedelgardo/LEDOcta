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
        void setSSID(const String &ssid);
        void setPassword(const String &pw);

        void saveConfig();
        void loadConfig();

    private:
        void flushEEProm();

        String _ssid;
        String _password;
};

#endif  // CONFIGDATA_H