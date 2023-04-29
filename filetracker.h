#ifndef FILETRACKER_H
#define FILETRACKER_H
#include <QList>
#include "infofile.h"

class FileTracker
{
private:
    QList<InfoFile> files;
public:
    FileTracker();
    void add_file(QString _name);
    void monitor();
    QList<QString> get_files_info();
};

#endif // FILETRACKER_H
