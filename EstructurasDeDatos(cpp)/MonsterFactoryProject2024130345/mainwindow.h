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
#include "refresh.h"
#include "hornothread.h"

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
    QMutex mutexColaEnergia;

    cola<QString>* materialCola;
    MaterialThread* materialThread;
    QMutex mutexColaMaterial;

    cola<QString>* maldadCola;
    MaldadThread* maldadThread;
    QMutex mutexColaMaldad;

    cola<Monstruo*>* colaDeMonstruos;
    Lista<Monstruo*>* basureroDeMonstruos;
    CombinarThread* combinarThread;
    QMutex  mutexColaMonstruos;

    Refresh* refresh;

    cola<Monstruo*>* colaBandeja1;
    cola<Monstruo*>* colaBandeja2;
    cola<Monstruo*>* colaBandeja3;
    cola<Monstruo*>* colaBandeja4;
    HornoThread* hornoThread;

private slots:
    void on_btnRefresh_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
