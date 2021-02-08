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

    private:
    struct cfgData_t{ 
        String ssid = "myssid";
        String password = "mypassword";
        int test = 1;
    } data;
        
    int address = 0;
};

#endif  // CONFIGDATA_H