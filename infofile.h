#ifndef INFOFILE_H
#define INFOFILE_H
#include <QString>
#include <QFileInfo>

class InfoFile
{
   private:
    int size;
    QString name;
    bool state;

public:
    InfoFile();
    InfoFile(QString _name);


    int get_size();
    QString get_name();
    bool get_state();

    int get_actual_size();
    bool get_actual_state();

    void UpdateInfo();

};

#endif // INFOFILE_H
