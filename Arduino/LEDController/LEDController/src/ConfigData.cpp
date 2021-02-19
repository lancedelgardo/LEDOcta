#include "ConfigData.h"

#include <EEPROM.h>

ConfigData::ConfigData(){}

void ConfigData::init()
{
    EEPROM.begin(512);
}

String ConfigData::getSSID()
{
    return _ssid;
}

void ConfigData::setSSID(const String &ssid)
{
    _ssid = ssid;
    Serial.print("SSID Set To: ");
    Serial.println(_ssid);
}

String ConfigData::getPassword()
{
    return _password;
}

void ConfigData::setPassword(const String &pw)
{
    _password = pw;
    Serial.print("Password Set To: ");
    Serial.println(_password);
}

void ConfigData::saveConfig()
{
    flushEEProm();
    uint addrOffset = 0;
    byte ssidlen = _ssid.length();
    EEPROM.write(addrOffset++, ssidlen);
    for (int i = 0; i < ssidlen; i++)
    {
        EEPROM.write(addrOffset + i, _ssid[i]);
    }

    addrOffset += ssidlen +1;
    byte pwlen = _password.length();
    EEPROM.write(addrOffset++, pwlen);
    for(int i = 0; i < pwlen; i++){
        EEPROM.write(addrOffset + i, _password[i]);
    }
    EEPROM.commit();
}

void ConfigData::loadConfig()
{
    uint addrOffset = 0;
    int ssidlen = EEPROM.read(addrOffset++);
    char ssiddata[ssidlen + 1];
    for (int i = 0; i < ssidlen; i++)
    {
        ssiddata[i] = EEPROM.read(addrOffset + i);
    }
    ssiddata[ssidlen] = '\0'; // the character may appear in a weird way, you should read: 'only one backslash and 0'
    
    _ssid = String(ssiddata);

    addrOffset += ssidlen + 1;
    int pwlen = EEPROM.read(addrOffset++);
    char pwdata[pwlen + 1];
    for (int i = 0; i < pwlen; i++){
        pwdata[i] = EEPROM.read(addrOffset + i);
    }
    pwdata[pwlen] = '\0';

    _password = String(pwdata);
}

void ConfigData::flushEEProm()
{
    Serial.println("Flush EEPROM");
    for(int i = 0; i < EEPROM.length(); i++)
    {
        EEPROM.write(i,0);
    }
    Serial.println("Flush Finish");
}
