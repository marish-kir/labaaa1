#include "filetracker.h"
#include <QTextStream>

FileTracker::FileTracker()
{
    QObject::connect(this, &FileTracker::file_changed, &FileTracker::update_file);
}
void FileTracker::add_file(QString _name)
{
    InfoFile file(_name);

    if(file.is_file() && !files.contains(file))
        files.append(file);
}
void FileTracker::monitor()
{
    QTextStream out(stdout);
    for(int i=0; i<files.size(); i++)
    {
        if(files[i].get_state()!=files[i].get_actual_state())
        {
           emit update_file(files[i]);
           out<<files[i].get_name()<<" state changed"<<endl;
        }
        else if(files[i].get_size()!=files[i].get_actual_size())
        {
            emit update_file(files[i]);
            out<<files[i].get_name()<<" size changed"<<endl;
        }

    }

}
QList<QString> FileTracker::get_files_info()
{
    QList<QString> info;
    for(int i=0; i<files.size(); i++){
        info.append(files[i].get_name() + " " + QString::number(files[i].get_size()) + " " + (files[i].get_state()?" exists":" dosn't exist"));
    }
    return info;
}
void FileTracker::update_file(InfoFile& file)
{
    file.update_info();
}
