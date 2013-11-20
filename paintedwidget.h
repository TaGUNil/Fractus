#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <memory>
#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>
#include <QResizeEvent>

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintedWidget(QWidget *parent = 0);

    void setPixmap(QPixmap *pixmap);

private:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

    std::unique_ptr<QPixmap> m_pixmap;
};

#endif // PAINTEDWIDGET_H
