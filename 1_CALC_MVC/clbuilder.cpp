#include "clbuilder.h"


QString CLTestBuilder::test()
{
    QScopedPointer<CLIArithmeticOperation> pTestOperation(new CLOAddition(new CLModelData(35,44)));
    CLModel clmTestModel(pTestOperation);
    return QString().number(clmTestModel.getResult());
}
