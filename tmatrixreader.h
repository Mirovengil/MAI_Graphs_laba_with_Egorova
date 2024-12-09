#ifndef TMATRIXREADER_H
#define TMATRIXREADER_H

#include "tmatrix.h"
#include <string>
#include <fstream>

class TMatrixReader
{
private:
    std::fstream fIn;
public:
    TMatrixReader();
    void openFile(std::string filename);
    TMatrix read();
    void close();
};

#endif // TMATRIXREADER_H
