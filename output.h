#ifndef OUTPUT_H
#define OUTPUT_H
#include <QObject>
#include <QTextStream>


class Output : public QObject
{
    Q_OBJECT
public:
    Output();
public slots:
    void size_changed_print(QString name, int size);
    void file_deleted_print(QString name);
    void file_created_print(QString name, int size);
};

#endif // OUTPUT_H
