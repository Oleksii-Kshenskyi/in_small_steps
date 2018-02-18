#include "cloperations.h"

CLIArithmeticOperation::CLIArithmeticOperation(std::shared_ptr<CLModelData> clmNewModel)
    : clmCurrentModel(clmNewModel)
{

}

qreal CLIArithmeticOperation::getResult()
{
    return clmCurrentModel->getResult();
}

CLOAddition::CLOAddition(std::shared_ptr<CLModelData> clmNewModel) : CLIArithmeticOperation(clmNewModel)
{
    execute();
}

CLOSubstraction::CLOSubstraction(std::shared_ptr<CLModelData> clmNewModel) : CLIArithmeticOperation(clmNewModel)
{
    execute();
}

CLOMultiplication::CLOMultiplication(std::shared_ptr<CLModelData> clmNewModel) : CLIArithmeticOperation(clmNewModel)
{
    execute();
}

CLODivision::CLODivision(std::shared_ptr<CLModelData> clmNewModel) : CLIArithmeticOperation(clmNewModel)
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
