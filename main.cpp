#include "mainwindow.h"
#include "win2kstyle.h"
#include "qfontdatabase.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int fontId = QFontDatabase::addApplicationFont("C:/Users/Lenovo/OneDrive/Documentos/MyC++/BRUTE engine QT/bruteEngine/fonts/DotGothic16-Regular.ttf");
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont retroFont(fontFamily, 10); // o 12 si lo prefieres más grande
    qDebug() << "Usando fuente:" << retroFont.family();
    if (fontId == -1) qDebug() << "⚠️ No se pudo cargar la fuente";


    a.setFont(retroFont);


    Win2kStyle* style = new Win2kStyle();
    a.setStyle(style);                     // Aplica el estilo personalizado
    a.setPalette(style->standardPalette()); // Aplica los colores beige tipo Win2000

    MainWindow w;
    w.show();

    return a.exec();
}

