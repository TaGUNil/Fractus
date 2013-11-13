#ifndef QTPIXMAPDUMPER_H
#define QTPIXMAPDUMPER_H

#include <QPixmap>
#include "dumper.h"

class QtPixmapDumper : public Dumper
{
public:
    QtPixmapDumper(QPixmap *pixmap);

    bool dumpImage(const Image *image) const;

private:
    QPixmap *m_pixmap;
};

#endif // QTPIXMAPDUMPER_H
