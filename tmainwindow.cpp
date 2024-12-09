#include "tmainwindow.h"
#include "ui_tmainwindow.h"

TMainWindow::TMainWindow(TController *controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TMainWindow)
{
    ui->setupUi(this);
    initUI();

    this->controller = controller;
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

void TMainWindow::logDataAboutMatrix()
{
    auto data = controller->getDataAboutMatrix();
    for (int i = 0; i < data.size(); ++i)
        logMessage(data[i]);
}

void TMainWindow::loadFromFile()
{
    QStringList fileNames;
    if (dialogOpen->exec())
    {
        fileNames = dialogOpen->selectedFiles();
        controller->fillMatrixFromFile(fileNames[0].toStdString());

        if (controller->hasInitializedMatrix())
        {
            logMessage("Матрица была успешно считана");
            logDataAboutMatrix();
            logSeparator();

            matrixIsLoaded = true;
            initPathfindElems();
        }
    }
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
    initDialogOpen();
}

void TMainWindow::initLog()
{
    logMessage("Добро пожаловать в программу для поиска путей на матрице высот.");
    logSeparator();
}

void TMainWindow::initDialogOpen()
{
    dialogOpen = new QFileDialog(this);
    dialogOpen->setFileMode(QFileDialog::AnyFile);
    dialogOpen->setNameFilter(tr("BINARY (*)"));
};

void TMainWindow::initPathfindElems()
{
    ui->btnFindPath->setEnabled(matrixIsLoaded);

    ui->rbNoHeuristic->setChecked(true);
    ui->rbNoHeuristic->setEnabled(matrixIsLoaded);
    ui->rbManhattanHeuristic->setEnabled(matrixIsLoaded);
    ui->rbChebyshevaHeuristic->setEnabled(matrixIsLoaded);
    ui->rbEvklidHeuristic->setEnabled(matrixIsLoaded);


    ui->spboxStartX->setEnabled(matrixIsLoaded);
    ui->spboxStartY->setEnabled(matrixIsLoaded);
    ui->spboxEndX->setEnabled(matrixIsLoaded);
    ui->spboxEndY->setEnabled(matrixIsLoaded);

    ui->cbUseTimer->setEnabled(matrixIsLoaded);
    ui->cbVisualize->setEnabled(matrixIsLoaded);
}

void TMainWindow::on_btnLoadFromFile_pressed()
{
    loadFromFile();
}

