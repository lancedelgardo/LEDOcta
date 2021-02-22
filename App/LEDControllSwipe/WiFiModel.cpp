#include "WiFiModel.h"

#include "WiFiData.h"

WiFiModel::WiFiModel(QObject *parent) : QAbstractListModel(parent), _wifiData(nullptr)
{

}

int WiFiModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !_wifiData) return 0;

    return _wifiData->wifiItems().size();
}

QVariant WiFiModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !_wifiData) return QVariant();

    WiFiItem *item = _wifiData->wifiItems().at(index.row());
    switch (role)
    {
        case SSIDRole:
            return QVariant(item->ssid());
        case PasswordRole:
            return QVariant(item->password());
    }

    return QVariant();
}

Qt::ItemFlags WiFiModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) return Qt::NoItemFlags;

    return Qt::NoItemFlags;
}

QHash<int, QByteArray> WiFiModel::roleNames() const
{
    QHash< int, QByteArray > names;
    names[SSIDRole] = "ssid";
    names[PasswordRole] = "password";
    return names;
}

WiFiData *WiFiModel::wifiList() const
{
    return _wifiData;
}

void WiFiModel::setWifiList(WiFiData *wifiList)
{
    beginResetModel();

    if (_wifiData) _wifiData->disconnect(this);

    _wifiData = wifiList;

    if (_wifiData)
    {
        connect(_wifiData, &WiFiData::preItemAppended, this, [=]() {
            const int index = 0; /*_newsData->NewsItems().size();*/
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(_wifiData, &WiFiData::postItemAppended, this, [=]() { endInsertRows(); });
    }

    endResetModel();

    _wifiData = wifiList;
}
