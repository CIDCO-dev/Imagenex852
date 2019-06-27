#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "workerThread.h"
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

    void disableUI();
    void enableUI();

public slots:
    void onAccessFileChanged(bool);
    void onProgressVisibleChanged(bool);

private slots:
    void on_actionCIDCO_triggered();

    void on_actionOpen_triggered();

    void on_btnDump_clicked();

private:
    Ui::MainWindow *ui;
    WorkerThread worker;

    std::string inputFileName;
    std::string outputFileName;
};

#endif // MAINWINDOW_H
