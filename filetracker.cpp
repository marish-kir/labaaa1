#include "filetracker.h"
#include <QTextStream>

FileTracker::FileTracker()
{

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
        if(files[i].get_size()!=files[i].get_actual_size())
        {
            files[i].update_info();
            out<<files[i].get_name()<<" size changed"<<endl;
        }
         if(files[i].get_state()!=files[i].get_actual_state())
         {
            files[i].update_info();
            out<<files[i].get_name()<<" state changed"<<endl;
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
