#ifndef CLOPERATIONS_H
#define CLOPERATIONS_H

#include "model/clmodeldata.h"

class CLIArithmeticOperation
{
  public:
    CLIArithmeticOperation(CLModelData* clmNewModel);
    virtual ~CLIArithmeticOperation();
    virtual void execute() = 0;
    qreal getResult();
  protected:
    CLModelData* clmCurrentModel;
};

class CLOAddition: public CLIArithmeticOperation
{
  public:
    CLOAddition(CLModelData* clmNewModel);
    void execute();
};

class CLOSubstraction: public CLIArithmeticOperation
{
  public:
    CLOSubstraction(CLModelData* clmNewModel);
    void execute();
};

class CLOMultiplication: public CLIArithmeticOperation
{
  public:
    CLOMultiplication(CLModelData* clmNewModel);
    void execute();
};

class CLODivision: public CLIArithmeticOperation
{
  public:
    CLODivision(CLModelData* clmNewModel);
    void execute();
};

#endif // CLOPERATIONS_H
