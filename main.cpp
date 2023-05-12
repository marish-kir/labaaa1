#include <QCoreApplication>
#include "filetracker.h"
#include <QList>
#include <QString>
#include <QTextStream>
#include <thread>
#include <chrono>
#include "output.h"

void print_files(FileTracker&track){
    QTextStream out(stdout);
    QList<QString> files = track.get_files_info();
    for(int i=0; i<files.size(); i++){
        out <<files[i]<<endl;
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileTracker track;
    Output out;
    QObject::connect(&track, &FileTracker::size_changed,&out, &Output::size_changed_print);
    QObject::connect(&track, &FileTracker::file_deleted,&out, &Output::file_deleted_print);
    QObject::connect(&track, &FileTracker::file_created,&out, &Output::file_created_print);
    track.add_file("C:\\filesForLab\\file1.txt");
    track.add_file("C:\\filesForLab\\file1.txt");
    track.add_file("C:\\filesForLab\\file2.txt");
    track.add_file("C:\\filesForLab\\file3.txt");
    track.add_file("C:\\filesForLab\\file4.txt");
    track.add_file("C:\\filesForLab");
    print_files(track);

    while(true)
    {
        std::this_thread::sleep_for( std::chrono::milliseconds(100));
        track.monitor();
    }
    return a.exec();
}
