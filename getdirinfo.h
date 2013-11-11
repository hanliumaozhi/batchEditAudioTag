#ifndef GETDIRINFO_H
#define GETDIRINFO_H

#include <QFileSystemModel>
#include <QDir>
#include <QTreeView>

#include <QDebug>

class getDirInfo : public QTreeView
{
    Q_OBJECT
public:
    explicit getDirInfo(QWidget *parent = 0);

signals:

public slots:
    void changeCurrentPath(QString selectPath);

private:
    QFileSystemModel *model;
    QModelIndex index;

};

#endif // GETDIRINFO_H
