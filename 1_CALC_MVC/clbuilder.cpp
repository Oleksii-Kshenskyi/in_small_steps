#include "clbuilder.h"


QString CLTestBuilder::testAddition()
{
    QScopedPointer<CLIArithmeticOperation> pTestOperation(new CLOAddition(new CLModelData(35,44)));
    CLModel clmTestModel(pTestOperation);
    return QString().number(clmTestModel.getResult());
}

QString CLTestBuilder::testSubstraction()
{
    QScopedPointer<CLIArithmeticOperation> pTestOperation(new CLOSubstraction(new CLModelData(35,44)));
    CLModel clmTestModel(pTestOperation);
    return QString().number(clmTestModel.getResult());
}

QString CLTestBuilder::testMultiplication()
{
    QScopedPointer<CLIArithmeticOperation> pTestOperation(new CLOMultiplication(new CLModelData(35,44)));
    CLModel clmTestModel(pTestOperation);
    return QString().number(clmTestModel.getResult());
}

QString CLTestBuilder::testDivision()
{
    QScopedPointer<CLIArithmeticOperation> pTestOperation(new CLODivision(new CLModelData(35,44)));
    CLModel clmTestModel(pTestOperation);
    return QString().number(clmTestModel.getResult());
}

void CLTestBuilder::testSetOperationInModel()
{
    QScopedPointer<CLIArithmeticOperation> pTestOperationA(new CLOAddition(new CLModelData(35,44)));
    QScopedPointer<CLIArithmeticOperation> pTestOperationS(new CLOSubstraction(new CLModelData(35,44)));
    CLModel clmTestModel(pTestOperationA);
    qDebug() << "\n1: " << clmTestModel.getResult();
    clmTestModel.setOperation(pTestOperationS);
    qDebug() << "\n2: " << clmTestModel.getResult();

}
