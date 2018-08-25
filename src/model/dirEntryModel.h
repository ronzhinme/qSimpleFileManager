#ifndef DIRENTRYMODEL_H
#define DIRENTRYMODEL_H

#include <QAbstractListModel>
#include <QDir>
#include "../struct/directoryEntry.h"

class DirEntryModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QAbstractItemModel * model READ model NOTIFY modelChanged)
    Q_PROPERTY(QString currentDirectory READ currentDirectory WRITE setCurrentDirectory NOTIFY currentDirectoryChanged)
public:
    DirEntryModel(QObject * parent = Q_NULLPTR);
    QAbstractItemModel * model();
    const QString & currentDirectory() const;

    void setCurrentDirectory(const QString & val);
private:
    QDir m_dir;
Q_SIGNALS:
    void modelChanged();
    void currentDirectoryChanged();

public:
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::EditRole) const override;
};

#endif // DIRENTRYMODEL_H
