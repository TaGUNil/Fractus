#include "fractalsampler.h"

FractalSampler::FractalSampler() :
    m_function(nullptr),
    m_bottomLeft(-1.0, -1.0),
    m_topRight(1.0, 1.0),
    m_limit(0.0),
    m_steps(0)
{
}

void FractalSampler::setFunction(PolynomialFunction *function)
{
    m_function.reset(function);
}

bool FractalSampler::setDomain(const Complex &bottomLeft,
                               const Complex &topRight)
{
    if (bottomLeft.real() >= topRight.real())
    {
        return false;
    }

    if (bottomLeft.imag() >= topRight.imag())
    {
        return false;
    }

    m_bottomLeft = bottomLeft;
    m_topRight = topRight;

    return true;
}

void FractalSampler::setLimit(const Real &limit)
{
    m_limit = limit;
}

void FractalSampler::setSteps(Level steps)
{
    m_steps = steps;
}
