#ifndef SHOWDIRINFO_H
#define SHOWDIRINFO_H

#include <QObject>
#include <QFileSystemModel>
#include <QDir>
#include <QTreeView>
#include <QSplitter>
#include <QVBoxLayout>

class showDirInfo : public QObject
{
    Q_OBJECT
public:
    explicit showDirInfo(QObject *parent = 0);
    QVBoxLayout *layout;

signals:

public slots:

private:
    QFileSystemModel *model;
    QTreeView *tree;
    QSplitter *splitter;
};

#endif // SHOWDIRINFO_H
