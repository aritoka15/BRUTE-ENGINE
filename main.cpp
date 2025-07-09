#include "mainwindow.h"
#include "win2kstyle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(new Win2kStyle());  // Now a is defined
    MainWindow w;
    w.show();
    return a.exec();
}
