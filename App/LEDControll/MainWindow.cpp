#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "ControllLed.h"


#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QFile>
#include <QJsonDocument>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _wifiHandler = new WIFIHandler();
    ui->listView->setModel(_wifiHandler->model());
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_onPB_clicked()
{
    // Flush Prom
    ControllLed cl;
    //    cl.ledOn();
    ;
    cl.setHost(ui->ipLineEdit->text());
    cl.flushProm();
}

void MainWindow::on_offPB_clicked()
{
    // READ PROM
    ControllLed cl;
    //    cl.ledOn();
    cl.setHost(ui->ipLineEdit->text());
    cl.readProm();
}

void MainWindow::on_scanWifipushButton_clicked()
{
    _wifiHandler->scanWifi();
    ui->listView->update();
}

void MainWindow::on_sendWifiPushButton_clicked()
{
    ControllLed cl;
    cl.setHost(ui->ipLineEdit->text());
    cl.sendWifiData(ui->ssidLineEdit->text(), ui->passwordLineEdit->text());
}

void MainWindow::on_pushButton_clicked()
{
    // writeProm
    ControllLed cl;
    cl.setHost(ui->ipLineEdit->text());
    cl.writeProm();
}
