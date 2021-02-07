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
    ControllLed cl;
    cl.ledOn();
}

void MainWindow::on_offPB_clicked()
{
    ControllLed cl;
    cl.ledOn();
}

void MainWindow::on_scanWifipushButton_clicked()
{
    _wifiHandler->scanWifi();
    ui->listView->update();
}
