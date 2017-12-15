#include "clqmlconnector.h"

const QUrl CLQmlConnector::qmlUrl = QUrl("qrc:/calcui/CalcForm.qml");

CLQmlConnector::CLQmlConnector()
{
    this->engine = std::make_unique<QQmlApplicationEngine>();
    this->engine->load(this->qmlUrl);
    qDebug() << ((engine->rootObjects().isEmpty()) ? "EMPTY" : "NOT EMPTY");
    this->view = std::make_unique<QQuickView>(this->qmlUrl);
    this->component = std::make_unique<QQmlComponent>(this->engine.get(), this->qmlUrl);
    this->object = std::unique_ptr<QObject>(component->create());
}

void CLQmlConnector::setQmlMainDisplayText(QString newText)
{
    QMetaObject::invokeMethod(this->object.get(), "setDisplayTextValue", Q_ARG(QVariant, QVariant(newText)));
}

void CLQmlConnector::setContextProperty(QString propertyName, QObject* propertyObject)
{
    this->engine->rootContext()->setContextProperty(propertyName, propertyObject);
}
