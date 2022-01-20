#include "mainwindow.h"
#include <QApplication>
#include "controller.h"
#include "model.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Model m;
    Controller c(&w, &m);
    w.resize(1000, 500);
    w.setWindowTitle("Camera");
    w.show();
    return a.exec();
}
