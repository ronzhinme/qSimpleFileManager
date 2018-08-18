#include "directoryEntry.h"

DirectoryEntry::DirectoryEntry()
{

}

DirectoryEntry::DirectoryEntry(QString name, int type)
{
    m_name = name;
    m_type = type;
}

QString DirectoryEntry::name() const
{
    return m_name;
}

int DirectoryEntry::type() const
{
    return m_type;
}
