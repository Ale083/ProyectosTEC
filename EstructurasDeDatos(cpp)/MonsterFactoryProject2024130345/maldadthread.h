#ifndef MALDADTHREAD_H
#define MALDADTHREAD_H
#include <QString>
#include <QLabel>
#include <QtCore>
#include <QSpinBox>
#include <QCheckBox>
#include <QProgressBar>
#include "estructuras.h"

class MaldadThread : public QThread
{
public:
    MaldadThread();
    MaldadThread(QString id, cola<QString>* colaMaldad, QLabel* queueLabel, QLabel* countdownLabel, QSpinBox* tiempoSbx, QSpinBox* capacidadSbx, QCheckBox* corriendoChbx) {
        this->id = id;
        this->colaMaldad = colaMaldad;
        this->queueLabel = queueLabel;
        this->countdownLabel = countdownLabel;
        this->tiempoSbx = tiempoSbx;
        this->capacidadSbx = capacidadSbx;
        this->corriendoChbx = corriendoChbx;
    }
    void run();

private:
    QString id;
    cola<QString>* colaMaldad;
    QLabel* queueLabel; // N de 25.
    QLabel* countdownLabel;
    QSpinBox* tiempoSbx;
    QSpinBox* capacidadSbx;
    QCheckBox* corriendoChbx;
};

#endif // MALDADTHREAD_H
