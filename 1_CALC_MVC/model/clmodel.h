#ifndef CLMODEL_H
#define CLMODEL_H
#include <QtGlobal>
#include <memory>
#include "model/cloperations.h"

class CLModel
{
  public:
    CLModel(std::shared_ptr<CLIArithmeticOperation> cloNewPointer);
    qreal getResult();
    void setOperation(std::shared_ptr<CLIArithmeticOperation> cloNewPointer);
  private:
    std::shared_ptr<CLIArithmeticOperation> cloPointer;
};



#endif // CLMODEL_H
