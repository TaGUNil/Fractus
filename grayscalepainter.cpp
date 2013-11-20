#include "grayscalepainter.h"

Image *GrayscalePainter::createImage(const Surface *surface) const
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

            uint8_t brightness;

            if (point == maxValue)
            {
                brightness = 255;
            }
            else if (point > 255)
            {
                brightness = 255;
            }
            else
            {
                brightness = point;
            }

            brightness = 255 - brightness;

            image->setPoint(x, y, colorFromRGB(brightness,
                                               brightness,
                                               brightness));
        }
    }

    return image;
}
