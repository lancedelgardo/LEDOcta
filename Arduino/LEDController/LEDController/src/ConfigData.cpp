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

String ConfigData::getIpAddress()
{
    return _ipAddress;
}

void ConfigData::setPassword(const String &pw)
{
    _password = pw;
}

void ConfigData::setIpAddress(const String &ip)
{
    _ipAddress = ip;
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

    addrOffset += pwlen +1;
    byte iplen = _ipAddress.length();
    EEPROM.write(addrOffset++, iplen);
    for(int i = 0; i < iplen; i++){
        EEPROM.write(addrOffset + i, _ipAddress[i]);
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

    addrOffset += pwlen + 1;
    int iplen = EEPROM.read(addrOffset++);
    char ipdata[iplen + 1];
    for (int i = 0; i < iplen; i++){
        ipdata[i] = EEPROM.read(addrOffset + i);
    }
    ipdata[iplen] = '\0';
    _ipAddress = String(ipdata);
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
