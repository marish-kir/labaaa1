#include "infofile.h"

InfoFile::InfoFile(QString _name)
{
    QFileInfo info(_name);
    name = _name;
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
int InfoFile::get_actual_size()
{
    QFileInfo info(name);
    return info.size();

}
bool InfoFile::get_actual_state()
{
    QFileInfo info(name);
    return info.exists();
}
void InfoFile::update_info()
{
    QFileInfo info(name);
    size = info.size();
    state = info.exists();
}
