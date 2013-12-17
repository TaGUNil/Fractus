#-------------------------------------------------
#
# Project created by QtCreator 2013-11-09T13:28:35
#
#-------------------------------------------------

QT       += core concurrent gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fractus
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11 -fopenmp
QMAKE_LFLAGS += -pthread -fopenmp

SOURCES += main.cpp\
        mainwindow.cpp \
    polynomialfunction.cpp \
    sampler.cpp \
    simplemandelbrotsampler.cpp \
    fractalsampler.cpp \
    simplejuliasampler.cpp \
    image.cpp \
    surface.cpp \
    binarypainter.cpp \
    paintedwidget.cpp \
    qtpixmapdumper.cpp \
    grayscalepainter.cpp \
    palettepainter.cpp \
    palette.cpp \
    rainbowpalettemaker.cpp

HEADERS  += mainwindow.h \
    function.h \
    polynomialfunction.h \
    sampler.h \
    simplemandelbrotsampler.h \
    fractalsampler.h \
    simplejuliasampler.h \
    image.h \
    types.h \
    surface.h \
    painter.h \
    binarypainter.h \
    dumper.h \
    paintedwidget.h \
    qtpixmapdumper.h \
    grayscalepainter.h \
    palettepainter.h \
    palette.h \
    palettemaker.h \
    rainbowpalettemaker.h

FORMS    += \
    mainwindow.ui
