#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(bool iisdebug, QWidget *parent=0);
    ~MainWindow();
    bool isdebug;

    QProcess*  m_process;


    bool pauseFlag;
    
private slots:
    void on_playPause_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
