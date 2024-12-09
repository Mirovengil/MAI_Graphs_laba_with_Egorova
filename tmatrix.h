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

    friend class TMatrixReader;
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

    int getSizeX(){return data[0].size();};
    int getSizeY(){return data.size();};

    friend class TMatrixReader;
};

#endif // TMATRIX_H
