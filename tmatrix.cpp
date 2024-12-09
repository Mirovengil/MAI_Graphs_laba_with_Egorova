#include "tmatrix.h"
#include <stdexcept>

// TMatrix's methods

void TMatrix::checkIfPointIsInMatrix(TPoint point)
{
    if (!pointIsInMatrix(point))
        throw std::range_error("TMatrix : point is out of matrix!");
}

TMatrixPoint &TMatrix::getPoint(TPoint point)
{
    return data[point.getY()][point.getX()];
}

TMatrix::TMatrix()
{

}

bool TMatrix::pointIsInMatrix(TPoint point)
{
    int N = data.size();

    if (N == 0)
       return false;

    int M = data[0].size();

    return ((N > point.getY()) && (M > point.getX()));
}

bool TMatrix::isVisited(TPoint point)
{
    checkIfPointIsInMatrix(point);
    return getPoint(point).isVisited();
}

void TMatrix::visit(TPoint point)
{
    checkIfPointIsInMatrix(point);
    getPoint(point).visit();
}

void TMatrix::unvisit(TPoint point)
{
    checkIfPointIsInMatrix(point);
    getPoint(point).unvisit();
}

void TMatrix::setValue(TPoint point, type value)
{
    checkIfPointIsInMatrix(point);
    getPoint(point).setValue(value);
}

void TMatrix::resize(int N, int M)
{
    data.resize(N);
    for (int i = 0; i < N; ++i)
        data[i].resize(M);
    unvisit();
}

void TMatrix::unvisit()
{
    for (int i = 0; i < data.size(); ++i)
        for (int j = 0; j < data[i].size(); ++j)
        {
            TPoint point(j, i);
            getPoint(point).unvisit();
        }
}

type TMatrix::getValue(TPoint point)
{
    checkIfPointIsInMatrix(point);
    return getPoint(point).getValue();
}

// TMatrixPoint's methods

void TMatrixPoint::setValue(type value)
{
    this->value = value;
}

type TMatrixPoint::getValue()
{
    return value;
}

void TMatrixPoint::visit()
{
    visited = true;
}

void TMatrixPoint::unvisit()
{
    visited = false;
}

bool TMatrixPoint::isVisited()
{
    return visited;
}
