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
#include "robot1thread.h"
#include "robot2thread.h"
#include "estructuraalmacen.h"
#include "procesadorpedidos.h"

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
    Almacen* almacen;
    Refresh* refresh;

    cola<Monstruo*>* colaBandeja1;
    cola<Monstruo*>* colaBandeja2;
    cola<Monstruo*>* colaBandeja3;
    cola<Monstruo*>* colaBandeja4;
    HornoThread* hornoThread;

    cola<Monstruo*>* colaRobot1;
    cola<Monstruo*>* colaRobot2;
    QMutex mutexColaRobot1;
    QMutex mutexColaRobot2;
    QMutex mutexListaAlmacen;

    Lista<Pedido*>* listaDePedidos;
    Lista<Pedido*>* listaDePedidosPrioridad;

    ProcesadorPedidos* procesadorPedidos;
    Robot1Thread* robot1Thread;
    Robot2Thread* robot2Thread;


private slots:
    void on_btnRefresh_clicked();

    void on_btnIniciar_clicked();

    void on_btnPausa_clicked();

    void on_btnResumir_clicked();

    void on_btnDetener_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
