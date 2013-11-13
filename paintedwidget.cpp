#include <QPainter>
#include "paintedwidget.h"

PaintedWidget::PaintedWidget(QWidget *parent) :
    QWidget(parent),
    m_pixmap(nullptr)
{
}

void PaintedWidget::setPixmap(QPixmap *pixmap)
{
    m_pixmap.reset(pixmap);
}

void PaintedWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    if (!m_pixmap.get())
    {
        m_pixmap.reset(new QPixmap(this->width(), this->height()));
        m_pixmap->fill();
    }

    QPainter painter(this);
    painter.drawPixmap(0, 0, *m_pixmap);
}
