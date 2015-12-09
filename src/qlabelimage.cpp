#include "qlabelimage.h"



QLabelImage::QLabelImage(QWidget *parent) :
    QLabel(parent)
{

}


QLabelImage::~QLabelImage()
{

}

void QLabelImage::mouseMoveEvent(QMouseEvent *ev)
{
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pos();
}

void QLabelImage::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}

void QLabelImage::leaveEvent(QEvent *)
{
    emit Mouse_ClickLeft();
}

void QLabelImage::mouseReleaseEvent(QMouseEvent *ev)
{
    this->xr = ev->x();
    this->yr = ev->y();
    emit Mouse_ReleasePos();
}
