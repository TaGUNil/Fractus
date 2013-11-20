#ifndef GRAYSCALEPAINTER_H
#define GRAYSCALEPAINTER_H

#include "painter.h"

class GrayscalePainter : public Painter
{
public:
    Image *createImage(const Surface *surface) const;
};

#endif // GRAYSCALEPAINTER_H
