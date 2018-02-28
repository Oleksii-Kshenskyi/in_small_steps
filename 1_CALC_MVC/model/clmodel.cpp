#include "clmodel.h"

CLModel::CLModel()
{

}

double CLModel::getFirst()
{
    return this->data.getFirst();
}

void CLModel::setFirst(double newFirst)
{
    this->data.setFirst(newFirst);
}

double CLModel::getSecond()
{
    return this->data.getSecond();
}

void CLModel::setSecond(double newSecond)
{
    this->data.setSecond(newSecond);
}

void CLModel::setResult(double newResult)
{
    this->data.setResult(newResult);
}

double CLModel::getResult()
{
    return this->data.getResult();
}
