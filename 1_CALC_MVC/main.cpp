#include "clbuilder.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    std::shared_ptr<QQmlEngine> engine = std::make_shared<QQmlEngine>();

    CLTestBuilder clbBuilder(&app, engine); Q_UNUSED(clbBuilder);

    return app.exec();
}
