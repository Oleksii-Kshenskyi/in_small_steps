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
    QObject::connect(this->object, SIGNAL(clearEntryClicked()), this, SIGNAL(clearEntryClicked()));
    QObject::connect(this->object, SIGNAL(clearAllClicked()), this, SIGNAL(clearAllClicked()));
    QObject::connect(this->object, SIGNAL(eraseOneClicked()), this, SIGNAL(eraseOne()));
    QObject::connect(this->object, SIGNAL(operationClicked(const QString&)), this, SIGNAL(operationClicked(const QString&)));
    QObject::connect(this->object, SIGNAL(equalsSignClicked()), this, SIGNAL(equalsSignClicked()));
    QObject::connect(this->object, SIGNAL(dotClicked()), this, SIGNAL(dotClicked()));
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
