#include "clbuilder.h"

QString CLTestBuilder::testAddition()
{
    CLModel clmTestModel(std::make_shared<CLOAddition>(std::make_shared<CLModelData>(35,44)));
    return QString().number(clmTestModel.getResult());
}

QString CLTestBuilder::testSubstraction()
{
    CLModel clmTestModel(std::make_shared<CLOSubstraction>(std::make_shared<CLModelData>(35,44)));
    return QString().number(clmTestModel.getResult());
}

QString CLTestBuilder::testMultiplication()
{
    CLModel clmTestModel(std::make_shared<CLOMultiplication>(std::make_shared<CLModelData>(35,44)));
    return QString().number(clmTestModel.getResult());
}

QString CLTestBuilder::testDivision()
{
    CLModel clmTestModel(std::make_shared<CLODivision>(std::make_shared<CLModelData>(35,44)));
    return QString().number(clmTestModel.getResult());
}

void CLTestBuilder::testSetOperationInModel()
{
    CLModel clmTestModel(std::make_shared<CLOSubstraction>(std::make_shared<CLModelData>(35,44)));
    qDebug() << "\n1: " << clmTestModel.getResult();
    clmTestModel.setOperation(std::make_shared<CLOAddition>(std::make_shared<CLModelData>(35,44)));
    qDebug() << "\n2: " << clmTestModel.getResult();

}
