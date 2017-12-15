#include "clview.h"
#include <QDebug>

CLView::CLView()
{
   this->model = std::make_shared<CLViewModel>();
   this->qmlConnector = std::make_unique<CLQmlConnector>();
   this->qmlConnector->setContextProperty("ViewModel", this->model.get());
   connect(this->model.get(), &CLViewModel::displayValueChanged, this, &CLView::setDisplayText);
}

void CLView::setDisplayText(QString newValue)
{
    qDebug() << "New value is:" << newValue;
}
