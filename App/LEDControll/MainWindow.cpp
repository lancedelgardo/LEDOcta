#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QNetworkReply>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _echoClient = new EchoClient(QUrl("http://192.168.178.101/"), true, this);

    _manager = new QNetworkAccessManager();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_onPB_clicked()
{
    QNetworkReply *r = _manager->get(QNetworkRequest(QUrl("192.168.178.101/LED=ON")));
    qDebug() << r->errorString();
}

void MainWindow::on_offPB_clicked() { _manager->get(QNetworkRequest(QUrl("http://192.168.1/LED=OFF"))); }
