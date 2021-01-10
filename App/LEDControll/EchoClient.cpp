#include "EchoClient.h"

#include <QDebug>
#include <QNetworkAccessManager>
#include <QTcpSocket>

EchoClient::EchoClient(const QUrl &url, bool debug, QObject *parent) : QObject(parent), m_Url(url), m_Debug(debug)
{
    QNetworkProxy::setApplicationProxy(QNetworkProxy::NoProxy);
    if (m_Debug) qDebug() << "WebSocket server:" << url;
    //    connect(&m_webSocket, &QWebSocket::connected, this, &EchoClient::onConnected);
    //    connect(&m_webSocket, &QWebSocket::disconnected, this, &EchoClient::closed);
    //    connect(&m_webSocket, &QWebSocket::error, this, &EchoClient::onError);
    //    connect(&m_webSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
    //    m_webSocket.open(QUrl(url));
}

void EchoClient::onConnected()
{
    if (m_Debug) qDebug() << "WebSocket connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &EchoClient::onTextMessageReceived);
    m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}

void EchoClient::onTextMessageReceived(const QString &message)
{
    if (m_Debug) qDebug() << "Message received:" << message;
    m_webSocket.close();
}

void EchoClient::closed() {}

void EchoClient::onError(QAbstractSocket::SocketError error) { qDebug() << error; }
