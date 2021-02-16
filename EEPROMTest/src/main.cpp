#include <Arduino.h>

#include <EEPROM.h>


struct cfgData_t{ 
    String ssid = "";
    String password = "";
} data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void flush()
{
    Serial.println("Flush EEPROM");
    EEPROM.begin();
    for(int i = 0; i < EEPROM.length(); i++)
    {
        EEPROM.write(i,0);
    }
    EEPROM.end();
    Serial.println("Flush Finish");
}

void read()
{
    EEPROM.begin();
    String s;
    String s2;
    Serial.println("Test Read");
    
   // EEPROM.get(0, s);
    //EEPROM.get(1, s2);
    
    EEPROM.get(0, data);

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

void write()
{
    EEPROM.begin();
    Serial.println("Test Write");
    String s = "Bla";
    String s2 = "Blub";
    
    //EEPROM.put(0,s);
    //EEPROM.put(0,s2);

    data.password = "Mein Passwort";
    data.ssid = "MeineSSID %+$;ci fj";
    EEPROM.put(0, data);

    /*
    for(int i = 0; i < 512; i++)
    {
        EEPROM.put(i,s);
    }
    */

    EEPROM.end();
    Serial.println("Write Finish");
}

void loop() {
  // put your main code here, to run repeatedly:
  flush();
  read();
  //write();

  delay(100000);
}