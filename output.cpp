#include "output.h"

Output::Output()
{

}
void Output::size_changed_print(QString name, int size)
{
     QTextStream out(stdout);
     out<<"File "<<name<<" changed. Size = "<<size<<endl;

}
void Output::file_deleted_print(QString name)
{
     QTextStream out(stdout);
     out<<"File "<<name<<" deleted"<<endl;

}
void Output::file_created_print(QString name, int size)
{
     QTextStream out(stdout);
     out<<"File "<<name<<" created. Size = "<<size<<endl;

}
