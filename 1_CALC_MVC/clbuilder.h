#ifndef CLBUILDER_H
#define CLBUILDER_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "clmodel.h"
#include <QString>
#include <QDebug>
#include "clbuilder.h"

class CLTestBuilder: public QObject
{
    Q_OBJECT
  public:

    Q_INVOKABLE QString test();

};

#endif // CLBUILDER_H
