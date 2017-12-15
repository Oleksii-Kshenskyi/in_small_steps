#ifndef CLVIEWMODEL_H
#define CLVIEWMODEL_H

#include "model/clmodeldata.h"
#include <QObject>

class CLViewModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString displayValue READ getDisplayValue WRITE setDisplayValue NOTIFY displayValueChanged)
  public:
    CLViewModel();
    Q_INVOKABLE QString getDisplayValue();
    Q_INVOKABLE void setDisplayValue(QString newValue);
  signals:
    displayValueChanged(QString newValue);
  private:
    QString displayValue;
};

#endif //CLVIEWMODEL_H
