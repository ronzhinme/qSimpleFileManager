#ifndef FILEINFO_H
#define FILEINFO_H

#include <QObject>
#include <QFileInfo>

class FileInfo
{
    Q_GADGET
    Q_PROPERTY(QString fileName READ fileName CONSTANT)
    Q_PROPERTY(bool isDir READ isDir CONSTANT)
public:
    FileInfo() = default;
    explicit FileInfo(const QFileInfo & src);

    QString fileName() const;
    bool isDir() const;
private:
    QFileInfo m_fileinfo;
};
Q_DECLARE_METATYPE(FileInfo)

#endif // FILEINFO_H
