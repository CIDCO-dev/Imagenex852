#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "dump852thread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionCIDCO_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
        ::dump852Thread dt;
};

#endif // MAINWINDOW_H
