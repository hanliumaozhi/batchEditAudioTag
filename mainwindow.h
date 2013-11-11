#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QModelIndex>
#include <QFile>
#include <QStringList>
#include <QMessageBox>

#include <getdirinfo.h>
#include <showfileinfo.h>
#include <fileref.h>
#include <tag.h>
#include <tpropertymap.h>


#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void changeFilePath(QString pathOfOrd);
    void getAudioFilePath(QString pathOfOrd);

private slots:
    void on_selectPact_clicked();

    void on_affirmPach_clicked();

    void getAudioFileInfo(QModelIndex dataArr);

    void on_mod_clicked();

private:
    Ui::MainWindow *ui;
    getDirInfo *leftDirDisplay;
    showFileInfo *rightFileDisplay;
    QString currentPath;

};

#endif // MAINWINDOW_H
