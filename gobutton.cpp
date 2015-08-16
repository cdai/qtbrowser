#include "gobutton.h"

GoButton::GoButton(QObject *parent) :
    QPushButton(parent)
{
}

GoButton::mousePressEvent(QMouseEvent *e)
{
    emit clicked();
}
