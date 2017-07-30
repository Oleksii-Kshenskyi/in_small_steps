#ifndef CLMODEL_H
#define CLMODEL_H
#include <QtGlobal>
#include <QScopedPointer>

class CLModelData
{
  public:
    CLModelData(qreal fNewFirst, qreal fNewSecond);
    void setFirst(qreal fNewFirst);
    qreal getFirst();
    void setSecond(qreal fNewSecond);
    qreal getSecond();
    void setResult(qreal fNewResult);
    qreal getResult();
  private:
    qreal fFirstOperand;
    qreal fSecondOperand;
    qreal fResult;
};

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

class CLModel
{
  public:
    CLModel(QScopedPointer<CLIArithmeticOperation>& cloNewPointer);
    qreal getResult();
    //QScopedPointer<CLIArithmeticOperation>& getOperation();
    void setOperation(QScopedPointer<CLIArithmeticOperation>& cloNewPointer);
  private:
    QScopedPointer<CLIArithmeticOperation> cloPointer;
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

#endif // CLMODEL_H
