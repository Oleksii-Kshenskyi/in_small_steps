#ifndef CLVIEWMODEL_H
#define CLVIEWMODEL_H

#include <QObject>

class CLViewModel: public QObject
{
    Q_OBJECT

  public:
    CLViewModel(QObject* root);
    QString getDisplayValue();
    void setDisplayValue(QString newValue);
    void eraseOne();
    int getDisplaySize();
  signals:
    displayValueChanged(QString newValue);
  private:
    QString displayValue;
};

#endif //CLVIEWMODEL_H
