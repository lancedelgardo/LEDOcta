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

void ConfigData::setSSID(const String &ssid)
{
    data.ssid = ssid;
}

String ConfigData::getPassword()
{
    return data.password;
}

void ConfigData::setPassword(const String &pw)
{
    data.password = pw;
}

void ConfigData::saveConfig()
{
    flushEEProm();
    EEPROM.begin(512);
    EEPROM.put(0, data);
    EEPROM.commit();                      // Only needed for ESP8266 to get data written
    EEPROM.end();                         // Free RAM copy of structure
    
    Serial.println("Saved To EEPROM");
}

void ConfigData::loadConfig()
{
    EEPROM.begin(512);
    EEPROM.get(0, data);
    EEPROM.end();

    Serial.println("Fertig geladen");
    Serial.println(data.password);
    Serial.println(data.ssid);
}

void ConfigData::testChangeData()
{
    Serial.println(data.password);
    Serial.println(data.ssid);
    
    delay(1000);

    data.ssid = "neueSSID";
    data.password = "NeuesPasswort";

    Serial.println(data.password);
    Serial.println(data.ssid);

    delay(1000);

    Serial.println("Saveconfig...");
    saveConfig();
}

void ConfigData::flushEEProm()
{
    Serial.println("Flush EEPROM");
    EEPROM.begin(512);
    for(int i = 0; i < EEPROM.length(); i++)
    {
        EEPROM.write(i,0);
    }
    EEPROM.end();
    Serial.println("Flush Finish");
}

void ConfigData::testRead()
{
    EEPROM.begin(512);
    String s;
    String s2;
    Serial.println("Test Read");
    
   // EEPROM.get(0, s);
    //EEPROM.get(1, s2);
    
    EEPROM.get(256, data);

    /*
    for(int i = 0; i < 512; i++)
    {
        EEPROM.get(i,s);
    }
    */

    EEPROM.end();
    Serial.println(data.password);
    Serial.println(data.ssid);
    Serial.println(s);
    Serial.println(s2);
    Serial.println("Read Finish");
}

void ConfigData::testWrite()
{
    EEPROM.begin(512);
    Serial.println("Test Write");
    String s = "Bla";
    String s2 = "Blub";
    
    //EEPROM.put(0,s);
    //EEPROM.put(0,s2);

    data.password = "Mein Passwort";
    data.ssid = "MeineSSID %+$;ci fj";
    EEPROM.put(256, data);

    /*
    for(int i = 0; i < 512; i++)
    {
        EEPROM.put(i,s);
    }
    */

    EEPROM.end();
    Serial.println("Write Finish");
}