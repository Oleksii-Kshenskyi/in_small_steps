#include "clview.h"
#include <QDebug>

CLView::CLView(QObject *root, std::shared_ptr<QQmlApplicationEngine> engine): QObject(root)
{
   this->model = std::make_shared<CLViewModel>(root);
   this->qmlConnector = std::make_unique<CLQmlConnector>(root, engine);
   this->qmlConnector->setContextProperty("ViewModel", this->model.get());
}
