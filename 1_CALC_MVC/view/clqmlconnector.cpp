#include "clqmlconnector.h"
#include <QQmlProperty>

const QUrl CLQmlConnector::qmlUrl = QUrl("qrc:/calcui/CalcForm.qml");

CLQmlConnector::CLQmlConnector(QObject *root, std::shared_ptr<QQmlApplicationEngine> engine): QObject(root), engine(engine)
{
    this->engine->load(this->qmlUrl);

    this->view = std::make_unique<QQuickView>(this->qmlUrl);
    this->component = std::make_unique<QQmlComponent>(this->engine.get(), this->qmlUrl);
    this->object = std::unique_ptr<QObject>(component->create());
}

void CLQmlConnector::setQmlMainDisplayText(QString newText)
{
    qDebug() << "newText" << newText;
    //QMetaObject::invokeMethod(this->object.get(), "setDisplayTextString", Q_ARG(QVariant, QVariant(newText)));
    //this->object->setProperty("mainDisplayText", newText);
    QQmlProperty::write(this->object.get(), "mainDisplayText", newText);
    qDebug() << "Prop:" << QQmlProperty::read(this->object.get(), "mainDisplayText").toString();
}

void CLQmlConnector::setContextProperty(QString propertyName, QObject* propertyObject)
{
    this->engine->rootContext()->setContextProperty(propertyName, propertyObject);
}
