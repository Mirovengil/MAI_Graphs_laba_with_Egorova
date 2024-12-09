#include "tmainwindow.h"
#include "ui_tmainwindow.h"

TMainWindow::TMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TMainWindow)
{
    ui->setupUi(this);

    initUI();
}

TMainWindow::~TMainWindow()
{
    delete ui;
}

void TMainWindow::logMessage(std::string message)
{
    ui->editLog->append(QString::fromStdString(message));
}

void TMainWindow::logSeparator()
{
    logMessage(separator);
}

void TMainWindow::initUI()
{
    // init constants
    separator = "----------------------------------------------------";

    // init variables
    matrixIsLoaded = false;

    // init UI elems
    initLog();
    initPathfindElems();
}

void TMainWindow::initLog()
{
    logMessage("Добро пожаловать в программу для поиска путей на матрице высот.");
    logSeparator();
}

void TMainWindow::initPathfindElems()
{
    ui->btnFindPath->setEnabled(matrixIsLoaded);

    ui->rbNoHeuristic->setEnabled(matrixIsLoaded);
    ui->rbManhattanHeuristic->setEnabled(matrixIsLoaded);
    ui->rbChebyshevaHeuristic->setEnabled(matrixIsLoaded);
    ui->rbEvklidHeuristic->setEnabled(matrixIsLoaded);

    ui->spboxStartX->setEnabled(matrixIsLoaded);
    ui->spboxStartY->setEnabled(matrixIsLoaded);
    ui->spboxEndX->setEnabled(matrixIsLoaded);
    ui->spboxEndY->setEnabled(matrixIsLoaded);
}

