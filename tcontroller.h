#ifndef TCONTROLLER_H
#define TCONTROLLER_H

#include "tmatrix.h"

class TController
{
private:
    TMatrix *matrix;
public:
    TController(TMatrix *matrix);
};

#endif // TCONTROLLER_H
