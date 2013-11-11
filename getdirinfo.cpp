#include "getdirinfo.h"

getDirInfo::getDirInfo(QWidget *parent) :
    QTreeView(parent)
{
    model = new QFileSystemModel;
    //model->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    model->setRootPath(QDir::currentPath());
    setModel(model);
    index = model->index(QDir::currentPath());
    setRootIndex(index);
    hideColumn(3);
    hideColumn(2);
    hideColumn(1);
}

void getDirInfo::changeCurrentPath(QString selectPath)
{
    index = model->index(selectPath);
    setRootIndex(index);
}
