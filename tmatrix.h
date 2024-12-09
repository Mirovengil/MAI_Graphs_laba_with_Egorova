#ifndef TMATRIX_H
#define TMATRIX_H

#include <vector>
#include <stdint.h>
#include "tpoint.h"

typedef int16_t type;

class TMatrixPoint
{
private:
    type value;
    bool visited;
public:
    void setValue(type value);
    type getValue();
    void visit();
    void unvisit();
    bool isVisited();
};

class TMatrix
{
private:
    std::vector <std::vector <TMatrixPoint>> data;
    void checkIfPointIsInMatrix(TPoint point);
    TMatrixPoint &getPoint(TPoint point);
public:
    TMatrix();
    bool pointIsInMatrix(TPoint point);
    bool isVisited(TPoint point);
    void visit(TPoint point);
    void unvisit(TPoint point);
    void setValue(TPoint point, type value);
    void resize(int N, int M);
    void unvisit();
    type getValue(TPoint point);

};

#endif // TMATRIX_H
