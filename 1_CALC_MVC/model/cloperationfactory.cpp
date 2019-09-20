#include "cloperationfactory.h"


CLOperationFactory::CLOperationFactory(std::shared_ptr<CLModel> model): model(model), functions {{"+", &CLOperationFactory::createAdd},
                                                                                                 {"-", &CLOperationFactory::createSub},
                                                                                                 {"*", &CLOperationFactory::createMul},
                                                                                                 {"/", &CLOperationFactory::createDiv}}
{

}

std::shared_ptr<CLIArithmeticOperation> CLOperationFactory::create(const QString& operation)
{
    return (this->*functions[operation])();
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
