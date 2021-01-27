#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QFile>
#include <QJsonDocument>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) { ui->setupUi(this); }

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_onPB_clicked() { put("/5/on"); }

void MainWindow::on_offPB_clicked() { put("/5/off"); }

void MainWindow::put(const QString &value)
{
    QTcpSocket socket;
    //    socket.connectToHost("192.168.168.150", 80);
    socket.connectToHost("192.168.168.101", 80);
    QNetworkAccessManager nam;
    //    QString host = "192.168.168.150";
    //    QString path = "/api/v1/nodes/rc_contour/parameters/rccontour_contour_canny_low_thresh";
    QString host = "192.168.168.101";
    QString path = value;

    QString url = "http://" + host + ":" + QString::number(80);
    if (!path.startsWith("/")) url += "/";
    url += path;

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/html");

    /*QNetworkReply *reply = */ nam.get(request);

    //    while (!reply->isFinished())
    //    {
    //        QCoreApplication::processEvents();
    //    }

    //    if (reply->error() != QNetworkReply::NoError)
    //    {
    //        QJsonDocument resultDoc = QJsonDocument::fromJson(reply->readAll());
    //        if (!resultDoc.isEmpty())
    //        {
    //            QJsonObject obj = resultDoc.object();
    //            _error = obj["message"].toString();
    //        }
    //        else
    //        {
    //            _error = reply->errorString();
    //        }
    //        //        return false;
    //    }

    //    QJsonDocument resultDoc = QJsonDocument::fromJson(reply->readAll());
    //    if (resultDoc.isEmpty())
    //    {
    //        qWarning() << "Emtpy Result received!";
    //        //        return false;
    //    }
    //    _response = resultDoc.object();
    //    return true;
}
