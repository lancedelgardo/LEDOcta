#include <Arduino.h>

//#include <EEPROM.h>
#include <EEPROM.h>


struct cfgData_t{ 
    String ssid = "";
    String password = "";
} data;

uint address = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  EEPROM.begin(512);
  Serial.println(EEPROM.length());

  String bla = "Bla";

}

void flush()
{
    Serial.println("Flush EEPROM"); 
    for(uint i = 0; i < EEPROM.length(); i++)
    {
        EEPROM.write(i,0);
    }
    EEPROM.commit();
    Serial.println("Flush Finish");
}

void read()
{
    //EEPROM.begin();
    String s;
    String s2;
    Serial.println("Test Read");
    
    //EEPROM.get(0, s);
    //EEPROM.get(1, s2);

    uint addrOffset = 0;
    int ssidlen = EEPROM.read(addrOffset++);
    char ssiddata[ssidlen + 1];
    for (int i = 0; i < ssidlen; i++)
    {
        ssiddata[i] = EEPROM.read(addrOffset + i);
    }
    ssiddata[ssidlen] = '\0'; // the character may appear in a weird way, you should read: 'only one backslash and 0'
    
    data.ssid = String(ssiddata);

    addrOffset += ssidlen + 1;
    int pwlen = EEPROM.read(addrOffset++);
    char pwdata[pwlen + 1];
    for (int i = 0; i < pwlen; i++){
        pwdata[i] = EEPROM.read(addrOffset + i);
    }
    pwdata[pwlen] = '\0';

    data.password = String(pwdata);

/*
    int pwLen = EEPROM.read(addrOffset + newStrLen +1);
    char n_PW[pwLen + 1];
    addrOffset += addrOffset + newStrLen + 2;
    for (int i = 0; i < pwLen; i++)
    {
        n_PW[i] = EEPROM.read(addrOffset + i);
    }
*/

    //data.password = String(n_PW);
   // data.ssid = String(n_data);

    //EEPROM.get(0, data);


    


    /*
    for(int i = 0; i < 512; i++)
    {
        EEPROM.get(i,s);
    }
    */

    //EEPROM.end();
    Serial.print("data.password: ");
    Serial.println(data.password);
    Serial.print("data.ssid: ");
    Serial.println(data.ssid);
    /*Serial.print("s: ");
    Serial.println(s);
    Serial.print("s2: ");
    Serial.println(s2);
    Serial.print("StringData: ");*/
    //Serial.println(String(n_data));
    //Serial.println("Read Finish");
}

void write()
{
    //EEPROM.begin();
    Serial.println("Test Write");
    String s = "Bla";
    String s2 = "Blub";
    
    //EEPROM.put(0,s);
    //EEPROM.put(0,s2);

    data.password = "Mein Passwort";
    data.ssid = "MeineSSID %+$;ci fj";
    //EEPROM.put(0, data);

    uint addrOffset = 0;
    byte ssidlen = data.ssid.length();
    EEPROM.write(addrOffset++, ssidlen);
    for (int i = 0; i < ssidlen; i++)
    {
        EEPROM.write(addrOffset + i, data.ssid[i]);
    }

    addrOffset += ssidlen +1;
    byte pwlen = data.password.length();
    EEPROM.write(addrOffset++, pwlen);
    for(int i = 0; i < pwlen; i++){
        EEPROM.write(addrOffset + i, data.password[i]);
    }



/*
    addrOffset += ssidlen + 1;
    byte pwlen = data.password.length();
    EEPROM.write(addrOffset++, pwlen);
    for(int i = 0; i < pwlen; i++){
        EEPROM.write(addrOffset + i, data.password[i]);
    }
    /*


    /*
    for(int i = 0; i < 512; i++)
    {
        EEPROM.put(i,s);
    }
    */
    EEPROM.commit();
   // EEPROM.end();
    Serial.println("Write Finish");
}

void loop() {
  // put your main code here, to run repeatedly:
  //flush();
  read();
  //write();
  //read();
  EEPROM.end();
  delay(100000);
}
