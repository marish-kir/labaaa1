#include <QCoreApplication>
#include "filetracker.h"
#include <QList>
#include <QString>
#include <QTextStream>
#include <thread>
#include <chrono>

void print_files(FileTracker track){
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
