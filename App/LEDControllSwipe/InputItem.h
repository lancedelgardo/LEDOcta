#ifndef INPUTITEM_H
#define INPUTITEM_H

#include <QObject>
#include <QString>

class InputItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameUpdated)
    // Q_PROPERTY(QString m_name READ name WRITE setName NOTIFY nameUpdated) würde auch gehen
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageUpdated)
    Q_PROPERTY(QList<int> checkedObjects READ checkedObjects WRITE setCheckedObjects NOTIFY checkedObjectsChanged)

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

signals:
    void nameUpdated();
    void ageUpdated();
    void checkedObjectsChanged();

public slots:
    void onTimerUpdate();
    void appendObject(int value);

private slots:

private:
    QString _name = "LORENZ";
    int _age;
    QString _password;
    QList<int> _checkedObjects;
};

#endif // INPUTITEM_H
