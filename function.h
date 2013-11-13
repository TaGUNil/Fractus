#ifndef FUNCTION_H
#define FUNCTION_H

#include "types.h"

class Function
{
public:
    virtual ~Function()
    {
    }

    virtual Complex operator()(const Complex &z) const = 0;
};

#endif // FUNCTION_H
