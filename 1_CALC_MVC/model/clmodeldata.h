#ifndef CLMODELDATA_H
#define CLMODELDATA_H

#include <QtGlobal>

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

#endif // CLMODELDATA_H
