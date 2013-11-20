#ifndef PALETTEPAINTER_H
#define PALETTEPAINTER_H

#include <memory>
#include "painter.h"
#include "palette.h"

class PalettePainter : public Painter
{
public:
    PalettePainter(Palette *palette);

    Image *createImage(const Surface *surface) const;

private:
    std::unique_ptr<Palette> m_palette;
};

#endif // PALETTEPAINTER_H
