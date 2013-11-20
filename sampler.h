#ifndef SAMPLER_H
#define SAMPLER_H

#include "surface.h"

class Sampler
{
public:
    Sampler();
    virtual ~Sampler();

    void setSize(unsigned int width,
                 unsigned int height);

    virtual Surface *createSurface() const = 0;

protected:
    unsigned int m_width;
    unsigned int m_height;
};

#endif // SAMPLER_H
