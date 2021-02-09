#ifndef CONFIGDATA_H
#define CONFIGDATA_H

#include <Arduino.h>

class ConfigData
{
    public:
        ConfigData();
        String getSSID();
        String getPassword();
        void saveConfig();
        void loadConfig();

        void testChangeData();

        void setSSID(const String &ssid);
        void setPassword(const String &pw);

        void flushEEProm();
        void testRead();
        void testWrite();

    private:
    struct cfgData_t{ 
        String ssid = "";
        String password = "";
    } data;
        
    int address = 0;
};

#endif  // CONFIGDATA_H