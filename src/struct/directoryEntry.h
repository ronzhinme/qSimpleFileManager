#ifndef DIRECTORYENTRY_H
#define DIRECTORYENTRY_H

#include <QObject>

class DirectoryEntry
{
    Q_GADGET
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int type READ type CONSTANT)
public:
    DirectoryEntry();
    explicit DirectoryEntry(QString name, int type);

    QString name() const;
    int type() const;
private:
    QString m_name;
    int m_type;
};
Q_DECLARE_METATYPE(DirectoryEntry)

#endif // DIRECTORYENTRY_H
