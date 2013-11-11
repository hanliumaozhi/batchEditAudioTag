#include "showfileinfo.h"

showFileInfo::showFileInfo(QWidget *parent):
    QTreeView(parent)
{
    model = new QFileSystemModel;

    QStringList filters;
    filters << "*.mp3";
    model->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    model->setNameFilters(filters);
    model->setNameFilterDisables(false);


    model->setRootPath(QDir::currentPath());
    setModel(model);
    index = model->index(QDir::currentPath());
    setRootIndex(index);
    hideColumn(3);
    hideColumn(2);
    setColumnWidth(0,400);
}

void showFileInfo::getWorkPath(QString selectPath)
{
    index = model->index(selectPath);
    setRootIndex(index);
}
