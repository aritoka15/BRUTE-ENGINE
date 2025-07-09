#include "mainwindow.h"
#include "win2kstyle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Win2kStyle* style = new Win2kStyle();
    a.setStyle(style);                     // Aplica el estilo personalizado
    a.setPalette(style->standardPalette()); // Aplica los colores beige tipo Win2000

    MainWindow w;
    w.show();

    return a.exec();
}

