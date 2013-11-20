#ifndef PALETTE_H
#define PALETTE_H

#include <vector>
#include "types.h"

class Palette
{
public:
    Palette(unsigned int length);

    unsigned int getLength() const;

    Color getColor(unsigned int index) const;
    bool setColor(unsigned int index,
                  const Color &color);
    bool setColor(unsigned int index,
                  uint8_t red,
                  uint8_t green,
                  uint8_t blue);

    const Color *getRawColors() const;
    Color *getRawColors();

private:
    std::vector<Color> m_colors;
};

#endif // PALETTE_H
