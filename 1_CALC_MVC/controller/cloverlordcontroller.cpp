#include "cloverlordcontroller.h"

CLOverlordController::CLOverlordController(QObject* root, std::shared_ptr<QQuickView> view): view(std::make_shared<CLView>(root, view))
{

}
