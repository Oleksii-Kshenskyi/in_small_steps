#ifndef CLMODEL_H
#define CLMODEL_H
#include <QtGlobal>
#include <memory>
#include "model/clmodeldata.h"

class CLModel
{
  public:
    CLModel();

    double getDelta();
    void setDelta(double newDelta);
    void setResult(double newResult);
    double getResult();

  private:
    CLModelData data;
};



#endif // CLMODEL_H
