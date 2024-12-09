#ifndef TPATHFINDER_H
#define TPATHFINDER_H

#include "tpoint.h"
#include "tmatrix.h"
#include "theuristics.h"
#include "tpath.h"

class TPathFinder
{
private:
    TMatrix *matrix;
    TPoint startPoint;
    TPoint endPoint;
    IHeuristicStrategy *heuristic;
public:
    TPathFinder();
    void setMatrix(TMatrix *matrix);
    void setStartPoint(TPoint point);
    void setEndPoint(TPoint point);
    void setHeuristic(IHeuristicStrategy *heuristic);

    TPath findPath();
};

#endif // TPATHFINDER_H
