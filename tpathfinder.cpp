#include "tpathfinder.h"

TPathFinder::TPathFinder()
{

}

void TPathFinder::setMatrix(TMatrix *matrix)
{
    this->matrix=matrix;
}

void TPathFinder::setStartPoint(TPoint point)
{
    startPoint = point;
}

void TPathFinder::setEndPoint(TPoint point)
{
    endPoint = point;
}

void TPathFinder::setHeuristic(IHeuristicStrategy *heuristic)
{
    this->heuristic = heuristic;
}

TPath TPathFinder::findPath()
{
    // TODO : сделать нормально!!!
    TPath result;
    return result;
}
