#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>

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
    QJsonObject _response;
    QString _error;

    void put(const QString &value);
};
#endif  // MAINWINDOW_H
