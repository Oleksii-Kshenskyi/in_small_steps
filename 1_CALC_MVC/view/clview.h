#ifndef CLVIEW_H
#define CLVIEW_H

#include <QObject>
#include "view/clviewmodel.h"
#include "view/clqmlconnector.h"
#include <memory>

class CLView : public QObject
{
    Q_OBJECT
public:
    CLView(QObject* root, std::shared_ptr<QQuickView> mainView);
public slots:
    void setModelText(const QString& newText);
private:
    std::shared_ptr<CLViewModel> model;
    std::unique_ptr<CLQmlConnector> qmlConnector;
private slots:
    void setQmlText(const QString& newText);
    void changeModelTextForDelta(const QString& deltaText);
    void resetQmlDisplay();
    void eraseOne();
};

#endif // CLVIEW_H
