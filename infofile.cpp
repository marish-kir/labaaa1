#include "infofile.h"


InfoFile::InfoFile()
{


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
