#include "dirEntryModel.h"

#include <QDebug>

DirEntryModel::DirEntryModel(QObject *parent) : QAbstractListModel(parent)
{
}

QAbstractItemModel * DirEntryModel::model()
{
    return this;
}

QString DirEntryModel::curDir() const
{
    return m_dir.absolutePath();
}

void DirEntryModel::doAction(const FileInfo & val)
{
    qDebug() << __FUNCTION__ << val.fileName() << " isDir:" << val.isDir();
    if(val.isDir())
    {
        m_dir.cd(val.fileName());
        Q_EMIT curDirChanged();
        Q_EMIT layoutChanged();
    }
}

void DirEntryModel::doAction(int row)
{
    if(!this->index(row,0).isValid())
        return;

    const FileInfo finfo(m_dir.entryInfoList()[row]);
    doAction(finfo);
}

int DirEntryModel::rowCount(const QModelIndex &parent) const
{
    return m_dir.count();
}

QVariant DirEntryModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    return QVariant::fromValue(FileInfo(m_dir.entryInfoList()[index.row()]));
}
