#ifndef THEURISTICS_H
#define THEURISTICS_H

#include "tpoint.h"
#include <string>
#include <math.h>

int abs(int a)
{
    if (a > 0)
        return a;
    else
        return -a;
}

class IHeuristicStrategy
{
public:
    virtual std::string getSignature() = 0;
    virtual int getDistance(TPoint from, TPoint to) = 0;
};

class TEvclideHeuristicStrategy : IHeuristicStrategy
{
public:
    virtual std::string getSignature()
    {
        return "Эвклида";
    }

    virtual int getDistance(TPoint from, TPoint to)
    {
        int a = from.getX() - to.getX();
        int b = from.getY() - to.getY();
        return sqrt(a*a + b*b);
    }
};

class TManhattenHeuristicStrategy : IHeuristicStrategy
{
public:
    virtual std::string getSignature()
    {
        return "Манхэттена";
    }

    virtual int getDistance(TPoint from, TPoint to)
    {
        return abs(from.getX() - to.getX()) + abs(from.getY() - to.getY());
    }
};

class TChebyshevHeuristicStrategy: IHeuristicStrategy
{
public:
    virtual std::string getSignature()
    {
        return "Чебышева";
    }

    virtual int getDistance(TPoint from, TPoint to)
    {
        return std::max(abs(from.getX() - to.getX()), abs(to.getY() - from.getY()));
    }
};

class TNoHeuristicStrategy: IHeuristicStrategy
{
public:
    virtual std::string getSignature()
    {
        return "отсутствует";
    }

    virtual int getDistance(TPoint from, TPoint to)
    {
        return 0;
    }
};

#endif // THEURISTICS_H
