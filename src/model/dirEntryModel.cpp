#include "dirEntryModel.h"
#include <QDebug>

DirEntryModel::DirEntryModel(QObject *parent) : QAbstractListModel(parent)
{
    setCurrentDirectory(QFileInfo(".").absolutePath());
}

QAbstractItemModel * DirEntryModel::model()
{
    return this;
}

const QString &DirEntryModel::currentDirectory() const
{
    return m_dir.dirName();
}

void DirEntryModel::setCurrentDirectory(const QString &val)
{
    m_dir.cd(val);
    Q_EMIT currentDirectoryChanged();
}

int DirEntryModel::rowCount(const QModelIndex &parent) const
{
    return m_dir.count();
}

QVariant DirEntryModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();

    return QVariant::fromValue(m_dir.entryInfoList()[index.row()].fileName());
}

