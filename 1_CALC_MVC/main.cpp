#include "clbuilder.h"
#include <QQuickView>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    std::shared_ptr<QQuickView> mainView = std::make_shared<QQuickView>();

    CLTestBuilder clbBuilder(&app, mainView); Q_UNUSED(clbBuilder);

    mainView->setMaximumHeight(mainView->height());
    mainView->setMaximumWidth(mainView->width());
    mainView->setMinimumHeight(mainView->height());
    mainView->setMinimumWidth(mainView->width());

    return app.exec();
}
