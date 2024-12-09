#ifndef TCONTROLLER_H
#define TCONTROLLER_H

#include "tmatrix.h"
#include <string>
#include <vector>

class TController
{
private:
    TMatrix *matrix;
    bool matrixIsInitialized;

public:
    TController(TMatrix *matrix);

    void fillMatrixFromFile(std::string filename);
    bool hasInitializedMatrix();
    std::vector <std::string> getDataAboutMatrix();
};

#endif // TCONTROLLER_H
