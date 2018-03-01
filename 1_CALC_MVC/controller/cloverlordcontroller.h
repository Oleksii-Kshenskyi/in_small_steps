#ifndef CLOVERLORDCONTROLLER_H
#define CLOVERLORDCONTROLLER_H

#include <QObject>
#include <QQuickView>
#include <memory>
#include "model/cloperationfactory.h"

class CLOverlordController: public QObject
{
    CLOverlordController(QObject* root, std::shared_ptr<QQuickView> view, std::shared_ptr<CLOperationFactory> factory);
};

#endif //CLOVERLORDCONTROLLER_H
