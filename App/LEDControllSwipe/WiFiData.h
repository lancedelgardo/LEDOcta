#ifndef WIFIDATA_H
#define WIFIDATA_H

#include "WiFiItem.h"

#include <QObject>
#include <QHostInfo>

class WiFiData : public QObject
{
    Q_OBJECT
public:
    explicit WiFiData(QObject *parent = nullptr);

    QList<WiFiItem *> wifiItems() const;
    void setWifiItems(const QList<WiFiItem *> &wifiItems);
    void appendItem(WiFiItem *item);

signals:
  void postItemAppended();
  void preItemAppended();

public slots:
  void refreshItems();
  void onLookupHost(QHostInfo host);

private:
    QList<WiFiItem*> _wifiItems;
};

#endif // WIFIDATA_H
