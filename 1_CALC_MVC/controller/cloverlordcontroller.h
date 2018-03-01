#ifndef CLOVERLORDCONTROLLER_H
#define CLOVERLORDCONTROLLER_H

#include <QObject>
#include <QQuickView>
#include <memory>
#include "model/cloperationfactory.h"
#include "view/clview.h"

class CLOverlordController: public QObject
{
  public:
    CLOverlordController(QObject* root, std::shared_ptr<QQuickView> view);

  private:
    std::shared_ptr<CLIArithmeticOperation> operation;
    std::shared_ptr<CLView> view;
};

#endif //CLOVERLORDCONTROLLER_H
