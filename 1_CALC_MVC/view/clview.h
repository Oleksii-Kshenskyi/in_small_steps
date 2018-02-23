#ifndef CLVIEW_H
#define CLVIEW_H

#include <QObject>
#include "view/clviewvodel.h"
#include "view/clqmlconnector.h"
#include <memory>

class CLView : public QObject
{
    Q_OBJECT
public:
    CLView(QObject* root, std::shared_ptr<QQuickView> mainView);
public slots:
    Q_INVOKABLE void setQmlText(const QString& newText);
private:
    std::shared_ptr<CLViewModel> model;
    std::unique_ptr<CLQmlConnector> qmlConnector;
private slots:
    void changeModelTextForDelta(const QString& deltaText);
};

#endif // CLVIEW_H
