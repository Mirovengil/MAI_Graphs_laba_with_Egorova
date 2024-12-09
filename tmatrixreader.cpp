#include "tmatrixreader.h"
#include <stdexcept>

TMatrixReader::TMatrixReader()
{

}

void TMatrixReader::openFile(std::string filename)
{
    fIn.open(filename, std::ios::in | std::ios::binary);
    if (!fIn)
        throw std::logic_error("TMatrixReader : file was not found!");
}

TMatrix TMatrixReader::read()
{
    TMatrix matrix;

    type N, M;
    fIn.read((char*)&N, sizeof(type));
    fIn.read((char*)&M, sizeof(type));

    matrix.resize(N, M);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            fIn.read((char*)&(matrix.data[i][j].value), sizeof(type));
        }
    }

    return matrix;
}

void TMatrixReader::close()
{
    fIn.close();
}
