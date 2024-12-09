#include "tpoint.h"

TPoint::TPoint(int x, int y)
{
    this->x = x;
    this->y = y;
}

int TPoint::getX()
{
    return x;
}

int TPoint::getY()
{
    return y;
}
