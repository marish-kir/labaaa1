#include "filetracker.h"

FileTracker::FileTracker()
{

}
FileTracker& FileTracker::Instance()
{
    static FileTracker obj;
    return obj;
}
void FileTracker::add_file(QString _name)
{
    InfoFile file(_name);


    if(file.is_file() && !files.contains(file))
    {
        QTextStream out(stdout);
        out << "file "<< _name << " added"<<endl;
        files.append(file);
    }
    else
    {
        QTextStream out(stdout);
        out << "file"<< _name<< " not added"<<endl;
    }
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

           files[i].update_info();
        }
        else if(files[i].get_size()!=files[i].get_actual_size())
        {
            files[i].update_info();
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
