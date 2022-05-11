#ifndef INFO_H
#define INFO_H
#include <QString>
#include <sys/stat.h>
class Info
{
public:
    QString name;
    long size;
    bool existence;
    Info(QString fileName);
};

#endif // INFO_H
