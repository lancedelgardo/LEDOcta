#ifndef INPUTDATAS_H
#define INPUTDATAS_H

#include "InputItem.h"

#include <QObject>
#include <QList>

class InputDatas : public QObject
{
    Q_OBJECT
    Q_PROPERTY(InputItem *currentItem READ currentItem WRITE setCurrentItem NOTIFY currentItemChanged)
public:
    explicit InputDatas(QObject *parent = nullptr);

    QList<InputItem *> items() const;
    void setItems(const QList<InputItem *> &items);

    InputItem *currentItem() const;
    void setCurrentItem(InputItem *currentItem);

signals:
    void currentItemChanged();

public slots:

private:
    QList<InputItem*> _items;
    InputItem *_currentItem = Q_NULLPTR;
};

#endif // INPUTDATAS_H
