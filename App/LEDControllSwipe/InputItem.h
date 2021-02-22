#ifndef INPUTITEM_H
#define INPUTITEM_H

#include <QObject>
#include <QString>
#include <QImage>

class InputItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameUpdated)
    // Q_PROPERTY(QString m_name READ name WRITE setName NOTIFY nameUpdated) würde auch gehen
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageUpdated)
    Q_PROPERTY(QList<int> checkedObjects READ checkedObjects WRITE setCheckedObjects NOTIFY checkedObjectsChanged)
    //Q_PROPERTY(bool busyRunning READ busyRunning WRITE setBusyRunning NOTIFY timerEnded)
    Q_PROPERTY(QString imagePath READ getImagePath WRITE setImagePath NOTIFY imagePathChanged)

public:
    explicit InputItem(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &name);

    int age() const;
    void setAge(int age);

    QString password() const;
    void setPassword(const QString &password);

    QList<int> checkedObjects() const;
    void setCheckedObjects(const QList<int> &checkedObjects);

    bool busyRunning() const;
    void setBusyRunning(bool busyRunning);

    QString getImagePath() const;

signals:
    void nameUpdated();
    void ageUpdated();
    void checkedObjectsChanged();
    void timerEnded();
    void imagePathChanged();

public slots:
    void setImagePath(const QString &imagePath);
    void onTimerUpdate();
    void appendObject(int value);
    void onTimerStart();
    void onTimerEnd();

private slots:

private:
    QString _name = "LORENZ";
    int _age;
    QString _password;
    QList<int> _checkedObjects;
    bool _busyRunning = false;
    QImage _image;
    QString _imagePath;
};

#endif // INPUTITEM_H
