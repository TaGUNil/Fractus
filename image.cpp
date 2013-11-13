#include "image.h"

Image::Image(size_t width,
             size_t height) :
    m_width(width),
    m_height(height),
    m_points(width * height, 0)
{
}

size_t Image::getWidth() const
{
    return m_width;
}

size_t Image::getHeight() const
{
    return m_height;
}

Color Image::getPoint(size_t x,
                      size_t y) const
{
    if ((x >= m_width) || (y >= m_height))
    {
        return 0;
    }

    return m_points[y * m_width + x];
}

bool Image::setPoint(size_t x,
                     size_t y,
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
