#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pbProgress->setVisible(false);
    dt = new dump852Thread();
    QObject::connect(dt,SIGNAL(AccessFileChanged(bool)),this,SLOT(onAccessFileChanged(bool)));
    QObject::connect(dt,SIGNAL(ProgressVisibleChanged(bool)),this,SLOT(onProgressVisibleChanged(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCIDCO_triggered()
{
    QMessageBox msg;
    msg.setText("Mission\nCIDCO's mission is to modernize hydrography through research, development, training and technology transfer and to enhance its outcomes in a sustainable way thanks to its partnerships and its leading-edge expertise.\n\nVision\nBe a world-class hydrographic research and development center that contributes to the success of its partners and clients by designing innovative solutions and transferring knowledge.\n\nObjectives\nIncrease the expertise in marine geomatics in the region;\nImprove or develop new methods and technologies for ocean mapping;\nWork with industry, government departments and institutions for the development and improvement of technological solutions for the maritime sector;\nBe a building block for the development of marine information technology and services in the region.");
    msg.exec();
}

void MainWindow::on_actionOpen_triggered()
{
    QFileDialog fd;
    dt->setOpenFile(fd.getOpenFileName().toStdString());
    dt->setSaveFile(fd.getSaveFileName().toStdString());
    dt->start();
}

void MainWindow::onAccessFileChanged(bool access)
{
    ui->menuFile->setEnabled(access);
}

void MainWindow::onProgressVisibleChanged(bool visible)
{
    ui->pbProgress->setVisible(visible);
}
