#include "clmodel.h"

CLModel::CLModel()
{
    this->data.delta = 0;
    this->data.result = 0;
}

double CLModel::getDelta()
{
    return this->data.delta;
}

void CLModel::setDelta(double newDelta)
{
    this->data.delta = newDelta;
}

double CLModel::getResult()
{
    return this->data.result;
}

void CLModel::setResult(double newResult)
{
    this->data.result = newResult;
}
