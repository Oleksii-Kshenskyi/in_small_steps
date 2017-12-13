#include "clsetterrules.h"

QString CLISetterRule::szID = "INVALID";
QString CLSRCancel::szID = "C";

CLISetterRule::CLISetterRule()
{
   szID = "INVALID";
}

CLISetterRule::~CLISetterRule()
{

}

bool CLISetterRule::doesIDMatch(QString szIDToValidate)
{
    return szID == szIDToValidate;
}

CLSRCancel::CLSRCancel()
{
}

QString CLSRCancel::execute(const QString& szOldValue)
{
    return ((doesIDMatch(szOldValue)) ? ("0") : (""));
}
