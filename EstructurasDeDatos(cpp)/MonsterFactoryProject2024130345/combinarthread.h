#ifndef COMBINARTHREAD_H
#define COMBINARTHREAD_H
#include <QString>
#include "estructuras.h"
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QtCore>
#include "estructuramonstruo.h"

class CombinarThread : public QThread
{
public:
    CombinarThread();
    CombinarThread(QString id, cola<QString>* colaEnergia, cola<QString>* colaMaterial, cola<QString>* colaMaldad, QLabel* countdownLabel,QSpinBox* tiempoSbx, QCheckBox* corriendoChbx, QLabel* colaDeMonstruosLabel, QSpinBox* capacidadColaMonstruos, cola<Monstruo*>* colaDeMonstruos, Lista<Monstruo*>* basureroDeMonstruos, QMutex* mutex, QSpinBox* capacidadColaEnergia, QSpinBox* capacidadColaMaterial, QSpinBox* capacidadColaMaldad,    QLabel* lblColaEnergia, QLabel* lblColaMaterial, QLabel* lblColaMaldad){
        this->id = id;
        this->colaEnergia = colaEnergia;
        this->colaMaterial = colaMaterial;
        this->colaMaldad = colaMaldad;
        this->countdownLabel = countdownLabel;
        this->tiempoSbx = tiempoSbx;
        this->corriendoChbx = corriendoChbx;
        this->colaDeMonstruosLabel = colaDeMonstruosLabel;
        this->capacidadColaMonstruos = capacidadColaMonstruos;
        this->colaDeMonstruos = colaDeMonstruos;
        this->basureroDeMonstruos = basureroDeMonstruos;
        this->mutex = mutex;
        this->capacidadColaEnergia = capacidadColaEnergia;
        this->capacidadColaMaterial = capacidadColaMaterial;
        this->capacidadColaMaldad = capacidadColaMaldad;
        this->lblColaEnergia = lblColaEnergia;
        this->lblColaMaterial = lblColaMaterial;
        this->lblColaMaldad = lblColaMaldad;
    }
    void run();
private:
    QString id;
    cola<QString>* colaEnergia;
    cola<QString>* colaMaterial;
    cola<QString>* colaMaldad;
    QLabel* countdownLabel;
    QSpinBox* tiempoSbx;
    QCheckBox* corriendoChbx;
    QLabel* colaDeMonstruosLabel;
    QSpinBox* capacidadColaMonstruos;
    cola<Monstruo*>* colaDeMonstruos;
    Lista<Monstruo*>* basureroDeMonstruos;
    QMutex* mutex;
    QSpinBox* capacidadColaEnergia;
    QSpinBox* capacidadColaMaterial;
    QSpinBox* capacidadColaMaldad;
    QLabel* lblColaEnergia;
    QLabel* lblColaMaterial;
    QLabel* lblColaMaldad;
};

#endif // COMBINARTHREAD_H
