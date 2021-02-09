#ifndef CONTROLLLED_H
#define CONTROLLLED_H

#include "APIBase.h"

class ControllLed : public APIBase
{
  public:
    ControllLed();
    void ledOn();
    void ledOff();
    void sendWifiData(const QString &ssid, const QString &password);

    void writeProm();
    void readProm();
    void flushProm();
};

#endif  // CONTROLLLED_H
