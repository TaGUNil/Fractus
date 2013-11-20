#ifndef SURFACE_H
#define SURFACE_H

#include <vector>
#include "types.h"

class Surface
{
public:
    Surface(unsigned int width,
            unsigned int height);

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    Level getMaxValue() const;
    void setMaxValue(Level value);

    Level getPoint(unsigned int x,
                   unsigned int y) const;
    bool setPoint(unsigned int x,
                  unsigned int y,
                  Level value);

    const Level *getRawPoints() const;
    Level *getRawPoints();

private:
    unsigned int m_width;
    unsigned int m_height;
    Level m_maxValue;
    std::vector<Level> m_points;
};

#endif // SURFACE_H
