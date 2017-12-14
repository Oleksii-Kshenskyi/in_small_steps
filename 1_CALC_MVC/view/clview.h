#ifndef CLVIEW_H
#define CLVIEW_H

#include <QObject>
#include "view/clviewvodel.h"
#include <memory>

class CLView : public QObject
{
    Q_OBJECT
public:
    CLView();
private:
    std::shared_ptr<CLViewModel> model;

signals:

public slots:
};

#endif // CLVIEW_H
