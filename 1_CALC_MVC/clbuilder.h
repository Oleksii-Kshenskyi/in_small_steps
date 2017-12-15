#ifndef CLBUILDER_H
#define CLBUILDER_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "model/clmodel.h"
#include "model/cloperations.h"
#include "model/clmodeldata.h"
#include <QString>
#include <QDebug>
#include "clbuilder.h"
#include "view/clview.h"

class CLTestBuilder: public QObject
{
    Q_OBJECT
  public:
    CLTestBuilder();

    Q_INVOKABLE QString testAddition();
    Q_INVOKABLE QString testSubstraction();
    Q_INVOKABLE QString testMultiplication();
    Q_INVOKABLE QString testDivision();
    void testSetOperationInModel();

  private:
    std::shared_ptr<CLView> ui;

};

#endif // CLBUILDER_H
