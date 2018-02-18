#include "clbuilder.h"

CLTestBuilder::CLTestBuilder(QObject *root, std::shared_ptr<QQmlApplicationEngine> engine): QObject(root)
{
    ui = std::make_shared<CLView>(root, engine);
}
