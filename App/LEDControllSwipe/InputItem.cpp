#include "InputItem.h"

#include <QDebug>
#include <QTimer>

InputItem::InputItem(QObject *parent) : QObject(parent)
{
    _checkedObjects.append(1);
    _checkedObjects.append(3);
    //QTimer::singleShot(10000, this, SLOT(onTimerUpdate()));
}

QString InputItem::name() const
{
    return _name;
}

void InputItem::setName(const QString &name)
{
    _name = name;
    nameUpdated(); // um qml zu sagen update text
    qDebug() << "New Name: " + _name;
}

int InputItem::age() const
{
    return _age;
}

void InputItem::setAge(int age)
{
    _age = age;
    qDebug() << "New Age: " + QString::number(age);
}

QString InputItem::password() const
{
    return _password;
}

void InputItem::setPassword(const QString &password)
{
    _password = password;
    qDebug() << "New Password: " + _password;
}

QList<int> InputItem::checkedObjects() const
{
    return _checkedObjects;
}

void InputItem::setCheckedObjects(const QList<int> &checkedObjects)
{
    _checkedObjects = checkedObjects;
    qDebug() << "New CheckedObjectsSize: " + QString::number(_checkedObjects.size());
    checkedObjectsChanged();
}

void InputItem::appendObject(int value)
{
    _checkedObjects.append(value);
    qDebug() << "New CheckedObjectsSize: " + QString::number(_checkedObjects.size());
    checkedObjectsChanged();
}

void InputItem::onTimerStart()
{
    QTimer::singleShot(5000,this, SLOT(onTimerEnd()));
    qDebug() << "Timer Started";
}

void InputItem::onTimerEnd()
{
    qDebug() << "Timer End";
    timerEnded();
}

QString InputItem::getImagePath() const
{
    return _imagePath;
}

void InputItem::setImagePath(const QString &imagePath)
{
    _imagePath = imagePath;
    // imagePathChanged();
    qDebug() << "Image Path Set: " + imagePath;
}

bool InputItem::busyRunning() const
{
    return _busyRunning;
}

void InputItem::setBusyRunning(bool busyRunning)
{
    _busyRunning = busyRunning;
}

void InputItem::onTimerUpdate()
{
    setName("TimerNewName");
    qDebug() << "Timer ausgelaufen";
}
