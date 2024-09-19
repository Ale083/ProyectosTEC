#ifndef MATERIALTHREAD_H
#define MATERIALTHREAD_H
#include <QString>
#include <QLabel>
#include <QtCore>
#include <QSpinBox>
#include <QCheckBox>
#include <QProgressBar>
#include "estructuras.h"

class MaterialThread : public QThread
{
public:
    MaterialThread();
    MaterialThread(QString id, cola<QString>* colaMaterial, QLabel* queueLabel, QLabel* countdownLabel,QSpinBox* tiempoSbx,QSpinBox* capacidadSbx, QCheckBox* corriendoChbx,QMutex* mutexColaMaterial){
        this->id = id;
        this->colaMaterial = colaMaterial;
        this->queueLabel = queueLabel;
        this->countdownLabel = countdownLabel;
        this->tiempoSbx = tiempoSbx;
        this->capacidadSbx = capacidadSbx;
        this->corriendoChbx = corriendoChbx;
        this->mutexColaMaterial = mutexColaMaterial;
    }
    void run();

private:
    QString id;
    cola<QString>* colaMaterial;
    QLabel* queueLabel; //N de 25.
    QLabel* countdownLabel;
    QSpinBox* tiempoSbx;
    QSpinBox* capacidadSbx;
    QCheckBox* corriendoChbx;
    QMutex* mutexColaMaterial;
};

#endif // MATERIALTHREAD_H
