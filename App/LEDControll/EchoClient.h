#ifndef ECHOCLIENT_H
#define ECHOCLIENT_H

#include <QUrl>
#include <QObject>
#include <QWebSocket>

class EchoClient : public QObject
{
    Q_OBJECT
  public:
    EchoClient(const QUrl &url, bool debug, QObject *parent = Q_NULLPTR);

  private slots:
    void onConnected();
    void onTextMessageReceived(const QString &message);
    void closed();
    void onError(QAbstractSocket::SocketError error);

  private:
    QUrl m_Url;
    bool m_Debug;
    QWebSocket m_webSocket;
};

#endif  // ECHOCLIENT_H
