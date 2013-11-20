#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <complex>

typedef double Real;
typedef std::complex<Real> Complex;

typedef unsigned int Level;

typedef uint32_t Color;

inline constexpr Color colorFromRGB(uint8_t red,
                                    uint8_t green,
                                    uint8_t blue)
{
    return (0xff << 24) | (red << 16) | (green << 8) | (blue << 0);
}

inline constexpr uint8_t redValue(Color color)
{
    return (color >> 16) & 0xff;
}

inline constexpr uint8_t greenValue(Color color)
{
    return (color >> 8) & 0xff;
}

inline constexpr uint8_t blueValue(Color color)
{
    return (color >> 0) & 0xff;
}

#endif // TYPES_H
