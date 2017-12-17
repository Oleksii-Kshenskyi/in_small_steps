#include "view/clviewvodel.h"
#include <QQmlEngine>

CLViewModel::CLViewModel(QObject *root): QObject(root), displayValue("0")
{
    //qmlRegisterType<CLViewModel>("com.darkspectre.calculator", 1, 0, "ViewModel");
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
