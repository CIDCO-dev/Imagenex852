#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include "dumper852.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    disableUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::disableUI(){
    ui->pbProgress->setVisible(false);
    ui->btnDump->setVisible(false);
    ui->txtFilenameLabel->setVisible(false);
    ui->txtFilename->setVisible(false);
}

void MainWindow::enableUI(){
    ui->pbProgress->setVisible(true);
    ui->btnDump->setVisible(true);
    ui->txtFilenameLabel->setVisible(true);
    ui->txtFilename->setVisible(true);
}

void MainWindow::on_actionCIDCO_triggered()
{
    QMessageBox msg;
    msg.setText("Mission\nCIDCO's mission is to modernize hydrography through research, development, training and technology transfer and to enhance its outcomes in a sustainable way thanks to its partnerships and its leading-edge expertise.\n\nVision\nBe a world-class hydrographic research and development center that contributes to the success of its partners and clients by designing innovative solutions and transferring knowledge.\n\nObjectives\nIncrease the expertise in marine geomatics in the region;\nImprove or develop new methods and technologies for ocean mapping;\nWork with industry, government departments and institutions for the development and improvement of technological solutions for the maritime sector;\nBe a building block for the development of marine information technology and services in the region.");
    msg.exec();
}

void MainWindow::on_actionOpen_triggered()
{
    inputFileName = QFileDialog::getOpenFileName(this, tr("Open 852 File"), QDir::homePath(), tr("852 Files (*.852)")).toStdString();

    if(inputFileName.size() > 0){
        ui->txtFilename->setText(QString::fromStdString(inputFileName));
        enableUI();
        ui->pbProgress->setValue(0);

        //Check file size
        std::ifstream inputFile(inputFileName, std::ios::binary);
        const auto begin = inputFile.tellg();
        inputFile.seekg (0, std::ios::end);
        const auto end = inputFile.tellg();
        fileSize = (end-begin);

        ui->pbProgress->setMaximum(fileSize);
    }
}

void MainWindow::onAccessFileChanged(bool access)
{
    ui->menuFile->setEnabled(access);
}

void MainWindow::onProgressVisibleChanged(bool visible)
{
    ui->pbProgress->setVisible(visible);
}

void MainWindow::on_btnDump_clicked()
{
    outputFileName = QFileDialog::getSaveFileName(this,tr("Save output to file"),QDir::homePath(),tr("Text file (*.txt)")).toStdString();

    if(outputFileName.size() > 0){
        try{
            Dumper852 dump(outputFileName);
            dump.read(inputFileName);
            ui->pbProgress->setValue(fileSize);

            QMessageBox msg;
            msg.setText(QString::fromStdString("Data dumped successfully"));
            msg.exec();
        }
        catch(Exception * e){
            QMessageBox msg;
            msg.setIcon(QMessageBox::Critical);
            msg.setText(QString::fromStdString(e->getMessage()));
            msg.exec();
        }
    }
}
