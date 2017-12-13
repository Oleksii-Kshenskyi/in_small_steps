#include "clviewsetter.h"

CLViewSetter::CLViewSetter()
    : vRules(QList<std::shared_ptr<CLISetterRule>>())
{

}

CLViewSetter::CLViewSetter(QList<std::shared_ptr<CLISetterRule>>& vNewRules)
{
    vRules.append(vNewRules);
}

void CLViewSetter::addRule(std::shared_ptr<CLISetterRule> clsrNewRule)
{
    vRules.append(clsrNewRule);
    //vRules.last().swap(clsrNewRule);
}
