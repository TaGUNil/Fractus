#include "binarypainter.h"

Image *BinaryPainter::createImageFromSurface(const Surface *surface) const
{
    size_t width = surface->getWidth();
    size_t height = surface->getHeight();
    Level maxValue = surface->getMaxValue();

    Image *image = new Image(width, height);
    if (!image)
    {
        return nullptr;
    }

#pragma omp parallel for
    for (size_t y = 0; y < height; y++)
    {
        for (size_t x = 0; x < width; x++)
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
