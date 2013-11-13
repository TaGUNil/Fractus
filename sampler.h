#ifndef SAMPLER_H
#define SAMPLER_H

#include <stddef.h>
#include "surface.h"

class Sampler
{
public:
    Sampler();
    virtual ~Sampler();

    void setSize(size_t width,
                 size_t height);

    virtual Surface *createSurface() const = 0;

protected:
    size_t m_width;
    size_t m_height;
};

#endif // SAMPLER_H
