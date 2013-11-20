#include "image.h"

Image::Image(unsigned int width,
             unsigned int height) :
    m_width(width),
    m_height(height),
    m_points(width * height, 0)
{
}

unsigned int Image::getWidth() const
{
    return m_width;
}

unsigned int Image::getHeight() const
{
    return m_height;
}

Color Image::getPoint(unsigned int x,
                      unsigned int y) const
{
    if ((x >= m_width) || (y >= m_height))
    {
        return 0;
    }

    return m_points[y * m_width + x];
}

bool Image::setPoint(unsigned int x,
                     unsigned int y,
                     Color value)
{
    if ((x >= m_width) || (y >= m_height))
    {
        return false;
    }

    m_points[y * m_width + x] = value;

    return true;
}

const Color *Image::getRawPoints() const
{
    return m_points.data();
}

Color *Image::getRawPoints()
{
    return m_points.data();
}
