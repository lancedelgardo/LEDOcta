#include "WiFiData.h"

#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QDebug>
#include <QNetworkSession>
#include <QHostInfo>

WiFiData::WiFiData(QObject *parent) : QObject(parent)
{
    //QHostInfo::lookupHost("ESP-63AB22",this, SLOT(onLookupHost(QHostInfo)));



    /*
    QNetworkConfigurationManager ncm;
    QNetworkConfiguration cfg;

    int count = QNetworkConfiguration::Active;

    qDebug() << "Amount available connect in Wi-Fi :" << count;

    QList< QNetworkConfiguration > ssids = ncm.allConfigurations();

    foreach (auto ssid, ssids)
    {
        if(ssid.name().isEmpty()) continue;
        if(ssid.bearerType() != QNetworkConfiguration::BearerWLAN) continue;

        qDebug() << "=====";
        qDebug() << "Name: " + ssid.name();
        qDebug() << "BearerType: " + QString::number(ssid.bearerType());
        qDebug() << "BearerTypeFamily: " + QString::number(ssid.bearerTypeFamily());
        qDebug() << "BearerTypeName: " + ssid.bearerTypeName();
        qDebug() << "State: " + QString::number(ssid.state());
        qDebug() << "Type: " + QString::number(ssid.type());
        qDebug() << "=====";
        if(ssid.name().isEmpty()) continue;
        emit preItemAppended();

        WiFiItem *item = new WiFiItem(this);
        item->setSsid(ssid.name());
        _wifiItems.append(item);
        emit postItemAppended();
    }
    qDebug() << _wifiItems.size();
    */
}

QList<WiFiItem *> WiFiData::wifiItems() const
{
    return _wifiItems;
}

void WiFiData::setWifiItems(const QList<WiFiItem *> &wifiItems)
{
    _wifiItems = wifiItems;
}

void WiFiData::appendItem(WiFiItem *item)
{
    emit preItemAppended();
    _wifiItems.append(item);
    emit postItemAppended();
}

void WiFiData::refreshItems()
{

}

void WiFiData::onLookupHost(QHostInfo host)
{
    if (host.error() != QHostInfo::NoError) {
        qDebug() << "Lookup failed:" << host.errorString();
        return;
    }

    const auto addresses = host.addresses();
    for (const QHostAddress &address : addresses)
        qDebug() << "Found address:" << address.toString();

}
