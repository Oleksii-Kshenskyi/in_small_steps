#include "cloperations.h"

CLIArithmeticOperation::CLIArithmeticOperation(std::shared_ptr<CLModel> newModel)
    : model(newModel)
{

}

QString CLIArithmeticOperation::getResult()
{
    return QString::number(this->model->getResult(), 'g', 22);
}

void CLIArithmeticOperation::setFirst(const QString& first)
{
    this->model->setFirst(first.toDouble());
}

void CLIArithmeticOperation::setSecond(const QString& second)
{
    this->model->setSecond(second.toDouble());
}

CLOAddition::CLOAddition(std::shared_ptr<CLModel> newModel) : CLIArithmeticOperation(newModel)
{

}

CLOSubstraction::CLOSubstraction(std::shared_ptr<CLModel> newModel) : CLIArithmeticOperation(newModel)
{

}

CLOMultiplication::CLOMultiplication(std::shared_ptr<CLModel> newModel) : CLIArithmeticOperation(newModel)
{

}

CLODivision::CLODivision(std::shared_ptr<CLModel> newModel) : CLIArithmeticOperation(newModel)
{

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
