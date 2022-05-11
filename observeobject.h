#ifndef OBSERVEOBJECT_H
#define OBSERVEOBJECT_H

#include "observe.h"
#include <vector>
#include <info.h>
using namespace  std;
class ObserveObject
{
private:
    vector<FileObserver*> subscribers;
public:
    void Attach(FileObserver *observer);
    void Detach(FileObserver *observer);
    void Notify(bool existence, long size);
};
class FileMonitor: public ObserveObject {
private:
    Info prevFileState;
public:
    FileMonitor(QString _name);
    void checkFile();
    void Change(bool existence, long size);
};
#endif // OBSERVEOBJECT_H
