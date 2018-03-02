#include "cloverlordcontroller.h"

CLOverlordController::CLOverlordController(QObject* root, std::shared_ptr<QQuickView> view): view(std::make_shared<CLView>(root, view)),
                                                                                             factory(std::make_shared<CLOperationFactory>(std::make_shared<CLModel>()))
{
    QObject::connect(this->view.get(), &CLView::operationClicked, this, &CLOverlordController::createOperation);
    QObject::connect(this->view.get(), &CLView::equalsSignClicked, this, &CLOverlordController::processOperation);

}

void CLOverlordController::createOperation(const QString& operation)
{
    this->operation = this->factory->create(operation);
    this->operation->setFirst(this->view->getModelText());

    this->view->clearLater();
}

void CLOverlordController::processOperation()
{
    if(this->operation)
    {
        this->operation->setSecond(this->view->getModelText());
        this->operation->execute();
        this->view->setModelText(this->operation->getResult());

        this->view->clearLater();
    }
}
