#include "cloverlordcontroller.h"

CLOverlordController::CLOverlordController(QObject* root, std::shared_ptr<QQuickView> view): view(std::make_shared<CLView>(root, view)),
                                                                                             factory(std::make_shared<CLOperationFactory>(std::make_shared<CLModel>()))
{
    QObject::connect(this->view.get(), &CLView::operationClicked, this, &CLOverlordController::createOperation);
    QObject::connect(this->view.get(), &CLView::equalsSignClicked, this, &CLOverlordController::processOperation);
    QObject::connect(this->view.get(), &CLView::clearEntryClicked, this, &CLOverlordController::clearEntry);
    QObject::connect(this->view.get(), &CLView::clearAllClicked, this, &CLOverlordController::clearAll);
}

void CLOverlordController::createOperation(const QString& operation)
{
    if(this->operation && this->view->getPreviousPress() == CLButtonType::Number)
        this->processOperation();

    this->operation = this->factory->create(operation);
    this->operation->setResult(this->view->getModelText());

    this->view->clearLater();
}

void CLOverlordController::processOperation()
{
    if(this->operation)
    {
        if(this->view->getPreviousPress() == CLButtonType::Number || this->view->getPreviousPress() == CLButtonType::Operation)
            this->operation->setDelta(this->view->getModelText());

        this->operation->execute();
        this->view->setModelText(this->operation->getResult());

        this->view->clearLater();
    }
}

void CLOverlordController::clearEntry()
{
    this->view->setModelText("0");

    if(this->view->getLastPress() == CLButtonType::Equals)
        this->operation->setResult("0");
}

void CLOverlordController::clearAll()
{
    this->operation.reset();
    this->view->setModelText("0");
    this->view->setLastPress(CLButtonType::Nothing);
}
