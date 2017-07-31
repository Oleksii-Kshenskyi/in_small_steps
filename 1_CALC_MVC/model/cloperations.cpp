#include "cloperations.h"

CLIArithmeticOperation::CLIArithmeticOperation(CLModelData* clmNewModel)
    : clmCurrentModel(clmNewModel)
{

}

CLIArithmeticOperation::~CLIArithmeticOperation()
{

}

qreal CLIArithmeticOperation::getResult()
{
    return clmCurrentModel->getResult();
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
