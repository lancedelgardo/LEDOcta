#ifndef WIFIMODEL_H
#define WIFIMODEL_H

#include <QAbstractListModel>

class WiFiData;

class WiFiModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(WiFiData *list READ wifiList WRITE setWifiList)

public:
    WiFiModel(QObject *parent = Q_NULLPTR);

    enum
    {
        SSIDRole,
        PasswordRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    //    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    virtual QHash< int, QByteArray > roleNames() const override;

    WiFiData *wifiList() const;
    void setWifiList(WiFiData *wifiList);

  private:
    WiFiData *_wifiData;
};

#endif // WIFIMODEL_H
