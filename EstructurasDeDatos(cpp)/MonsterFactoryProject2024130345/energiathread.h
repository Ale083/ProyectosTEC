#ifndef ENERGIATHREAD_H
#define ENERGIATHREAD_H
#include <QString>
#include <QLabel>
#include <QtCore>
#include <QSpinBox>
#include <QCheckBox>
#include <QProgressBar>
#include "estructuras.h"


class EnergiaThread : public QThread
{
public:
    EnergiaThread();
    EnergiaThread(QString id, cola<QString>* colaEnergia, QLabel* queueLabel, QLabel* countdownLabel,QSpinBox* tiempoSbx,QSpinBox* capacidadSbx, QCheckBox* corriendoChbx,QProgressBar* pBarEnergia){
        this->id = id;
        this->colaEnergia = colaEnergia;
        this->queueLabel = queueLabel;
        this->countdownLabel = countdownLabel;
        this->tiempoSbx = tiempoSbx;
        this->capacidadSbx = capacidadSbx;
        this->corriendoChbx = corriendoChbx;
        this->pBarEnergia = pBarEnergia;
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
    QProgressBar* pBarEnergia;
};

#endif // ENERGIATHREAD_H
