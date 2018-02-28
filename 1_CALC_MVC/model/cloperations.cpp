#include "cloperations.h"

CLIArithmeticOperation::CLIArithmeticOperation(std::shared_ptr<CLModel> newModel)
    : model(newModel)
{

}

double CLIArithmeticOperation::getResult()
{
    return this->model->getResult();
}

CLOAddition::CLOAddition(std::shared_ptr<CLModel> newModel) : CLIArithmeticOperation(newModel)
{
    execute();
}

CLOSubstraction::CLOSubstraction(std::shared_ptr<CLModel> newModel) : CLIArithmeticOperation(newModel)
{
    execute();
}

CLOMultiplication::CLOMultiplication(std::shared_ptr<CLModel> newModel) : CLIArithmeticOperation(newModel)
{
    execute();
}

CLODivision::CLODivision(std::shared_ptr<CLModel> newModel) : CLIArithmeticOperation(newModel)
{
    execute();
}

void CLOAddition::execute()
{
    this->model->setResult(this->model->getFirst() + this->model->getSecond());
}

void CLOSubstraction::execute()
{
    this->model->setResult(this->model->getFirst() - this->model->getSecond());
}

void CLOMultiplication::execute()
{
    this->model->setResult(this->model->getFirst() * this->model->getSecond());
}

void CLODivision::execute()
{
    this->model->setResult(this->model->getFirst() / this->model->getSecond());
}
