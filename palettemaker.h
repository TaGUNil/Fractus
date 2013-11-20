#ifndef PALETTEMAKER_H
#define PALETTEMAKER_H

#include "palette.h"

class PaletteMaker
{
public:
    virtual ~PaletteMaker()
    {
    }

    virtual Palette *createPalette() const = 0;
};

#endif // PALETTEMAKER_H
