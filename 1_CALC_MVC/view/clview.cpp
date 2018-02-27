#include "clview.h"
#include <QDebug>

CLView::CLView(QObject *root, std::shared_ptr<QQuickView> mainView): QObject(root)
{
   this->model = std::make_shared<CLViewModel>(root);
   this->qmlConnector = std::make_unique<CLQmlConnector>(root, mainView);

   QObject::connect(this->qmlConnector.get(), &CLQmlConnector::changeModelTextForDelta, this, &CLView::changeModelTextForDelta);
   QObject::connect(this->model.get(), &CLViewModel::displayValueChanged, this, &CLView::setQmlText);
   QObject::connect(this->qmlConnector.get(), &CLQmlConnector::resetQmlMainDisplay, this, &CLView::resetQmlDisplay);
   QObject::connect(this->qmlConnector.get(), &CLQmlConnector::eraseOne, this, &CLView::eraseOne);
}

/**
 * @brief CLView::changeModelTextForDelta(const QString&) changes display text according to the number pressed.
 * The function restricts user input to 13 numbers, becauase maximum display length is 26 (in case of
 * multiplication the number's length may double). Also it appends the string with the number, but
 * if number is 0, it substitutes this 0 with the number instead (to avoid numbers like 038).
 * @param deltaText - the delta (appending number) string that has to be attached to the display.
 */
void CLView::changeModelTextForDelta(const QString &deltaText)
{
    if( (this->model->getDisplaySize() + deltaText.size()) <= (this->qmlConnector->getQmlMainDisplayLength() / 2))
      this->model->setDisplayValue( (this->model->getDisplayValue() == "0") ? deltaText : this->model->getDisplayValue() + deltaText);
}

void CLView::setQmlText(const QString& newText)
{
    this->qmlConnector->setQmlMainDisplayText(newText);
}

void CLView::resetQmlDisplay()
{
    this->model->setDisplayValue("0");
}

void CLView::eraseOne()
{
    if(this->model->getDisplaySize() != 1)
        this->model->eraseOne();
    else
        this->model->setDisplayValue("0");
}
