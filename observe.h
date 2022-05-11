#ifndef OBSERVE_H
#define OBSERVE_H


class Observe
{
public:
    virtual void Update(bool existence, long size) = 0;
};

class FileObserver: Observe
{
private:
    long lastSize = -1;
public:
    void Update(bool existence, long size);
};

#endif // OBSERVE_H
