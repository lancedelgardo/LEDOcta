#include "InputDatas.h"

InputDatas::InputDatas(QObject *parent) : QObject(parent)
{
    InputItem *it = new InputItem(this);
    it->setName("Erstes Item");
    _items.append(it);

    InputItem *it2 = new InputItem(this);
    it2->setName("Zweites Item");
    _items.append(it2);

    _currentItem = it2;
}

QList<InputItem *> InputDatas::items() const
{
    return _items;
}

void InputDatas::setItems(const QList<InputItem *> &items)
{
    _items = items;
}

InputItem *InputDatas::currentItem() const
{
    return _currentItem;
}

void InputDatas::setCurrentItem(InputItem *currentItem)
{
    _currentItem = currentItem;
}
