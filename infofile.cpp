#include "infofile.h"


InfoFile::InfoFile()
{


}
InfoFile::InfoFile(QString _name)
{
    QFileInfo info(_name);
    size = info.size();
    state = info.exists();
}
int InfoFile::get_size()
{
    return size;
}
QString InfoFile::get_name()
{
    return name;
}
bool InfoFile::get_state()
{
    return state;
}
