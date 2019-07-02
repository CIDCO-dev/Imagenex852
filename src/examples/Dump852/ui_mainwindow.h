/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionCIDCO;
    QWidget *centralWidget;
    QProgressBar *pbProgress;
    QLabel *txtFilenameLabel;
    QLabel *txtFilename;
    QPushButton *btnDump;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(851, 134);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(851, 134));
        MainWindow->setMaximumSize(QSize(851, 134));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionCIDCO = new QAction(MainWindow);
        actionCIDCO->setObjectName(QStringLiteral("actionCIDCO"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pbProgress = new QProgressBar(centralWidget);
        pbProgress->setObjectName(QStringLiteral("pbProgress"));
        pbProgress->setGeometry(QRect(10, 40, 831, 23));
        pbProgress->setAutoFillBackground(false);
        pbProgress->setMaximum(100);
        pbProgress->setValue(0);
        pbProgress->setTextVisible(true);
        pbProgress->setInvertedAppearance(false);
        txtFilenameLabel = new QLabel(centralWidget);
        txtFilenameLabel->setObjectName(QStringLiteral("txtFilenameLabel"));
        txtFilenameLabel->setGeometry(QRect(10, 20, 91, 20));
        txtFilename = new QLabel(centralWidget);
        txtFilename->setObjectName(QStringLiteral("txtFilename"));
        txtFilename->setGeometry(QRect(100, 20, 741, 20));
        btnDump = new QPushButton(centralWidget);
        btnDump->setObjectName(QStringLiteral("btnDump"));
        btnDump->setGeometry(QRect(10, 70, 131, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 851, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionOpen);
        menuAbout->addAction(actionCIDCO);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Dump852", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", Q_NULLPTR));
        actionCIDCO->setText(QApplication::translate("MainWindow", "&CIDCO", Q_NULLPTR));
        txtFilenameLabel->setText(QApplication::translate("MainWindow", "File selected:", Q_NULLPTR));
        txtFilename->setText(QString());
        btnDump->setText(QApplication::translate("MainWindow", "Dump file data", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "&About", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
