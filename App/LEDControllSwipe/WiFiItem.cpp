#include "WiFiItem.h"

WiFiItem::WiFiItem(QObject *parent) : QObject(parent)
{

}

QString WiFiItem::ssid() const
{
    return _ssid;
}

void WiFiItem::setSsid(const QString &ssid)
{
    _ssid = ssid;
}

QString WiFiItem::password() const
{
    return _password;
}

void WiFiItem::setPassword(const QString &password)
{
    _password = password;
}
