#ifndef FILETRACKER_H
#define FILETRACKER_H
#include <QObject>
#include <QList>
#include "infofile.h"

class FileTracker : public QObject
{
    Q_OBJECT
private:
    QList<InfoFile> files;
public:
    FileTracker();
    void add_file(QString _name);
    void monitor();
    QList<QString> get_files_info();
signals:
    void file_changed(InfoFile& file);
    void size_changed(QString name, int size);
    void file_deleted(QString name);
    void file_created(QString name, int size);
public slots:
    void update_file(InfoFile& file);

};

#endif // FILETRACKER_H
