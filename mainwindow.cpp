#include <QStatusBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QtConcurrent>
#include "simplemandelbrotsampler.h"
#include "simplejuliasampler.h"
#include "binarypainter.h"
#include "grayscalepainter.h"
#include "palettepainter.h"
#include "qtpixmapdumper.h"
#include "polynomialfunction.h"
#include "rainbowpalettemaker.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Q_DECLARE_METATYPE(std::shared_ptr<PaletteMaker>)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_timer(0),
    m_watcher(nullptr),
    m_sampler(nullptr),
    m_painter(nullptr),
    m_image(nullptr),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    std::shared_ptr<PaletteMaker> rainbow;
    rainbow.reset(new RainbowPaletteMaker);

    m_ui->paletteComboBox->addItem(tr("Rainbow"),
                                   QVariant::fromValue(rainbow));

    m_ui->paletteComboBox->setCurrentIndex(0);

    connect(m_ui->centralwidget, &PaintedWidget::resized,
            this, &MainWindow::refresh);
}

MainWindow::~MainWindow()
{
}

void MainWindow::refresh()
{
    if (m_timer != 0)
    {
        killTimer(m_timer);
        m_timer = 0;
    }

    m_watcher.reset();

    if (m_image.get())
    {
        display();
    }
}

void MainWindow::display()
{
    m_ui->statusbar->showMessage(tr("Drawing..."));

    m_ui->action_Save->setEnabled(false);

    m_ui->drawButton->setEnabled(false);

    m_ui->centralwidget->setPixmap(nullptr);
    m_ui->centralwidget->update();

    if (m_ui->mandelbrotRadioButton->isChecked())
    {
        m_sampler.reset(new SimpleMandelbrotSampler);
    }
    else if (m_ui->juliaRadioButton->isChecked())
    {
        m_sampler.reset(new SimpleJuliaSampler);
    }
    else
    {
        return;
    }

    m_sampler->setSize(m_ui->centralwidget->width(),
                       m_ui->centralwidget->height());

    PolynomialFunction *function = new PolynomialFunction(6);
    function->setCoeff(0,
                       m_ui->a0RealSpinBox->value(),
                       m_ui->a0ImagSpinBox->value());
    function->setCoeff(1,
                       m_ui->a1RealSpinBox->value(),
                       m_ui->a1ImagSpinBox->value());
    function->setCoeff(2,
                       m_ui->a2RealSpinBox->value(),
                       m_ui->a2ImagSpinBox->value());
    function->setCoeff(3,
                       m_ui->a3RealSpinBox->value(),
                       m_ui->a3ImagSpinBox->value());
    function->setCoeff(4,
                       m_ui->a4RealSpinBox->value(),
                       m_ui->a4ImagSpinBox->value());
    function->setCoeff(5,
                       m_ui->a5RealSpinBox->value(),
                       m_ui->a5ImagSpinBox->value());

    m_sampler->setFunction(function);

    Complex fovCenter = Complex(m_ui->xFovSpinBox->value(),
                                m_ui->yFovSpinBox->value());
    Real fovHeight = m_ui->sizeFovSpinBox->value() / 2;
    Real fovWidth = fovHeight *
            m_ui->centralwidget->width() /
            m_ui->centralwidget->height();

    m_sampler->setDomain(fovCenter - Complex(fovWidth, fovHeight),
                         fovCenter + Complex(fovWidth, fovHeight));

    m_sampler->setLimit(m_ui->limitSpinBox->value());

    m_sampler->setSteps(m_ui->stepsSpinBox->value());

    if (m_ui->binaryRadioButton->isChecked())
    {
        m_painter.reset(new BinaryPainter);
    }
    else if (m_ui->grayscaleRadioButton->isChecked())
    {
        m_painter.reset(new GrayscalePainter);
    }
    else if (m_ui->paletteRadioButton->isChecked())
    {
        int index = m_ui->paletteComboBox->currentIndex();
        const QVariant &data = m_ui->paletteComboBox->itemData(index);
        PaletteMaker *maker;
        maker = data.value<std::shared_ptr<PaletteMaker> >().get();

        m_painter.reset(new PalettePainter(maker->createPalette()));
    }
    else
    {
        return;
    }

    m_timer = startTimer(500);
}

void MainWindow::finalize()
{
    m_image.reset(m_watcher->result());

    QPixmap *pixmap = new QPixmap(m_ui->centralwidget->width(),
                                  m_ui->centralwidget->height());

    std::unique_ptr<QtPixmapDumper> dumper;
    dumper.reset(new QtPixmapDumper(pixmap));

    dumper->dumpImage(m_image.get());

    m_ui->centralwidget->setPixmap(pixmap);
    m_ui->centralwidget->update();

    m_ui->drawButton->setEnabled(true);

    m_ui->action_Save->setEnabled(true);

    m_ui->statusbar->showMessage("Done!");
}

void MainWindow::save()
{
    QString fileName;
    QString filter = tr("PNG images (*.png)");
    fileName = QFileDialog::getSaveFileName(this,
                                            tr("Save image"),
                                            "",
                                            filter,
                                            &filter);

    if (fileName.isEmpty())
    {
        return;
    }

    QPixmap pixmap;

    std::unique_ptr<QtPixmapDumper> dumper;
    dumper.reset(new QtPixmapDumper(&pixmap));

    dumper->dumpImage(m_image.get());

    if (!pixmap.save(fileName, "png", 100))
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Cannot save image file!"));
    }
}

Image *MainWindow::draw()
{
    std::shared_ptr<FractalSampler> sampler;
    std::shared_ptr<Painter> painter;
    std::unique_ptr<Surface> surface;

    sampler = m_sampler;
    painter = m_painter;

    surface.reset(sampler->createSurface());

    return painter->createImage(surface.get());
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)

    killTimer(m_timer);
    m_timer = 0;

    m_watcher.reset(new QFutureWatcher<Image *>);

    connect(m_watcher.get(), &QFutureWatcher<Image *>::finished,
            this, &MainWindow::finalize);

    m_watcher->setFuture(QtConcurrent::run(this, &MainWindow::draw));
}
