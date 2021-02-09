#include "ControllLed.h"

#include <QDebug>

ControllLed::ControllLed() {}

void ControllLed::ledOn() { get("/5/on"); }

void ControllLed::ledOff() { get("/5/off"); }

void ControllLed::sendWifiData(const QString &ssid, const QString &password)
{
    //    qDebug() << "Send Wifi Data...";
    //    get("/ssid=MySendedSSID");


    qDebug() << "Put Test";
    put("ssid=" + ssid + "pw=" + password + ";");
}

void ControllLed::writeProm() { get("/write"); }

void ControllLed::readProm() { get("/read"); }

void ControllLed::flushProm() { get("/flush"); }
