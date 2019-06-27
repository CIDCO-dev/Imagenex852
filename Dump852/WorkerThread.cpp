#include "workerThread.h"
#include <QThread>
#include <QObject>
#include "mainwindow.h"
#include "dumper852.hpp"

WorkerThread::WorkerThread()
{
}

void WorkerThread::run()
{

    dump = new Dumper852(outputFileName);
    try
    {
        dump->read(inputFileName);
    }
    catch(Exception * e)
    {
        std::cerr << e->getMessage() << std::endl;
    }

}


