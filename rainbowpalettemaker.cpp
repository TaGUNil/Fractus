#include <math.h>
#include "rainbowpalettemaker.h"

Palette *RainbowPaletteMaker::createPalette() const
{
    Palette *palette = new Palette(360);
    if (!palette)
    {
        return nullptr;
    }

    double saturation = 1.0;
    double value = 1.0;
    double chroma = value * saturation;

    for (int i = 0; i < 360; i++)
    {
        double hue = i / 60.0;
        double x = chroma * (1.0 - fabs(1.0 - fmod(hue, 2.0)));

        double red = 0.0;
        double green = 0.0;
        double blue = 0.0;

        if ((hue >= 0.0) && (hue < 1.0))
        {
            red = chroma;
            green = x;
            blue = 0.0;
        }
        else if ((hue >= 1.0) && (hue < 2.0))
        {
            red = x;
            green = chroma;
            blue = 0.0;
        }
        else if ((hue >= 2.0) && (hue < 3.0))
        {
            red = 0.0;
            green = chroma;
            blue = x;
        }
        else if ((hue >= 3.0) && (hue < 4.0))
        {
            red = 0.0;
            green = x;
            blue = chroma;
        }
        else if ((hue >= 4.0) && (hue < 5.0))
        {
            red = x;
            green = 0.0;
            blue = chroma;
        }
        else if ((hue >= 5.0) && (hue < 6.0))
        {
            red = chroma;
            green = 0.0;
            blue = x;
        }

        red += value - chroma;
        green += value - chroma;
        blue += value - chroma;

        palette->setColor(i,
                          round(red * 255),
                          round(green * 255),
                          round(blue * 255));
    }

    return palette;
}
