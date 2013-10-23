#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool deb=0;
    if (argc)
       {
        if ( !strcmp( argv[0], "-d" ))
        {
        deb=1;
        }

        }

    MainWindow w(deb);

    w.show();
    
    return a.exec();
}
