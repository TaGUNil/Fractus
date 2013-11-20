#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include "types.h"

class Image
{
public:
    Image(unsigned int width,
          unsigned int height);

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    Color getPoint(unsigned int x,
                   unsigned int y) const;
    bool setPoint(unsigned int x,
                  unsigned int y,
                  Color color);

    const Color *getRawPoints() const;
    Color *getRawPoints();

private:
    unsigned int m_width;
    unsigned int m_height;
    std::vector<Color> m_points;
};

#endif // IMAGE_H
