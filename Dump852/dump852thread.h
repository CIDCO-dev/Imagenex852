#ifndef DUMP852THREAD_H
#define DUMP852THREAD_H
#include <QThread>
#include <QObject>


class dump852Thread:public QThread
{
    Q_OBJECT
public:
    dump852Thread();
    void run();
    void setOpenFile(std::string filename);
    void setSaveFile(std::string filename);

private:
    std::string openFile;
    std::string saveFile;
};

#endif // DUMP852THREAD_H
