#ifndef CLISETTER_H
#define CLISETTER_H

#include <QList>
#include "clsetterrules.h"
#include <memory>

class CLViewSetter
{
  public:
    CLViewSetter();
    CLViewSetter(QList<std::shared_ptr<CLISetterRule> > &vNewRules);
    void addRule(std::shared_ptr<CLISetterRule> clsrNewRule);
  private:
    QList<std::shared_ptr<CLISetterRule>> vRules;
};

#endif // CLISETTER_H
