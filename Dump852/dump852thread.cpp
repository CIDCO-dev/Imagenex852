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
    try
    {
        Dumper852 dump(saveFile);
        dump.read(openFile);
    }
    catch(Exception * e)
    {
        std::cerr << e->getMessage() << std::endl;
    }
}

void dump852Thread::setOpenFile(std::string filename)
{
    openFile = filename;
}

void dump852Thread::setSaveFile(std::string filename)
{
    saveFile = filename;
}
