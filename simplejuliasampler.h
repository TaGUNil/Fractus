#ifndef SIMPLEJULIASAMPLER_H
#define SIMPLEJULIASAMPLER_H

#include "fractalsampler.h"

class SimpleJuliaSampler : public FractalSampler
{
public:
    Surface *createSurface() const;
};

#endif // SIMPLEJULIASAMPLER_H
