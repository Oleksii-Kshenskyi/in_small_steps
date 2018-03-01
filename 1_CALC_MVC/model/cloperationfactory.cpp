#include "cloperationfactory.h"


CLOperationFactory::CLOperationFactory(const QString& operation, std::shared_ptr<CLModel> model): operation(operation), model(model), functions {{"add", &CLOperationFactory::createAdd},
                                                                                                                                                 {"sub", &CLOperationFactory::createSub},
                                                                                                                                                 {"mul", &CLOperationFactory::createMul},
                                                                                                                                                 {"div", &CLOperationFactory::createDiv}}
{

}

std::shared_ptr<CLIArithmeticOperation> CLOperationFactory::create()
{
    return (this->*functions[this->operation])();
}

std::shared_ptr<CLIArithmeticOperation> CLOperationFactory::createAdd()
{
    return std::make_shared<CLOAddition>(this->model);
}

std::shared_ptr<CLIArithmeticOperation> CLOperationFactory::createSub()
{
    return std::make_shared<CLOSubstraction>(this->model);
}

std::shared_ptr<CLIArithmeticOperation> CLOperationFactory::createMul()
{
    return std::make_shared<CLOMultiplication>(this->model);
}

std::shared_ptr<CLIArithmeticOperation> CLOperationFactory::createDiv()
{
    return std::make_shared<CLODivision>(this->model);
}
