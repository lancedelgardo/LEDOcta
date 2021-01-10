#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    _echoClient = new EchoClient(QUrl("http://192.168.178.101/"), true, this);

    _manager = new QNetworkAccessManager();
    QObject::connect(_manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if (reply->error())
        {
            qDebug() << reply->errorString();
            return;
        }

        QString answer = reply->readAll();

        qDebug() << answer;
    });
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_onPB_clicked()
{
    //    QString m_Host = "192.168.168.101";
    //    quint16 m_Port = 80;

    //    QTcpSocket socket;
    //    socket.connectToHost(m_Host, m_Port);
    //    QNetworkAccessManager nam;

    //    QString url1 = m_Host + "/5/on";

    //    QNetworkRequest request(url1);
    //    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/html");
    //    request.setRawHeader("Connection", "keep-alive, Upgrade");

    //    QByteArray arr;
    //    QNetworkReply *reply = nam.get(request);

    //    while (!reply->isFinished())
    //    {

    //        QCoreApplication::processEvents();
    //    }


    //    QByteArray ret;
    //    qWarning() << "QNetworkReply return error " << reply->error();
    //    ret = reply->readAll();

    //    qDebug() << ret;

    QNetworkRequest request;
    request.setUrl(QUrl("192.168.178.101/5/off"));
    _manager->get(request);
}

void MainWindow::on_offPB_clicked()
{
    QNetworkRequest request;
    request.setUrl(QUrl("192.168.178.101/5/on"));
    _manager->get(request);


    //    QString m_Host = "192.168.168.101";
    //    quint16 m_Port = 80;

    //    QTcpSocket socket;
    //    socket.connectToHost(m_Host, m_Port);

    //    if (socket.waitForConnected(1000)) qDebug("Connected!");
    //    QNetworkAccessManager nam;


    //    QString url1 = m_Host + "/5/on";

    //    QNetworkRequest request(url1);
    //    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/html");
    //    request.setRawHeader("Connection", "keep-alive, Upgrade");


    //    QByteArray arr;
    //    QNetworkReply *reply = nam.get(request);

    //    while (!reply->isFinished())
    //    {

    //        QCoreApplication::processEvents();
    //    }


    //    QByteArray ret;
    //    qWarning() << "QNetworkReply return error " << reply->error();
    //    ret = reply->readAll();

    //    qDebug() << ret;
}
