#ifndef ENERGIATHREAD_H
#define ENERGIATHREAD_H
#include <QString>
#include <QLabel>
#include <QtCore>
#include <QSpinBox>
#include <QCheckBox>
#include "estructuras.h"
#include <QMutex>

class EnergiaThread : public QThread
{
public:
    EnergiaThread();
    EnergiaThread(QString id, cola<QString>* colaEnergia, QLabel* queueLabel, QLabel* countdownLabel,QSpinBox* tiempoSbx,QSpinBox* capacidadSbx, QCheckBox* corriendoChbx, QMutex* mutexColaEnergia){
        this->id = id;
        this->colaEnergia = colaEnergia;
        this->queueLabel = queueLabel;
        this->countdownLabel = countdownLabel;
        this->tiempoSbx = tiempoSbx;
        this->capacidadSbx = capacidadSbx;
        this->corriendoChbx = corriendoChbx;
        this->mutexColaEnergia = mutexColaEnergia;

    }
    void run();

private:
    QString id;
    cola<QString>* colaEnergia;
    QLabel* queueLabel; //N de 25.
    QLabel* countdownLabel;
    QSpinBox* tiempoSbx;
    QSpinBox* capacidadSbx;
    QCheckBox* corriendoChbx;
    QMutex* mutexColaEnergia;
};

#endif // ENERGIATHREAD_H
