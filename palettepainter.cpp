#include <vector>
#include "palettepainter.h"

PalettePainter::PalettePainter(Palette *palette) :
    m_palette(palette)
{
}

Image *PalettePainter::createImage(const Surface *surface) const
{
    if (!surface)
    {
        return nullptr;
    }

    unsigned int width = surface->getWidth();
    unsigned int height = surface->getHeight();
    Level maxValue = surface->getMaxValue();
    unsigned int paletteLength = m_palette->getLength();

    Image *image = new Image(width, height);
    if (!image)
    {
        return nullptr;
    }

#pragma omp parallel for
    for (unsigned int y = 0; y < height; y++)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            Level point = surface->getPoint(x, y);

            Color color;

            if (point == maxValue)
            {
                color = colorFromRGB(0, 0, 0);
            }
            else if (point >= paletteLength)
            {
                color = colorFromRGB(0, 0, 0);
            }
            else
            {
                color = m_palette->getColor(point);
            }

            image->setPoint(x, y, color);
        }
    }

    return image;
}
