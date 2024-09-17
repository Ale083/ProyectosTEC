#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMutex>

#include "energiathread.h"
#include "estructuras.h"
#include "materialthread.h"
#include "maldadthread.h"
#include "combinarthread.h"

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    cola<QString>* energiaCola;
    EnergiaThread* energiaThread;

    cola<QString>* materialCola;
    MaterialThread* materialThread;

    cola<QString>* maldadCola;
    MaldadThread* maldadThread;

    cola<Monstruo*>* colaDeMonstruos;
    Lista<Monstruo*>* basureroDeMonstruos;
    CombinarThread* combinarThread;

    QMutex mutex;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
