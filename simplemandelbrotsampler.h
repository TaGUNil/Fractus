#ifndef SIMPLEMANDELBROTSAMPLER_H
#define SIMPLEMANDELBROTSAMPLER_H

#include "fractalsampler.h"

class SimpleMandelbrotSampler : public FractalSampler
{
public:
    Surface *createSurface() const;
};

#endif // SIMPLEMANDELBROTSAMPLER_H
