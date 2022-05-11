#include "observe.h"
#include<iostream>
using namespace  std;
void FileObserver::Update(bool existence, long size) {
    if (lastSize == -1) lastSize = size;
//    lastSize = size;
    if (existence) {
        if (lastSize != size) {
            cout << "File is existung, file has been changed, size: " << size << endl;
            lastSize = size;
        }
        else {
            cout << "File is existing, size: " << lastSize <<endl;
        }
    }
    else {
        cout << "File is not existing" << endl;
    }

}
