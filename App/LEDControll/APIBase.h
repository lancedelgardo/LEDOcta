#ifndef APIBASE_H
#define APIBASE_H

#include <QObject>
#include <QJsonObject>

class APIBase : public QObject
{
    Q_OBJECT
public:
    explicit APIBase(QObject *parent = nullptr);

signals:

public slots:

protected:
 virtual void put(const QString &value);
 virtual void get(const QString &value);

private:
    QJsonObject _response;
    QString _error;
    QString _host;
};

#endif // APIBASE_H
