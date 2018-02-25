#include "clqmlconnector.h"
#include <QQmlProperty>
#include <QCoreApplication>

const QUrl CLQmlConnector::qmlUrl = QUrl("qrc:/calcui/CalcForm.qml");

CLQmlConnector::CLQmlConnector(QObject *root, std::shared_ptr<QQuickView> mainView): QObject(root), mainView(mainView)
{    
    mainView->setSource(qmlUrl);
    mainView->show();
    this->object = (QObject*) mainView->rootObject();

    QObject::connect(this->object, SIGNAL(numberClicked(const QString&)), this, SIGNAL(changeModelTextForDelta(const QString&)));
    QObject::connect(this->object, SIGNAL(offClicked()), qApp, SLOT(quit()));

}

void CLQmlConnector::setQmlMainDisplayText(const QString& newText)
{
    QMetaObject::invokeMethod(this->object, "setDisplayText", Q_ARG(QVariant, newText));
}

QString CLQmlConnector::getQmlMainDisplayText()
{
    QVariant displayText;
    QMetaObject::invokeMethod(this->object, "getDisplayText", Q_RETURN_ARG(QVariant, displayText));

    return displayText.toString();
}

int CLQmlConnector::getQmlMainDisplayLength()
{
    return QQmlProperty(this->object, "mainDisplayLength").read().toInt();
}
