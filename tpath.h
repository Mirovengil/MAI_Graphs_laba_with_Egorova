#ifndef TPATH_H
#define TPATH_H

#include <vector>
#include "tpoint.h"

class TPath
{
    std::vector <TPoint> steps;
public:
    TPath();
    void addStep(TPoint step);
};

#endif // TPATH_H
