#ifndef CLQMLCONNECTOR_H
#define CLQMLCONNECTOR_H

#include <QQmlEngine>
#include <QQuickView>
#include <QQmlComponent>
#include <QQmlContext>
#include <memory>


class CLQmlConnector: public QObject
{
public:
    CLQmlConnector(QObject* root, std::shared_ptr<QQmlEngine> engine);
    void setQmlMainDisplayText(QString newText);
private:
    std::shared_ptr<QQmlEngine> engine;
    std::shared_ptr<QQmlComponent> component;
    std::shared_ptr<QObject> object;
    static const QUrl qmlUrl;
};

#endif // CLQMLCONNECTOR_H
