#include "clview.h"
#include <QDebug>

CLView::CLView(QObject *root, std::shared_ptr<QQuickView> mainView): QObject(root), clearNext(false)
{
   this->model = std::make_shared<CLViewModel>(root);
   this->qmlConnector = std::make_unique<CLQmlConnector>(root, mainView);

   this->lastPress.push(CLButtonType::Nothing);
   this->lastPress.push(CLButtonType::Nothing);

   QObject::connect(this->qmlConnector.get(), &CLQmlConnector::changeModelTextForDelta, this, &CLView::changeModelTextForDelta);
   QObject::connect(this->model.get(), &CLViewModel::displayValueChanged, this, &CLView::setQmlText);
   QObject::connect(this->qmlConnector.get(), &CLQmlConnector::resetQmlMainDisplay, this, &CLView::resetQmlDisplay);
   QObject::connect(this->qmlConnector.get(), &CLQmlConnector::eraseOne, this, &CLView::eraseOne);
   QObject::connect(this->qmlConnector.get(), &CLQmlConnector::operationClicked, this, &CLView::operationClicked);
   QObject::connect(this->qmlConnector.get(), &CLQmlConnector::equalsSignClicked, this, &CLView::equalsSignClicked);

   QObject::connect(this, &CLView::lastPressChanged, this, &CLView::setLastPress);
   QObject::connect(this, &CLView::equalsSignClicked, this, &CLView::setLastPressToEquals);
   QObject::connect(this, &CLView::operationClicked, this, &CLView::setLastPressToOperation);
}

void CLView::setLastPress(const CLButtonType& lastPress)
{
    this->lastPress.push(lastPress);
}

const CLButtonType& CLView::getLastPress()
{
    return this->lastPress.front();
}

void CLView::setLastPressToEquals()
{
    emit this->lastPressChanged(CLButtonType::Equals);
}

void CLView::setLastPressToOperation()
{
    emit this->lastPressChanged(CLButtonType::Operation);
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
      this->model->setDisplayValue( ((this->model->getDisplayValue() == "0") || this->clearNext) ? deltaText : this->model->getDisplayValue() + deltaText);

    this->clearNext = false;

    emit this->lastPressChanged(CLButtonType::Number);
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

void CLView::setModelText(const QString& newText)
{
    this->model->setDisplayValue(newText);
}

QString CLView::getModelText()
{
    return this->model->getDisplayValue();
}

void CLView::clearLater()
{
    this->clearNext = true;
}
