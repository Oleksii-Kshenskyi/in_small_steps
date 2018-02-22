#include "clqmlconnector.h"
#include <QQmlProperty>

const QUrl CLQmlConnector::qmlUrl = QUrl("qrc:/calcui/CalcForm.qml");

CLQmlConnector::CLQmlConnector(QObject *root, std::shared_ptr<QQmlEngine> engine): QObject(root), engine(engine)
{    
    //this->engine->load(this->qmlUrl);
    this->component = std::make_shared<QQmlComponent>(this->engine.get(), this->qmlUrl);
    this->object = std::shared_ptr<QObject>(this->component->create());

    QObject::connect(this->object.get(), SIGNAL(numberClicked(QString)), this, SLOT(setQmlMainDisplayText(QString)));
}

void CLQmlConnector::setQmlMainDisplayText(QString newText)
{
    qDebug() << "prop:" << QQmlProperty(this->object.get(), "mainDisplayText").read().toString();
}
