#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    leftDirDisplay = new getDirInfo();
    rightFileDisplay = new showFileInfo();
    ui->verticalLayout_3->addWidget(leftDirDisplay);
    ui->verticalLayout_4->addWidget(rightFileDisplay);
    currentPath = QString(QDir::currentPath());
    QObject::connect(this,SIGNAL(changeFilePath(QString)),leftDirDisplay,SLOT(changeCurrentPath(QString)));
    QObject::connect(this,SIGNAL(getAudioFilePath(QString)),rightFileDisplay,SLOT(getWorkPath(QString)));
    QObject::connect(rightFileDisplay,SIGNAL(clicked(const QModelIndex&)),this,SLOT(getAudioFileInfo(const QModelIndex&)));
    //qDebug()<<currentPath;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectPact_clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                        currentPath,
                                                        QFileDialog::ShowDirsOnly
                                                        | QFileDialog::DontResolveSymlinks);
    if(!dirPath.isEmpty()){
        currentPath = dirPath;
        emit changeFilePath(dirPath);
    }
}

void MainWindow::on_affirmPach_clicked()
{
    emit getAudioFilePath(currentPath);

}

void MainWindow::getAudioFileInfo(QModelIndex dataArr)
{
    QString fixPath = dataArr.data().toString();
    QString completePath = currentPath + QString("/") + fixPath;
    if(QFile::exists(completePath)){
        TagLib::FileRef f(completePath.toStdString().c_str());
        if(!f.isNull() && f.tag()) {
            TagLib::Tag *tag = f.tag();
            ui->title->setText(QString::fromLocal8Bit(tag->title().toCString()));
            ui->artist->setText(QString::fromLocal8Bit(tag->artist().toCString()));
            ui->album->setText(QString::fromLocal8Bit(tag->album().toCString()));
            ui->genre->setText(QString::fromLocal8Bit(tag->genre().toCString()));
            ui->year->setText(QString::number(tag->year()));
            ui->track->setText(QString::number(tag->track()));
        }
    }
}

void MainWindow::on_mod_clicked()
{
    QStringList filters;
    filters << "*.mp3";
    QDir currentDir(currentPath);
    currentDir.setNameFilters(filters);
    QStringList fileNameList = currentDir.entryList();
    foreach(QString e, fileNameList){
        QString completePath = currentPath + QString("/") + e;
        TagLib::FileRef f(completePath.toStdString().c_str());
        if(!f.isNull() && f.tag()){
            TagLib::Tag *tag = f.tag();
            tag->setArtist(ui->artist->text().toLocal8Bit().data());
            tag->setAlbum(ui->album->text().toLocal8Bit().data());
            tag->setTitle(e.split('.')[0].toLocal8Bit().data());
            tag->setGenre(ui->genre->text().toLocal8Bit().data());
            /*tag->setArtist(ui->artist->text().toStdString());
            tag->setAlbum(ui->album->text().toStdString());
            tag->setTitle(ui->title->text().toStdString());
            tag->setGenre(ui->genre->text().toStdString());*/
            tag->setYear(ui->year->text().toUInt());
        }
        f.file()->save();
    }
    QMessageBox::about(NULL, "完成", "完成!");
}
