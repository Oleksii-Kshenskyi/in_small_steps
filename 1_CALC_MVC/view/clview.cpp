#include "clview.h"
#include <QDebug>

CLView::CLView(QObject *root, std::shared_ptr<QQmlEngine> engine): QObject(root)
{
   this->model = std::make_shared<CLViewModel>(root);
   this->qmlConnector = std::make_unique<CLQmlConnector>(root, engine);
}

void CLView::setQmlText(const QString& newText)
{
    this->qmlConnector->setQmlMainDisplayText(newText);
}
