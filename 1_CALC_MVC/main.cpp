#include "clbuilder.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    CLTestBuilder clbBuilder(&app, std::shared_ptr<QQmlApplicationEngine>(&engine));

    engine.load(QUrl(QLatin1String("qrc:/calcui/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    engine.rootContext()->setContextProperty("testCalculator", &clbBuilder);
    //engine.load(QUrl(QLatin1String("qrc:/calcui/CalcForm.qml")));
    //engine.rootContext()->setContextProperty("ViewModel", clbBuilder.getView()->getModel().get());
    clbBuilder.testSetOperationInModel();
    return app.exec();
}
