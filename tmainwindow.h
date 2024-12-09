#ifndef TMAINWINDOW_H
#define TMAINWINDOW_H

#include <QMainWindow>
#include "tcontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TMainWindow; }
QT_END_NAMESPACE

class TMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    TMainWindow(TController *controller, QWidget *parent = nullptr);
    ~TMainWindow();

private:
    Ui::TMainWindow *ui;

    // variables
    std::string separator;
    bool matrixIsLoaded;
    TController *controller;

    // functions and procedures
    void logMessage(std::string message);
    void logSeparator();

    void initUI();
    void initLog();
    void initPathfindElems();
};
#endif // TMAINWINDOW_H
