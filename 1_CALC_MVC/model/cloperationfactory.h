#ifndef CLOPERATIONFACTORY_H
#define CLOPERATIONFACTORY_H

#include <QString>
#include <memory>
#include "cloperations.h"
#include "clmodel.h"
#include <QMap>

class CLOperationFactory
{
  public:
    CLOperationFactory(std::shared_ptr<CLModel> model);
    std::shared_ptr<CLIArithmeticOperation> create(const QString& operation);

  private:
    QString operation;
    std::shared_ptr<CLModel> model;

    std::shared_ptr<CLIArithmeticOperation> createAdd();
    std::shared_ptr<CLIArithmeticOperation> createSub();
    std::shared_ptr<CLIArithmeticOperation> createMul();
    std::shared_ptr<CLIArithmeticOperation> createDiv();

    typedef std::shared_ptr<CLIArithmeticOperation> (CLOperationFactory::*CreateFunc)();
    QMap<QString, CreateFunc> functions;
};

#endif //CLOPERATIONFACTORY_H
