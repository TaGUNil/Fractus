#include <QStatusBar>
#include <QFileDialog>
#include <QMessageBox>
#include "simplemandelbrotsampler.h"
#include "simplejuliasampler.h"
#include "binarypainter.h"
#include "qtpixmapdumper.h"
#include "polynomialfunction.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::display()
{
    m_ui->statusbar->showMessage(tr("Drawing..."));

    draw();

    QPixmap *pixmap = new QPixmap(m_ui->centralwidget->width(),
                                  m_ui->centralwidget->height());

    std::unique_ptr<QtPixmapDumper> dumper;
    dumper.reset(new QtPixmapDumper(pixmap));

    dumper->dumpImage(m_image.get());

    m_ui->centralwidget->setPixmap(pixmap);
    m_ui->centralwidget->update();

    m_ui->action_Save->setEnabled(true);

    m_ui->statusbar->showMessage("Done!");
}

void MainWindow::save()
{
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this,
                                            tr("Save image"),
                                            "",
                                            tr("Images (*.png)"));

    if (fileName.isEmpty())
    {
        return;
    }

    QPixmap pixmap;

    std::unique_ptr<QtPixmapDumper> dumper;
    dumper.reset(new QtPixmapDumper(&pixmap));

    dumper->dumpImage(m_image.get());

    if (!pixmap.save(fileName, 0, 100))
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Cannot save image file!"));
    }
}

void MainWindow::draw()
{
    std::unique_ptr<FractalSampler> sampler;

    if (m_ui->mandelbrotRadioButton->isChecked())
    {
        sampler.reset(new SimpleMandelbrotSampler);
    }
    else if (m_ui->juliaRadioButton->isChecked())
    {
        sampler.reset(new SimpleJuliaSampler);
    }
    else
    {
        return;
    }

    sampler->setSize(m_ui->centralwidget->width(),
                     m_ui->centralwidget->height());

    PolynomialFunction *function = new PolynomialFunction(6);
    function->setCoeff(0,
                       m_ui->a0RealSpinBox->text().toDouble(),
                       m_ui->a0ImagSpinBox->text().toDouble());
    function->setCoeff(1,
                       m_ui->a1RealSpinBox->text().toDouble(),
                       m_ui->a1ImagSpinBox->text().toDouble());
    function->setCoeff(2,
                       m_ui->a2RealSpinBox->text().toDouble(),
                       m_ui->a2ImagSpinBox->text().toDouble());
    function->setCoeff(3,
                       m_ui->a3RealSpinBox->text().toDouble(),
                       m_ui->a3ImagSpinBox->text().toDouble());
    function->setCoeff(4,
                       m_ui->a4RealSpinBox->text().toDouble(),
                       m_ui->a4ImagSpinBox->text().toDouble());
    function->setCoeff(5,
                       m_ui->a5RealSpinBox->text().toDouble(),
                       m_ui->a5ImagSpinBox->text().toDouble());

    sampler->setFunction(function);

    Complex fovCenter = Complex(m_ui->xFovSpinBox->text().toDouble(),
                                m_ui->yFovSpinBox->text().toDouble());
    Real fovSize = m_ui->sizeFovSpinBox->text().toDouble() / 2;

    sampler->setDomain(fovCenter - Complex(fovSize, fovSize),
                       fovCenter + Complex(fovSize, fovSize));

    sampler->setLimit(m_ui->limitSpinBox->text().toDouble());
    sampler->setSteps(m_ui->stepsSpinBox->text().toUInt());

    std::unique_ptr<Painter> painter;
    painter.reset(new BinaryPainter);

    std::unique_ptr<Surface> surface;
    surface.reset(sampler->createSurface());

    m_image.reset(painter->createImageFromSurface(surface.get()));
}
