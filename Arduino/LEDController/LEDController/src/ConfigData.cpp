#include "ConfigData.h"

#include <EEPROM.h>

ConfigData::ConfigData()
{
    Serial.println(data.password);
    Serial.println(data.ssid);
}

String ConfigData::getSSID()
{
    return data.ssid;
}

String ConfigData::getPassword()
{
    return data.password;
}

void ConfigData::saveConfig()
{
    EEPROM.begin(512);
    EEPROM.put( address, data );
    delay(200);
    EEPROM.commit();                      // Only needed for ESP8266 to get data written
    EEPROM.end();                         // Free RAM copy of structure
}

void ConfigData::loadConfig()
{
    EEPROM.begin(512);
    EEPROM.get( address, data );
    EEPROM.end();

    Serial.println("Fertig geladen");
    delay(2000);
    Serial.println(data.password);
    Serial.println(data.ssid);
}

void ConfigData::testChangeData()
{
    Serial.println(data.password);
    Serial.println(data.ssid);
    
    delay(1000);

    data.test = 1;
    data.ssid = "neueSSID";
    data.password = "NeuesPasswort";

    Serial.println(data.password);
    Serial.println(data.ssid);

    delay(1000);

    Serial.println("Saveconfig...");
    saveConfig();
}