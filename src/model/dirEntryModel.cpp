#include "dirEntryModel.h"

DirEntryModel::DirEntryModel(QObject *parent) : QAbstractListModel(parent)
{

}

QAbstractItemModel * DirEntryModel::model()
{
    return this;
}

void DirEntryModel::addItem(const DirectoryEntry &val)
{

}

int DirEntryModel::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
}

QVariant DirEntryModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();

    auto it = m_data.begin();
    std::advance(it,index.row());
    return QVariant::fromValue(it->second);
}
