#include "clmodeldata.h"

CLModelData::CLModelData(qreal fNewFirst, qreal fNewSecond)
    : fFirstOperand(fNewFirst), fSecondOperand(fNewSecond)
{

}

void CLModelData::setFirst(qreal fNewFirst)
{
    fFirstOperand = fNewFirst;
}

qreal CLModelData::getFirst()
{
    return fFirstOperand;
}

void CLModelData::setSecond(qreal fNewSecond)
{
    fSecondOperand = fNewSecond;
}

qreal CLModelData::getSecond()
{
    return fSecondOperand;
}

void CLModelData::setResult(qreal fNewResult)
{
    fResult = fNewResult;
}

qreal CLModelData::getResult()
{
    return fResult;
}
