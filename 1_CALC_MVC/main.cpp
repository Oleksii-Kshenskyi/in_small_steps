#include "clbuilder.h"
#include <QQuickView>
#include "controller/cloverlordcontroller.h"
#include "model/cloperationfactory.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    std::shared_ptr<QQuickView> mainView = std::make_shared<QQuickView>();

    CLOverlordController controller(&app, mainView);

    mainView->setMaximumHeight(mainView->height());
    mainView->setMaximumWidth(mainView->width());
    mainView->setMinimumHeight(mainView->height());
    mainView->setMinimumWidth(mainView->width());

    return app.exec();
}
