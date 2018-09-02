#ifndef DIRENTRYMODEL_H
#define DIRENTRYMODEL_H

#include <QAbstractListModel>
#include <QDir>

#include "../struct/fileInfo.h"

class DirEntryModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QAbstractItemModel * model READ model CONSTANT)
    Q_PROPERTY(QString curDir READ curDir NOTIFY curDirChanged)
public:
    DirEntryModel(QObject * parent = Q_NULLPTR);
    QAbstractItemModel * model();
    QString curDir() const;

    Q_INVOKABLE void doAction(const FileInfo & val);
private:
    QDir m_dir;
Q_SIGNALS:
    void curDirChanged();

public:
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::EditRole) const override;
};

#endif // DIRENTRYMODEL_H
