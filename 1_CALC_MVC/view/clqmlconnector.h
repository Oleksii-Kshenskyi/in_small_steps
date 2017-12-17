#ifndef CLQMLCONNECTOR_H
#define CLQMLCONNECTOR_H

#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlComponent>
#include <QQmlContext>
#include <memory>


class CLQmlConnector: public QObject
{
public:
    CLQmlConnector(QObject* root, std::shared_ptr<QQmlApplicationEngine> engine);
    void setQmlMainDisplayText(QString newText);
    void setContextProperty(QString propertyName, QObject* propertyObject);
private:
    std::shared_ptr<QQmlApplicationEngine> engine;
    std::unique_ptr<QQuickView> view;
    std::unique_ptr<QQmlComponent> component;
    std::unique_ptr<QObject> object;
    static const QUrl qmlUrl;
};

#endif // CLQMLCONNECTOR_H
