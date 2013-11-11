#ifndef SHOWFILEINFO_H
#define SHOWFILEINFO_H

#include <QTreeView>
#include <QFileSystemModel>
#include <QDir>
#include <QString>
#include <QStringList>

#include <QDebug>

class showFileInfo : public QTreeView
{
    Q_OBJECT
public:
    explicit showFileInfo(QWidget *parent = 0);

public slots:
    void getWorkPath(QString selectPath);

private:
    QFileSystemModel *model;
    QModelIndex index;
};

#endif // SHOWFILEINFO_H
