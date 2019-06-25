#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "dump852thread.h"
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onAccessFileChanged(bool);
    void onProgressVisibleChanged(bool);

private slots:
    void on_actionCIDCO_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
        dump852Thread *dt;
};

#endif // MAINWINDOW_H
