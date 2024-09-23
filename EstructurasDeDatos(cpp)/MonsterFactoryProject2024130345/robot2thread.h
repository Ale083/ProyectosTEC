#ifndef ROBOT2THREAD_H
#define ROBOT2THREAD_H

#include <QString>
#include <QtCore>
#include <QSpinBox>
#include <QCheckBox>
#include "estructuras.h"
#include "estructuramonstruo.h"

class Robot2Thread : public QThread
{
public:
    Robot2Thread();
    Robot2Thread(QString id, cola<Monstruo*>* colaRobot2, QCheckBox* checkBoxRobot2, QSpinBox* sbxProbaRobot2, Lista<Monstruo*>* listaAlmacen, Lista<Monstruo*>* basureroDeMonstruos, QSpinBox* sbxColaRobot2, QMutex* mutexColaRobot2, QMutex* mutexListaAlmacen) {
        this->id = id;
        this->colaRobot2 = colaRobot2;
        this->checkBoxRobot2 = checkBoxRobot2;
        this->sbxProbaRobot2 = sbxProbaRobot2;
        this->listaAlmacen = listaAlmacen;
        this->basureroDeMonstruos = basureroDeMonstruos;
        this->sbxColaRobot2 = sbxColaRobot2;
        this->mutexColaRobot2 = mutexColaRobot2;
        this->mutexListaAlmacen = mutexListaAlmacen;
    }

    void run();
    void actualizarBitacora(QString historico);
    void bitacoraBasurero(QString historico);
    void bitacoraAlmacen();
private:
    QString id;

    cola<Monstruo*>* colaRobot2;
    QCheckBox* checkBoxRobot2;
    QSpinBox* sbxProbaRobot2;

    Lista<Monstruo*>* listaAlmacen;
    Lista<Monstruo*>* basureroDeMonstruos;
    QSpinBox* sbxColaRobot2;
    QMutex* mutexColaRobot2;
    QMutex* mutexListaAlmacen;
};

#endif // ROBOT2THREAD_H
