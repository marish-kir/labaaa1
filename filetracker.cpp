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
    for(int i=0; i<files.size(); i++)
    {
        if(files[i].get_state()!=files[i].get_actual_state())
        {
            if(files[i].get_actual_state())
                emit file_created(files[i].get_name(),files[i].get_actual_size());
            else
                emit file_deleted(files[i].get_name());

           update_file(files[i]);
        }
        else if(files[i].get_size()!=files[i].get_actual_size())
        {
            update_file(files[i]);
            emit size_changed(files[i].get_name(),files[i].get_size());
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
