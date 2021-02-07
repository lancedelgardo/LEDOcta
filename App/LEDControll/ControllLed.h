#ifndef CONTROLLLED_H
#define CONTROLLLED_H

#include "APIBase.h"

class ControllLed : public APIBase
{
public:
    ControllLed();
    void ledOn();
    void ledOff();
};

#endif // CONTROLLLED_H
