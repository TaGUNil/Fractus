#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>
#include <stddef.h>
#include <vector>
#include "types.h"

class Image
{
public:
    Image(size_t width,
          size_t height);

    size_t getWidth() const;
    size_t getHeight() const;

    Color getPoint(size_t x,
                   size_t y) const;
    bool setPoint(size_t x,
                  size_t y,
                  Color color);

    const Color *getRawPoints() const;
    Color *getRawPoints();

private:
    size_t m_width;
    size_t m_height;
    std::vector<Color> m_points;
};

#endif // IMAGE_H
