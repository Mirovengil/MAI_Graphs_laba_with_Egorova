#include "tmainwindow.h"
#include "tcontroller.h"
#include "tmatrix.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    TMatrix matrix;
    TController controller(&matrix);

    QApplication a(argc, argv);
    TMainWindow w(&controller);
    w.show();
    return a.exec();
}
