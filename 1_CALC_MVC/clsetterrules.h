#ifndef CLSETTERRULES_H
#define CLSETTERRULES_H

#include <QList>

class CLISetterRule
{
  public:
    CLISetterRule();
    bool doesIDMatch(QString szIDToValidate);
    virtual QString execute(const QString& szOldValue) = 0;
    virtual ~CLISetterRule();
  private:
    static QString szID;
};

class CLSRCancel: public CLISetterRule
{
  public:
    CLSRCancel();
    QString execute(const QString& szOldValue);
  private:
    static QString szID;
};

#endif // CLSETTERRULES_H
