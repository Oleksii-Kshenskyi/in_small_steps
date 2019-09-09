#ifndef CLVIEW_H
#define CLVIEW_H

#include <QObject>
#include "view/clviewmodel.h"
#include "view/clqmlconnector.h"
#include <memory>
#include "view/clbuttontype.h"
#include "view/clfixedqueue.h"

class CLView : public QObject
{
    Q_OBJECT
public:
    CLView(QObject* root, std::shared_ptr<QQuickView> mainView);
    QString getModelText();
    void clearLater();
    const CLButtonType& getLastPress();
signals:
    void operationClicked(const QString& operation);
    void equalsSignClicked();
    void lastPressChanged(const CLButtonType& lastPress);
public slots:
    void setModelText(const QString& newText);

    void setLastPress(const CLButtonType& lastPress);
    void setLastPressToEquals();
    void setLastPressToOperation();
private:
    std::shared_ptr<CLViewModel> model;
    std::unique_ptr<CLQmlConnector> qmlConnector;
    bool clearNext;
    CLFixedQueue<CLButtonType, 2> lastPress;
private slots:
    void setQmlText(const QString& newText);
    void changeModelTextForDelta(const QString& deltaText);
    void clearEntry();
    void eraseOne();
};

#endif // CLVIEW_H
