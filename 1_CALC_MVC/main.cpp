#include "clbuilder.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    CLTestBuilder clbBuilder;
    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/calcui/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    engine.rootContext()->setContextProperty("testCalculator", &clbBuilder);
    clbBuilder.testSetOperationInModel();
    return app.exec();
}
