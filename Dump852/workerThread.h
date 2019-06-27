#ifndef DUMP852THREAD_H
#define DUMP852THREAD_H
#include <QThread>
#include <QObject>
#include <QtCore>
#include "Imagenex852.hpp"
#include "dumper852.hpp"

class WorkerThread:public QThread
{
    Q_OBJECT

public:
    WorkerThread();
    void run();

    Dumper852 *dump;


    void setInputFileName(std::string & filename){
        inputFileName = filename;
    }

    void setOutputFileName(std::string & filename){
        outputFileName = filename;
    }

signals:
    void AccessFileChanged(bool);
    void ProgressVisibleChanged(bool);

private:
    std::string inputFileName;
    std::string outputFileName;
};

#endif // DUMP852THREAD_H
