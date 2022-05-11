#include <iostream>
#include "observeobject.h"
#include "observe.h"
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    FileMonitor monitor("filename.txt");
    FileObserver observer;
    monitor.Attach(&observer);

    while (true){
        monitor.checkFile();
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    return 0;
}
