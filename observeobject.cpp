#include "observeobject.h"

#include <sys/stat.h>

void ObserveObject::Attach(FileObserver *observer){
    subscribers.push_back(observer);
}

void ObserveObject::Detach(FileObserver *observer){
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), observer), subscribers.end());
}

void ObserveObject::Notify(bool existence, long size){
    for(std::vector<FileObserver*>::const_iterator iter = subscribers.begin(); iter != subscribers.end(); iter++) {
        if (*iter != 0) {
            (*iter)->Update(existence, size);
        }
    }
}

FileMonitor::FileMonitor(QString name) : prevFileState(name) { }

void FileMonitor::checkFile() {
    Info newFileState(prevFileState.name);
    Change(newFileState.existence, newFileState.size);
    prevFileState = newFileState;
}

void FileMonitor::Change(bool existence, long size) {
    Notify(existence, size);
}
