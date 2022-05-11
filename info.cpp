#include "info.h"

Info::Info(QString fileName)
{
    name = fileName;
    struct stat stat_buf;
    existence = stat(fileName.toStdString().c_str(), &stat_buf) == 0;
    size = stat_buf.st_size;
}
