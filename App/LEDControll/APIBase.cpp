#include "APIBase.h"

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QFile>
#include <QJsonDocument>
#include <QCoreApplication>
#include <QSettings>


APIBase::APIBase(QObject *parent) : QObject(parent)
{
    //    QSettings set;
    //    set.beginGroup("main");
    //    _host = set.value("Host").toString();
    //    set.endGroup();

    _host = "192.168.168.168";
}

void APIBase::put(const QString &value)
{
    QTcpSocket socket;
    socket.connectToHost(_host, 80);
    QNetworkAccessManager nam;

    QString path = value;
    QString url = "http://" + _host + ":" + QString::number(80);
    if (!path.startsWith("/")) url += "/";
    url += path;

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/html");

    QByteArray data = value.toUtf8().data();
    QNetworkReply *reply = nam.put(request, data);

    connect(reply, &QNetworkReply::readyRead, this, [=]() { qDebug() << reply->readAll(); });

    while (!reply->isFinished())
    {
        QCoreApplication::processEvents();
    }

    if (reply->error() != QNetworkReply::NoError)
    {
        QJsonDocument resultDoc = QJsonDocument::fromJson(reply->readAll());
        if (!resultDoc.isEmpty())
        {
            QJsonObject obj = resultDoc.object();
            _error = obj["message"].toString();
        }
        else
        {
            _error = reply->errorString();
        }
        //        return false;
    }


    qDebug() << "Fertig mit senden";
}

void APIBase::get(const QString &value)
{
    QTcpSocket socket;
    socket.connectToHost(_host, 80);
    QNetworkAccessManager nam;

    QString path = value;
    QString url = "http://" + _host + ":" + QString::number(80);
    if (!path.startsWith("/")) url += "/";
    url += path;

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/html");

    QNetworkReply *reply = nam.get(request);


    connect(reply, &QNetworkReply::readyRead, this, [=]() { qDebug() << reply->readAll(); });

    while (!reply->isFinished())
    {
        QCoreApplication::processEvents();
    }

    if (reply->error() != QNetworkReply::NoError)
    {
        QJsonDocument resultDoc = QJsonDocument::fromJson(reply->readAll());
        if (!resultDoc.isEmpty())
        {
            QJsonObject obj = resultDoc.object();
            _error = obj["message"].toString();
        }
        else
        {
            _error = reply->errorString();
        }
        //        return false;
    }

    qDebug() << _response;

    qDebug() << "Fertig mit senden";
}

void APIBase::setHost(const QString &host) { _host = host; }
