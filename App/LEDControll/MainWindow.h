#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "EchoClient.h"

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void on_onPB_clicked();

    void on_offPB_clicked();


  private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *_manager = Q_NULLPTR;
    EchoClient *_echoClient = Q_NULLPTR;
};
#endif  // MAINWINDOW_H
