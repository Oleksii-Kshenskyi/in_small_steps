#ifndef CLOPERATIONS_H
#define CLOPERATIONS_H

#include "model/clmodeldata.h"
#include <memory>

class CLIArithmeticOperation
{
  public:
    CLIArithmeticOperation(std::shared_ptr<CLModelData> clmNewModel);
    virtual ~CLIArithmeticOperation() = default;
    virtual void execute() = 0;
    qreal getResult();
  protected:
    std::shared_ptr<CLModelData> clmCurrentModel;
};

class CLOAddition: public CLIArithmeticOperation
{
  public:
    CLOAddition(std::shared_ptr<CLModelData> clmNewModel);
    virtual void execute() override;
};

class CLOSubstraction: public CLIArithmeticOperation
{
  public:
    CLOSubstraction(std::shared_ptr<CLModelData> clmNewModel);
    virtual void execute() override;
};

class CLOMultiplication: public CLIArithmeticOperation
{
  public:
    CLOMultiplication(std::shared_ptr<CLModelData> clmNewModel);
    virtual void execute() override;
};

class CLODivision: public CLIArithmeticOperation
{
  public:
    CLODivision(std::shared_ptr<CLModelData> clmNewModel);
    virtual void execute() override;
};

#endif // CLOPERATIONS_H
