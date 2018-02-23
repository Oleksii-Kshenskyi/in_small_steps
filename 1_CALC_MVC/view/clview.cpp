#include "clview.h"
#include <QDebug>

CLView::CLView(QObject *root, std::shared_ptr<QQuickView> mainView): QObject(root)
{
   this->model = std::make_shared<CLViewModel>(root);
   this->qmlConnector = std::make_unique<CLQmlConnector>(root, mainView);
}

void CLView::setQmlText(const QString& newText)
{
    this->qmlConnector->setQmlMainDisplayText(newText);
}
