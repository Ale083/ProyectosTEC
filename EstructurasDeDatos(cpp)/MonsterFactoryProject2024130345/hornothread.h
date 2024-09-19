#ifndef HORNOTHREAD_H
#define HORNOTHREAD_H
#include <QString>
#include <QLabel>
#include <QtCore>
#include <QSpinBox>
#include <QCheckBox>
#include "estructuras.h"
#include "estructuramonstruo.h"

class HornoThread : public QThread
{
public: //if !enabled or size = capacity
    HornoThread();
    HornoThread(QString id, cola<Monstruo*>* colaDeMonstruos, cola<Monstruo*>* colaBandeja1, QCheckBox* checkBoxBandeja1, QLabel* lblContenido1, QSpinBox* sbxBandeja1, cola<Monstruo*>* colaBandeja2, QCheckBox* checkBoxBandeja2, QLabel* lblContenido2, QSpinBox* sbxBandeja2, cola<Monstruo*>* colaBandeja3, QCheckBox* checkBoxBandeja3, QLabel* lblContenido3, QSpinBox* sbxBandeja3, cola<Monstruo*>* colaBandeja4, QCheckBox* checkBoxBandeja4, QLabel* lblContenido4, QSpinBox* sbxBandeja4, QLabel* lblCountdownHorno, QSpinBox* sbxHorno, QMutex* mutexColaMonstruos) {
        this->id = id;
        this->colaDeMonstruos = colaDeMonstruos;

        this->colaBandeja1 = colaBandeja1;
        this->checkBoxBandeja1 = checkBoxBandeja1;
        this->lblContenido1 = lblContenido1;
        this->sbxBandeja1 = sbxBandeja1;

        this->colaBandeja2 = colaBandeja2;
        this->checkBoxBandeja2 = checkBoxBandeja2;
        this->lblContenido2 = lblContenido2;
        this->sbxBandeja2 = sbxBandeja2;

        this->colaBandeja3 = colaBandeja3;
        this->checkBoxBandeja3 = checkBoxBandeja3;
        this->lblContenido3 = lblContenido3;
        this->sbxBandeja3 = sbxBandeja3;

        this->colaBandeja4 = colaBandeja4;
        this->checkBoxBandeja4 = checkBoxBandeja4;
        this->lblContenido4 = lblContenido4;
        this->sbxBandeja4 = sbxBandeja4;

        this->lblCountdownHorno = lblCountdownHorno;
        this->sbxHorno = sbxHorno;
        this->mutexColaMonstruos = mutexColaMonstruos;
    }

    void run();

private:
    QString id;
    cola<Monstruo*>* colaDeMonstruos;

    // Bandeja 1
    cola<Monstruo*>* colaBandeja1;
    QCheckBox* checkBoxBandeja1;
    QLabel* lblContenido1;
    QSpinBox* sbxBandeja1;

    // Bandeja 2
    cola<Monstruo*>* colaBandeja2;
    QCheckBox* checkBoxBandeja2;
    QLabel* lblContenido2;
    QSpinBox* sbxBandeja2;

    // Bandeja 3
    cola<Monstruo*>* colaBandeja3;
    QCheckBox* checkBoxBandeja3;
    QLabel* lblContenido3;
    QSpinBox* sbxBandeja3;

    // Bandeja 4
    cola<Monstruo*>* colaBandeja4;
    QCheckBox* checkBoxBandeja4;
    QLabel* lblContenido4;
    QSpinBox* sbxBandeja4;

    QLabel* lblCountdownHorno;
    QSpinBox* sbxHorno;

    QMutex* mutexColaMonstruos;
};

#endif // HORNOTHREAD_H
