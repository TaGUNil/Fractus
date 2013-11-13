#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include <QPixmap>
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

    std::unique_ptr<Image> m_image;
    std::unique_ptr<Ui::MainWindow> m_ui;
};

#endif // MAINWINDOW_H
