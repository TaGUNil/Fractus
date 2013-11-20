#include "palette.h"

Palette::Palette(unsigned int length) :
    m_colors(length, colorFromRGB(0, 0, 0))
{
}

unsigned int Palette::getLength() const
{
    return m_colors.size();
}

Color Palette::getColor(unsigned int index) const
{
    if (index >= m_colors.size())
    {
        return colorFromRGB(0, 0, 0);
    }

    return m_colors[index];
}

bool Palette::setColor(unsigned int index,
                       const Color &color)
{
    if (index >= m_colors.size())
    {
        return false;
    }

    m_colors[index] = color;

    return true;
}

bool Palette::setColor(unsigned int index,
                       uint8_t red,
                       uint8_t green,
                       uint8_t blue)
{
    return setColor(index, colorFromRGB(red, green, blue));
}

const Color *Palette::getRawColors() const
{
    return m_colors.data();
}

Color *Palette::getRawColors()
{
    return m_colors.data();
}
