#ifndef SURFACE_H
#define SURFACE_H

#include <stddef.h>
#include <vector>
#include "types.h"

class Surface
{
public:
    Surface(size_t width,
            size_t height);

    size_t getWidth() const;
    size_t getHeight() const;

    Level getMaxValue() const;
    void setMaxValue(Level value);

    Level getPoint(size_t x,
                   size_t y) const;
    bool setPoint(size_t x,
                  size_t y,
                  Level value);

    const Level *getRawPoints() const;
    Level *getRawPoints();

private:
    size_t m_width;
    size_t m_height;
    Level m_maxValue;
    std::vector<Level> m_points;
};

#endif // SURFACE_H
