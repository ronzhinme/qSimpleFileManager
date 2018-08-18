#ifndef DIRENTRYMODEL_H
#define DIRENTRYMODEL_H

#include <QAbstractListModel>
#include <unordered_map>
#include "../struct/directoryEntry.h"

class DirEntryModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QAbstractItemModel * model READ model NOTIFY modelChanged)
public:
    DirEntryModel(QObject * parent = Q_NULLPTR);
    QAbstractItemModel * model();
    void addItem(const DirectoryEntry & val);
private:
    std::unordered_map<std::string, DirectoryEntry> m_data;
Q_SIGNALS:
    void modelChanged();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::EditRole) const;
};

#endif // DIRENTRYMODEL_H
