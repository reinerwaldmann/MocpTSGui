#include "mainwindow.h"
#include <QApplication>
#include "QFile"
#include  <iostream>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QFile file("black.qss");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))

    {
        qDebug ("Error in opening stylesheet file");
    }

       QString StyleSheet;

       QTextStream in(&file); //File.readall DOESN'T WORK FSR
       //QString StyleSheet = QLatin1String(file.readAll()); THIS DOESN'T WORK,

       while (!in.atEnd()) {
           QString line = in.readLine();
           StyleSheet.append(line+'\n');
       }

       //sets stylesheet application-wide
    a.setStyleSheet(StyleSheet);

        //sets stylesheet window-wide
    //this prevents applying style to children windows
    //materials considering qss stuff are in google drive

    //  w.setStyleSheet(StyleSheet);


    bool deb=0;
    if (argc)
       {
        if ( !strcmp( argv[0], "-d" ))
        {
        deb=1;
        }

        }

    MainWindow w(deb);


//qDebug(StyleSheet.toStdString().c_str()); //debugging a QString




    w.show();
    
    return a.exec();
}
