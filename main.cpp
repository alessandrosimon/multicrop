#include "mainwindow.h"
#include <QApplication>

// TODO: implement snap to grid/limit to picture
//       make zoomable with mouse gestures
//       automatic filename/ending recognition

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
