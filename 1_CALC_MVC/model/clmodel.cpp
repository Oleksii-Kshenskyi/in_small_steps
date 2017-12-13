#include "clmodel.h"

CLModel::CLModel(std::shared_ptr<CLIArithmeticOperation> cloNewPointer)
{
    setOperation(cloNewPointer);
}

qreal CLModel::getResult()
{
    return cloPointer->getResult();
}

void CLModel::setOperation(std::shared_ptr<CLIArithmeticOperation> cloNewPointer)
{
    cloPointer.swap(cloNewPointer);
}
