#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(bool iisdebug, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_process=new QProcess (this);
    pauseFlag=0;

    isdebug=iisdebug;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playPause_clicked()
{





    QString strCommand = pauseFlag?"mocp -U":"mocp -P";
    pauseFlag=!pauseFlag;

    m_process->start(strCommand);
    qDebug(m_process->readAllStandardOutput());

}
