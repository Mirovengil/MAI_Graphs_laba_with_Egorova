#ifndef TMAINWINDOW_H
#define TMAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
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

private slots:
    void on_btnLoadFromFile_pressed();

private:
    Ui::TMainWindow *ui;

    // variables
    std::string separator;
    bool matrixIsLoaded;
    TController *controller;
    QFileDialog *dialogOpen;

    // functions and procedures
    void logMessage(std::string message);
    void logSeparator();
    void logDataAboutMatrix();

    void loadFromFile();

    void initUI();
    void initLog();
    void initPathfindElems();
    void initDialogOpen();
};
#endif // TMAINWINDOW_H
