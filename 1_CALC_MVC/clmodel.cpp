#include "clmodel.h"

CLModel::CLModel(QScopedPointer<CLIArithmeticOperation>& cloNewPointer)
{
    setOperation(cloNewPointer);
}

/*QScopedPointer<CLIArithmeticOperation>& CLModel::getOperation()
{
    return cloPointer;
}*/

qreal CLIArithmeticOperation::getResult()
{
    return clmCurrentModel->getResult();
}

qreal CLModel::getResult()
{
    return cloPointer->getResult();
}

void CLModel::setOperation(QScopedPointer<CLIArithmeticOperation>& cloNewPointer)
{
    cloPointer.swap(cloNewPointer);
}

CLModelData::CLModelData(qreal fNewFirst, qreal fNewSecond)
    : fFirstOperand(fNewFirst), fSecondOperand(fNewSecond)
{

}

CLIArithmeticOperation::CLIArithmeticOperation(CLModelData* clmNewModel)
    : clmCurrentModel(clmNewModel)
{

}

CLIArithmeticOperation::~CLIArithmeticOperation()
{

}

CLOAddition::CLOAddition(CLModelData* clmNewModel) : CLIArithmeticOperation(clmNewModel)
{
    execute();
}

CLOSubstraction::CLOSubstraction(CLModelData* clmNewModel) : CLIArithmeticOperation(clmNewModel)
{
    execute();
}

CLOMultiplication::CLOMultiplication(CLModelData* clmNewModel) : CLIArithmeticOperation(clmNewModel)
{
    execute();
}

CLODivision::CLODivision(CLModelData* clmNewModel) : CLIArithmeticOperation(clmNewModel)
{
    execute();
}

void CLOAddition::execute()
{
    clmCurrentModel->setResult(clmCurrentModel->getFirst() + clmCurrentModel->getSecond());
}

void CLOSubstraction::execute()
{
    clmCurrentModel->setResult(clmCurrentModel->getFirst() - clmCurrentModel->getSecond());
}

void CLOMultiplication::execute()
{
    clmCurrentModel->setResult(clmCurrentModel->getFirst() * clmCurrentModel->getSecond());
}

void CLODivision::execute()
{
    clmCurrentModel->setResult(clmCurrentModel->getFirst() / clmCurrentModel->getSecond());
}

void CLModelData::setFirst(qreal fNewFirst)
{
    fFirstOperand = fNewFirst;
}

qreal CLModelData::getFirst()
{
    return fFirstOperand;
}

void CLModelData::setSecond(qreal fNewSecond)
{
    fSecondOperand = fNewSecond;
}

qreal CLModelData::getSecond()
{
    return fSecondOperand;
}

void CLModelData::setResult(qreal fNewResult)
{
    fResult = fNewResult;
}

qreal CLModelData::getResult()
{
    return fResult;
}
