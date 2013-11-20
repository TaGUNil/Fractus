#ifndef BINARYPAINTER_H
#define BINARYPAINTER_H

#include "painter.h"

class BinaryPainter : public Painter
{
public:
    Image *createImage(const Surface *surface) const;
};

#endif // BINARYPAINTER_H
