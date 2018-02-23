#include "clbuilder.h"

CLTestBuilder::CLTestBuilder(QObject *root, std::shared_ptr<QQuickView> mainView): QObject(root)
{
    ui = std::make_shared<CLView>(root, mainView);
}
