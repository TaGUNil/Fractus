#include "simplejuliasampler.h"

Surface *SimpleJuliaSampler::createSurface() const
{
    Real squareLimit = m_limit * m_limit;
    Real xStep = (m_topRight.real() - m_bottomLeft.real()) / m_width;
    Real yStep = (m_topRight.imag() - m_bottomLeft.imag()) / m_height;

    Surface *surface = new Surface(m_width, m_height);
    if (!surface)
    {
        return nullptr;
    }

    surface->setMaxValue(m_steps + 1);

#pragma omp parallel for
    for (size_t y = 0; y < m_height; y++)
    {
        for (size_t x = 0; x < m_width; x++)
        {
            Real xPos = m_bottomLeft.real() + xStep * (x + 0.5);
            Real yPos = m_topRight.imag() - yStep * (y + 0.5);
            Complex z = Complex(xPos, yPos);
            Real zNorm = std::norm(z);

            if (zNorm >= squareLimit)
            {
                surface->setPoint(x, y, 0);
            }
            else if (m_function != nullptr)
            {
                for (Level i = 0; i < m_steps; i++)
                {
                    z = (*m_function)(z);
                    zNorm = std::norm(z);

                    if (zNorm >= squareLimit)
                    {
                        surface->setPoint(x, y, i + 1);
                        break;
                    }
                }
            }

            if (zNorm < squareLimit)
            {
                surface->setPoint(x, y, m_steps + 1);
            }
        }
    }

    return surface;
}
