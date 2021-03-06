#include "binarypainter.h"

Image *BinaryPainter::createImage(const Surface *surface) const
{
    if (!surface)
    {
        return nullptr;
    }

    unsigned int width = surface->getWidth();
    unsigned int height = surface->getHeight();
    Level maxValue = surface->getMaxValue();

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

            if (point == maxValue)
            {
                image->setPoint(x, y, colorFromRGB(0, 0, 0));
            }
            else
            {
                image->setPoint(x, y, colorFromRGB(255, 255, 255));
            }
        }
    }

    return image;
}
