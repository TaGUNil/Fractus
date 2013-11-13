#ifndef DUMPER_H
#define DUMPER_H

#include "image.h"

class Dumper
{
public:
    virtual ~Dumper()
    {
    }

    virtual bool dumpImage(const Image *image) const = 0;
};

#endif // DUMPER_H
