#include "tpoint.h"

TPoint::TPoint(int x, int y)
{
    this->x = x;
    this->y = y;
}

TPoint::TPoint() : TPoint(0, 0)
{

}

int TPoint::getX()
{
    return x;
}

int TPoint::getY()
{
    return y;
}
