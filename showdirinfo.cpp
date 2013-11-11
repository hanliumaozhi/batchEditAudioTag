#include "showdirinfo.h"

showDirInfo::showDirInfo(QObject *parent) :
    QObject(parent)
{
    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    splitter = new QSplitter;
    tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));
    layout = new QVBoxLayout;
    layout->addWidget(tree);
}
