#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Para que sirvan las bitácoras, mover el folder 'monsterFactoryFileBitacoras' al escritorio y cambiar con ctrl f -> replace, 'Proyecto Diseño', por el nombre de su compu";
    MainWindow w;
    w.show();
    return a.exec();
}
