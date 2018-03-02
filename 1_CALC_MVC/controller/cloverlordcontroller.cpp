#include "cloverlordcontroller.h"

CLOverlordController::CLOverlordController(QObject* root, std::shared_ptr<QQuickView> view): view(std::make_shared<CLView>(root, view))
{
    this->factory = std::make_shared<CLOperationFactory>(std::make_shared<CLModel>());
    QObject::connect(this->view.get(), &CLView::operationClicked, this, &CLOverlordController::createOperation);
}

void CLOverlordController::createOperation(const QString& operation)
{
    this->operation = this->factory->create(operation);
}
