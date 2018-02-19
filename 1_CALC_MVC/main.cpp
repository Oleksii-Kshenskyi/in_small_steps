#include "clbuilder.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    std::shared_ptr<QQmlApplicationEngine> engine = std::make_shared<QQmlApplicationEngine>();
    engine->load(QUrl(QLatin1String("qrc:/calcui/main.qml")));
    CLTestBuilder clbBuilder(&app, engine); Q_UNUSED(clbBuilder);

    if (engine->rootObjects().isEmpty())
        return -1;

    return app.exec();
}
