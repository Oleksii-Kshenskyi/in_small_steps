#include "cloperations.h"

CLIArithmeticOperation::CLIArithmeticOperation(std::shared_ptr<CLModel> newModel)
    : model(newModel)
{

}

QString CLIArithmeticOperation::getResult()
{
    return (this->precision == -1) ? QString::number(this->model->getResult(), 'e') :
           (this->precision == 0)  ? QString::number(this->model->getResult()) :
                                     QString::number(this->model->getResult(), 'f', this->precision);
}

void CLIArithmeticOperation::setResult(const QString& result)
{
    updatePrecision(result);
    this->model->setResult(result.toDouble());
}

void CLIArithmeticOperation::setDelta(const QString& delta)
{
    updatePrecision(delta);
    this->model->setDelta(delta.toDouble());
}

void CLIArithmeticOperation::updatePrecision(const QString& forThisString)
{
    auto size = forThisString.size();
    if(size > this->MaxDisplaySize)
    {
        this->precision = -1;
        return;
    }

    auto index = forThisString.indexOf('.', 0, Qt::CaseInsensitive);
    if(index == -1)
        return;

    auto updatedPrecision = size - index - 1;
    if(updatedPrecision > this->precision)
        this->precision = static_cast<short>(updatedPrecision);
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
