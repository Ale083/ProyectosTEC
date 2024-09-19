#ifndef REFRESH_H
#define REFRESH_H

#include <QSpinBox>
#include <QLabel>
#include "estructuras.h"
#include "estructuramonstruo.h"
#include <QtCore>


class Refresh : public QThread
{
public:
    Refresh();
    Refresh(cola<QString>* colaEnergia, cola<QString>* colaMaterial, cola<QString>* colaMaldad, QLabel* lblColaEnergia, QSpinBox* sbxCapacidadColaEnergia, QLabel* lblColaMaterial, QSpinBox* sbxCapacidadColaMaterial, QLabel* lblColaMaldad, QSpinBox* sbxCapacidadColaMaldad, cola<Monstruo*>* colaDeMonstruos, QLabel* lblColaMonstruos, QSpinBox* sbxCapacidadColaDeMonstruos, QMutex* mutexColaEnergia, QMutex* mutexColaMaterial, QMutex* mutexColaMaldad){
        this->colaEnergia = colaEnergia;
        this->colaMaterial = colaMaterial;
        this->colaMaldad = colaMaldad;
        this->lblColaEnergia = lblColaEnergia;
        this->sbxCapacidadColaEnergia = sbxCapacidadColaEnergia;
        this->lblColaMaterial = lblColaMaterial;
        this->sbxCapacidadColaMaterial = sbxCapacidadColaMaterial;
        this->lblColaMaldad = lblColaMaldad;
        this->sbxCapacidadColaMaldad = sbxCapacidadColaMaldad;
        this->colaDeMonstruos = colaDeMonstruos;
        this->lblColaMonstruos = lblColaMonstruos;
        this->sbxCapacidadColaDeMonstruos = sbxCapacidadColaDeMonstruos;
        this->mutexColaEnergia = mutexColaEnergia;
        this->mutexColaMaterial = mutexColaMaterial;
        this->mutexColaMaldad = mutexColaMaldad;
    }
    void run();

private:
    cola<QString>* colaEnergia;
    cola<QString>* colaMaterial;
    cola<QString>* colaMaldad;
    QLabel* lblColaEnergia;
    QSpinBox* sbxCapacidadColaEnergia;
    QLabel* lblColaMaterial;
    QSpinBox* sbxCapacidadColaMaterial;
    QLabel* lblColaMaldad;
    QSpinBox* sbxCapacidadColaMaldad;
    cola<Monstruo*>* colaDeMonstruos;
    QLabel* lblColaMonstruos;
    QSpinBox* sbxCapacidadColaDeMonstruos;
    QMutex* mutexColaEnergia;
    QMutex* mutexColaMaterial;
    QMutex* mutexColaMaldad;
};

#endif // REFRESH_H
