#include <QImage>
#include "qtpixmapdumper.h"

QtPixmapDumper::QtPixmapDumper(QPixmap *pixmap) :
    m_pixmap(pixmap)
{
}

bool QtPixmapDumper::dumpImage(const Image *image) const
{
    if (!image)
    {
        return false;
    }

    if (!m_pixmap)
    {
        return false;
    }

    QImage qImage((const uchar *)(image->getRawPoints()),
                  image->getWidth(),
                  image->getHeight(),
                  QImage::Format_ARGB32);

    m_pixmap->convertFromImage(qImage);

    return true;
}
