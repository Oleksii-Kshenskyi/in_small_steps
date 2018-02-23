#ifndef CLQMLCONNECTOR_H
#define CLQMLCONNECTOR_H

#include <QQmlEngine>
#include <QQuickView>
#include <QQmlComponent>
#include <QQmlContext>
#include <memory>


class CLQmlConnector: public QObject
{
    Q_OBJECT
public:
    CLQmlConnector(QObject* root, std::shared_ptr<QQuickView> mainView);
    QString getQmlMainDisplayText();
public slots:
    void setQmlMainDisplayText(const QString& newText);
private:
    std::shared_ptr<QQuickView> mainView;
    std::shared_ptr<QQmlComponent> component;
    QObject* object;
    static const QUrl qmlUrl;
};

#endif // CLQMLCONNECTOR_H
