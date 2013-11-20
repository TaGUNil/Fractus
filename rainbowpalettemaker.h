#ifndef RAINBOWPALETTEMAKER_H
#define RAINBOWPALETTEMAKER_H

#include "palettemaker.h"

class RainbowPaletteMaker : public PaletteMaker
{
public:
    Palette *createPalette() const;
};

#endif // RAINBOWPALETTEMAKER_H
