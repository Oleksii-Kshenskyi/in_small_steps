#ifndef CLOVERLORDCONTROLLER_H
#define CLOVERLORDCONTROLLER_H

#include <QObject>
#include <QQuickView>
#include <memory>
#include "model/cloperationfactory.h"
#include "view/clview.h"

class CLOverlordController: public QObject
{
    Q_OBJECT
  public:
    CLOverlordController(QObject* root, std::shared_ptr<QQuickView> view);

  private slots:
    void createOperation(const QString& operation);
    void processOperation();
    void clearEntry();

  private:
    std::shared_ptr<CLIArithmeticOperation> operation;
    std::shared_ptr<CLView> view;
    std::shared_ptr<CLOperationFactory> factory;
};

#endif //CLOVERLORDCONTROLLER_H
