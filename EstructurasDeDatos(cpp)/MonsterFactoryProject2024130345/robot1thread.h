#ifndef ROBOT1THREAD_H
#define ROBOT1THREAD_H

#include <QString>
#include <QtCore>
#include <QSpinBox>
#include <QCheckBox>
#include "estructuras.h"
#include "estructuramonstruo.h"

class Robot1Thread : public QThread
{
public:
    Robot1Thread();
    Robot1Thread(QString id, cola<Monstruo*>* colaRobot1, QCheckBox* checkBoxRobot1, QSpinBox* sbxProbaRobot1, cola<Monstruo*>* colaRobot2, Lista<Monstruo*>* basureroDeMonstruos, QMutex* mutexColaRobot1, QMutex* mutexColaRobot2) {
        this->id = id;
        this->colaRobot1 = colaRobot1;
        this->checkBoxRobot1 = checkBoxRobot1;
        this->sbxProbaRobot1 = sbxProbaRobot1;
        this->colaRobot2 = colaRobot2;
        this->mutexColaRobot1 = mutexColaRobot1;
        this->mutexColaRobot2 = mutexColaRobot2;
        this->basureroDeMonstruos = basureroDeMonstruos;
    }

    void run();

private:
    QString id;

    cola<Monstruo*>* colaRobot1;
    QCheckBox* checkBoxRobot1;
    QSpinBox* sbxProbaRobot1;

    cola<Monstruo*>* colaRobot2;
    Lista<Monstruo*>* basureroDeMonstruos;
    QMutex* mutexColaRobot1;
    QMutex* mutexColaRobot2;
};

#endif // ROBOT1THREAD_H
