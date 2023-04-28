#include <QCoreApplication>
#include "filetracker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileTracker track;
    track.add_file("C:\\filesForLab\\file1.txt");
    track.add_file("C:\\filesForLab\\file2.txt");
    track.add_file("C:\\filesForLab\\file3.txt");
    track.add_file("C:\\filesForLab\\file4.txt");
    track.monitor();
    return a.exec();
}
