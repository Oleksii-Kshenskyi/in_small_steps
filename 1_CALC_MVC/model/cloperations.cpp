#include "cloperations.h"

CLIArithmeticOperation::CLIArithmeticOperation(std::shared_ptr<CLModel> newModel)
    : model(newModel)
{

}

QString CLIArithmeticOperation::getResult()
{
    return QString::number(this->model->getResult());
}

void CLIArithmeticOperation::setResult(const QString& result)
{
    this->model->setResult(result.toDouble());
}

void CLIArithmeticOperation::setDelta(const QString& delta)
{
    this->model->setDelta(delta.toDouble());
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
    this->model->setResult(this->model->getResult() + this->model->getDelta());
}

void CLOSubstraction::execute()
{
    this->model->setResult(this->model->getResult() - this->model->getDelta());
}

void CLOMultiplication::execute()
{
    this->model->setResult(this->model->getResult() * this->model->getDelta());
}

void CLODivision::execute()
{
    this->model->setResult(this->model->getResult() / this->model->getDelta());
}
