#ifndef TCONTROLLER_H
#define TCONTROLLER_H

#include "tmatrix.h"
#include "tpoint.h"
#include "theuristics.h"
#include "tpathfinder.h"

#include <string>
#include <vector>

class TController
{
private:
    TMatrix *matrix;
    bool matrixIsInitialized;
    TPathFinder pathFinder;

public:
    TController(TMatrix *matrix);

    void setStartPoint(TPoint point);
    void setEndPoint(TPoint point);
    void setHeuristic(IHeuristicStrategy *heuristic);


    void fillMatrixFromFile(std::string filename);
    bool hasInitializedMatrix();
    std::vector <std::string> getDataAboutMatrix();
};

#endif // TCONTROLLER_H
