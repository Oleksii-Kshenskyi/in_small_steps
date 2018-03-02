#ifndef CLOPERATIONS_H
#define CLOPERATIONS_H

#include "model/clmodel.h"
#include <memory>
#include <QString>

class CLIArithmeticOperation
{
  public:
    CLIArithmeticOperation(std::shared_ptr<CLModel> newModel);
    virtual ~CLIArithmeticOperation() = default;

    QString getResult();
    void setFirst(const QString& first);
    void setSecond(const QString& second);
    virtual void execute() = 0;
  protected:
    std::shared_ptr<CLModel> model;

};

class CLOAddition: public CLIArithmeticOperation
{
  public:
    CLOAddition(std::shared_ptr<CLModel> newModel);
    virtual void execute() override;
};

class CLOSubstraction: public CLIArithmeticOperation
{
  public:
    CLOSubstraction(std::shared_ptr<CLModel> newModel);
    virtual void execute() override;
};

class CLOMultiplication: public CLIArithmeticOperation
{
  public:
    CLOMultiplication(std::shared_ptr<CLModel> newModel);
    virtual void execute() override;
};

class CLODivision: public CLIArithmeticOperation
{
  public:
    CLODivision(std::shared_ptr<CLModel> newModel);
    virtual void execute() override;
};

#endif // CLOPERATIONS_H
