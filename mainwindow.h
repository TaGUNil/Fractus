#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include <QFutureWatcher>
#include <QTimerEvent>
#include "fractalsampler.h"
#include "painter.h"
#include "surface.h"
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
    void refresh();
    void display();
    void finalize();
    void save();
    Image *draw();

private:
    void timerEvent(QTimerEvent *event);

    int m_timer;
    std::unique_ptr<QFutureWatcher<Image *> > m_watcher;
    std::shared_ptr<FractalSampler> m_sampler;
    std::shared_ptr<Painter> m_painter;
    std::unique_ptr<Image> m_image;
    std::unique_ptr<Ui::MainWindow> m_ui;
};

#endif // MAINWINDOW_H
