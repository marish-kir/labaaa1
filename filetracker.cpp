#include "filetracker.h"
#include <QTextStream>

FileTracker::FileTracker()
{

}
void FileTracker::add_file(QString _name)
{
    files.append(InfoFile(_name));
}
void FileTracker::monitor()
{
    for(int i=0; i<files.size(); i++){
        QTextStream out(stdout);
        out <<files[i].get_name()<<endl;
    }
}
