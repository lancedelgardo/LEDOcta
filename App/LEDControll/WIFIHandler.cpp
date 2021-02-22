#include "WIFIHandler.h"

#include <QNetworkConfigurationManager>
#include <QDebug>

WIFIHandler::WIFIHandler(QObject *parent) : QObject(parent) { _model = new WifiListModel(this); }

void WIFIHandler::setWifiOnArduino(const QString &ssid, const QString &password) { QString value = ssid + ""; }

void WIFIHandler::scanWifi()
{
    QNetworkConfigurationManager ncm;
    QNetworkConfiguration cfg;
    QNetworkConfiguration::StateFlags flags;

    int count = QNetworkConfiguration::Active;

    qDebug() << "Amount available connect in Wi-Fi :" << count;

    QList< QNetworkConfiguration > ssids = ncm.allConfigurations(flags = 0);

    foreach (auto ssid, ssids)
    {
        qDebug() << ssid.name();
        if(ssid.name().isEmpty()) continue;
        _model->addWifi(ssid.name());
    }
}

QList< QString > WIFIHandler::wifis() const { return _model->wifis(); }

WifiListModel *WIFIHandler::model() const { return _model; }
