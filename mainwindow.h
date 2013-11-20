#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include <QPixmap>
#include <QResizeEvent>
#include "image.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void display();
    void save();

private:
    void draw();
    void resizeEvent(QResizeEvent *event);

    std::unique_ptr<Image> m_image;
    std::unique_ptr<Ui::MainWindow> m_ui;
};

#endif // MAINWINDOW_H
