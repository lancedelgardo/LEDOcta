#include "ControllLed.h"

ControllLed::ControllLed()
{

}

void ControllLed::ledOn()
{
    put("/5/on");
}

void ControllLed::ledOff()
{
     put("/5/off");
}
