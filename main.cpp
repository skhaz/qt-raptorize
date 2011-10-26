
#include "mainwindow.h"



int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(assets);

    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();
    w.raptorize();

    return a.exec();
}
