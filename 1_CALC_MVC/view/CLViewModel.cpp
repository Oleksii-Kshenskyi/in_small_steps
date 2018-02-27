#include "view/clviewmodel.h"
#include <QQmlEngine>
#include <QDebug>

CLViewModel::CLViewModel(QObject *root): QObject(root), displayValue("0")
{

}

QString CLViewModel::getDisplayValue()
{
    return displayValue;
}

void CLViewModel::setDisplayValue(QString newValue)
{
    this->displayValue = newValue;
    emit displayValueChanged(newValue);
}

void CLViewModel::eraseOne()
{
    this->displayValue.truncate(this->displayValue.size() - 1);
    emit displayValueChanged(this->displayValue);
}

int CLViewModel::getDisplaySize()
{
   return this->displayValue.size();
}
