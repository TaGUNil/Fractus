#include <QPainter>
#include "paintedwidget.h"

PaintedWidget::PaintedWidget(QWidget *parent) :
    QWidget(parent),
    m_frontPixmap(nullptr),
    m_backPixmap(nullptr)
{
}

void PaintedWidget::setPixmap(QPixmap *pixmap)
{
    m_frontPixmap.reset(pixmap);
}

void PaintedWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPixmap *pixmap = m_frontPixmap.get();

    if (!pixmap)
    {
        pixmap = m_backPixmap.get();

        if (!pixmap)
        {
            pixmap = new QPixmap(this->width(), this->height());

            pixmap->fill();

            m_backPixmap.reset(pixmap);
        }
    }

    QPainter painter(this);

    painter.drawPixmap(0, 0, *pixmap);
}

void PaintedWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    m_backPixmap.reset();

    emit resized();
}
