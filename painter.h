#ifndef PAINTER_H
#define PAINTER_H

#include "surface.h"
#include "image.h"

class Painter
{
public:
    virtual ~Painter()
    {
    }

    virtual Image *createImageFromSurface(const Surface *surface) const = 0;
};

#endif // PAINTER_H
