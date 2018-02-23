#include "clview.h"
#include <QDebug>

CLView::CLView(QObject *root, std::shared_ptr<QQuickView> mainView): QObject(root)
{
   this->model = std::make_shared<CLViewModel>(root);
   this->qmlConnector = std::make_unique<CLQmlConnector>(root, mainView);

   QObject::connect(this->qmlConnector.get(), &CLQmlConnector::changeModelTextForDelta, this, &CLView::changeModelTextForDelta);
   QObject::connect(this->model.get(), &CLViewModel::displayValueChanged, this, &CLView::setQmlText);
}

void CLView::changeModelTextForDelta(const QString &deltaText)
{
    this->model->setDisplayValue(this->model->getDisplayValue() + deltaText);
}

void CLView::setQmlText(const QString& newText)
{
    this->qmlConnector->setQmlMainDisplayText(newText);
}
