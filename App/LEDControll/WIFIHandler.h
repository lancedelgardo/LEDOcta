#ifndef WIFIHANDLER_H
#define WIFIHANDLER_H

#include "WifiListModel.h"

#include <QObject>


class WIFIHandler : public QObject
{
    Q_OBJECT
public:
    explicit WIFIHandler(QObject *parent = nullptr);

    void setWifiOnArduino(const QString &ssid, const QString &password);

    void scanWifi();

    QList<QString> wifis() const;

    WifiListModel *model() const;

signals:

public slots:

private:
    WifiListModel *_model;

};

#endif // WIFIHANDLER_H
