#ifndef DUMP852THREAD_H
#define DUMP852THREAD_H
#include <QThread>
#include <QObject>
#include <QtCore>
#include "Imagenex852.hpp"
#include "dumper852.hpp"

class dump852Thread:public QThread
{
    Q_OBJECT

public:
    dump852Thread();
    void run();
    void setOpenFile(std::string filename);
    void setSaveFile(std::string filename);
    Dumper852 *dump;

signals:
    void AccessFileChanged(bool);
    void ProgressVisibleChanged(bool);

private:
    std::string openFile;
    std::string saveFile;
};

#endif // DUMP852THREAD_H
