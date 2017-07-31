#ifndef CLMODEL_H
#define CLMODEL_H
#include <QtGlobal>
#include <QScopedPointer>
#include "model/cloperations.h"

class CLModel
{
  public:
    CLModel(QScopedPointer<CLIArithmeticOperation>& cloNewPointer);
    qreal getResult();
    void setOperation(QScopedPointer<CLIArithmeticOperation>& cloNewPointer);
  private:
    QScopedPointer<CLIArithmeticOperation> cloPointer;
};



#endif // CLMODEL_H
