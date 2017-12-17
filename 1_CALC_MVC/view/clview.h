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
    CLView(QObject* root, std::shared_ptr<QQmlApplicationEngine>);
    void setDisplayText(QString newValue);
private:
    std::shared_ptr<CLViewModel> model;
    std::unique_ptr<CLQmlConnector> qmlConnector;

signals:

public slots:
};

#endif // CLVIEW_H
