#include "WifiListModel.h"

WifiListModel::WifiListModel(QObject *parent)
{

}

void WifiListModel::addWifi(const QString &ssid)
{
    beginResetModel();
    _wifis.append(ssid);
    endResetModel();
}

int WifiListModel::rowCount(const QModelIndex &parent) const
{
    return _wifis.size();
}

QVariant WifiListModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
    {
        return _wifis.at(index.row());
    }
    return QVariant();
}

QList<QString >WifiListModel::wifis() const
{
    return _wifis;
}
