#include "dump852thread.h"
#include <QThread>
#include <QObject>
#include "mainwindow.h"
#include "dumper852.hpp"

dump852Thread::dump852Thread()
{
}

void dump852Thread::run()
{
    emit AccessFileChanged(false);
    emit ProgressVisibleChanged(true);
    dump = new Dumper852(saveFile);
    try
    {
        dump->read(openFile);
    }
    catch(Exception * e)
    {
        std::cerr << e->getMessage() << std::endl;
    }
    emit AccessFileChanged(true);
    emit ProgressVisibleChanged(false);
}

void dump852Thread::setOpenFile(std::string filename)
{
    openFile = filename;
}

void dump852Thread::setSaveFile(std::string filename)
{
    saveFile = filename;
}
