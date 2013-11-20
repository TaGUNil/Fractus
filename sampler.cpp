#include "sampler.h"

Sampler::Sampler() :
    m_width(0),
    m_height(0)
{
}

Sampler::~Sampler()
{
}

void Sampler::setSize(unsigned int width,
                      unsigned int height)
{
    m_width = width;
    m_height = height;
}
