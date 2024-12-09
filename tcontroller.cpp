#include "tcontroller.h"
#include "tmatrixreader.h"

TController::TController(TMatrix *matrix)
{
    this->matrix = matrix;
    matrixIsInitialized = false;
}

void TController::fillMatrixFromFile(std::string filename)
{
    TMatrixReader reader;

    reader.openFile(filename);
    *matrix = reader.read();
    reader.close();
    matrixIsInitialized = true;
}

bool TController::hasInitializedMatrix()
{
    return matrixIsInitialized;
}

std::vector<std::string> TController::getDataAboutMatrix()
{
    std::vector <std::string> data;
    int N = matrix->getSizeY();
    int M = matrix->getSizeX();

    data.push_back("Число строк: " + std::to_string(N));
    data.push_back("Число столбцов: " + std::to_string(M));
    data.push_back("Первый элемент: " + std::to_string(matrix->getValue({0, 0})));
    data.push_back("Последний элемент: " + std::to_string(matrix->getValue({M-1, N-1})));

    return data;
}
