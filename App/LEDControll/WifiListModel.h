#ifndef WIFILISTMODEL_H
#define WIFILISTMODEL_H

#include <QAbstractListModel>

class WifiListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    WifiListModel(QObject *parent = Q_NULLPTR);

    void addWifi(const QString &ssid);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

   QList< QString> wifis() const;

private:
   QList< QString >_wifis;
};

#endif // WIFILISTMODEL_H
