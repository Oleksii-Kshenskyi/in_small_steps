#include "clqmlconnector.h"
#include <QQmlProperty>

const QUrl CLQmlConnector::qmlUrl = QUrl("qrc:/calcui/CalcForm.qml");

CLQmlConnector::CLQmlConnector(QObject *root, std::shared_ptr<QQuickView> mainView): QObject(root), mainView(mainView)
{    
    mainView->setSource(qmlUrl);
    mainView->show();
    this->object = (QObject*) mainView->rootObject();

    QObject::connect(this->object, SIGNAL(numberClicked(const QString&)), this, SLOT(setQmlMainDisplayText(const QString&)));

}

void CLQmlConnector::setQmlMainDisplayText(const QString& newText)
{
    qDebug() << "\nprop:" << QQmlProperty(this->object, "mainDisplayText").read().toString();
}
