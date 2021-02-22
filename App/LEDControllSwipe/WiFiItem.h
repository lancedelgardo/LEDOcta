#ifndef WIFIITEM_H
#define WIFIITEM_H

#include <QObject>

class WiFiItem : public QObject
{
    Q_OBJECT
public:
    explicit WiFiItem(QObject *parent = nullptr);

    QString ssid() const;
    void setSsid(const QString &ssid);

    QString password() const;
    void setPassword(const QString &password);

signals:

public slots:

private:
    QString _ssid;
    QString _password;
};

#endif // WIFIITEM_H
