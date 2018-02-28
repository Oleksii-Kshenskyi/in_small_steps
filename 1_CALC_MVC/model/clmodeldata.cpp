#include "clmodeldata.h"

CLModelData::CLModelData()
    : first(0), second(0), result(0)
{

}

void CLModelData::setFirst(double newFirst)
{
    this->first = newFirst;
}

double CLModelData::getFirst()
{
    return this->first;
}

void CLModelData::setSecond(double newSecond)
{
    this->second = newSecond;
}

double CLModelData::getSecond()
{
    return this->second;
}

void CLModelData::setResult(double newResult)
{
    this->result = newResult;
}

double CLModelData::getResult()
{
    return this->result;
}
