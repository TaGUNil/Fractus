#include "surface.h"

Surface::Surface(size_t width,
                 size_t height) :
    m_width(width),
    m_height(height),
    m_maxValue(0),
    m_points(width * height, 0)
{
}

size_t Surface::getWidth() const
{
    return m_width;
}

size_t Surface::getHeight() const
{
    return m_height;
}

Level Surface::getMaxValue() const
{
    return m_maxValue;
}

void Surface::setMaxValue(Level value)
{
    m_maxValue = value;
}

Level Surface::getPoint(size_t x,
                        size_t y) const
{
    if ((x >= m_width) || (y >= m_height))
    {
        return 0;
    }

    return m_points[y * m_width + x];
}

bool Surface::setPoint(size_t x,
                       size_t y,
                       Level value)
{
    if ((x >= m_width) || (y >= m_height))
    {
        return false;
    }

    m_points[y * m_width + x] = value;

    return true;
}

const Level *Surface::getRawPoints() const
{
    return m_points.data();
}

Level *Surface::getRawPoints()
{
    return m_points.data();
}
