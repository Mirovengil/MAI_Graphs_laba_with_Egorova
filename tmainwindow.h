#ifndef TMAINWINDOW_H
#define TMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TMainWindow; }
QT_END_NAMESPACE

class TMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    TMainWindow(QWidget *parent = nullptr);
    ~TMainWindow();

private:
    Ui::TMainWindow *ui;
};
#endif // TMAINWINDOW_H
