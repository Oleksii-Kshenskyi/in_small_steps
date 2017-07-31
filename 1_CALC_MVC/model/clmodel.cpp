#include "clmodel.h"

CLModel::CLModel(QScopedPointer<CLIArithmeticOperation>& cloNewPointer)
{
    setOperation(cloNewPointer);
}

qreal CLModel::getResult()
{
    return cloPointer->getResult();
}

void CLModel::setOperation(QScopedPointer<CLIArithmeticOperation>& cloNewPointer)
{
    cloPointer.swap(cloNewPointer);
}
