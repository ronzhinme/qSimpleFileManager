#include "fileInfo.h"

FileInfo::FileInfo(const QFileInfo & src) : m_fileinfo(src)
{

}

QString FileInfo::fileName() const
{
    return m_fileinfo.fileName();
}

bool FileInfo::isDir() const
{
    return m_fileinfo.isDir();
}


