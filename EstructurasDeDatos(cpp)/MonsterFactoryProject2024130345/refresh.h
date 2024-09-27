#ifndef REFRESH_H
#define REFRESH_H

#include <QSpinBox>
#include <QLabel>
#include "estructuras.h"
#include "estructuramonstruo.h"
#include <QtCore>
#include "estructuraalmacen.h"


class Refresh : public QThread
{
public:
    Refresh();
    Refresh(cola<QString>* colaEnergia, cola<QString>* colaMaterial, cola<QString>* colaMaldad, QLabel* lblColaEnergia, QSpinBox* sbxCapacidadColaEnergia, QLabel* lblColaMaterial, QSpinBox* sbxCapacidadColaMaterial, QLabel* lblColaMaldad, QSpinBox* sbxCapacidadColaMaldad, cola<Monstruo*>* colaDeMonstruos, QLabel* lblColaMonstruos, QSpinBox* sbxCapacidadColaDeMonstruos, cola<Monstruo*>* colaBandeja1, QLabel* lblContenido1, cola<Monstruo*>* colaBandeja2, QLabel* lblContenido2, cola<Monstruo*>* colaBandeja3, QLabel* lblContenido3, cola<Monstruo*>* colaBandeja4, QLabel* lblContenido4, cola<Monstruo*>* colaRobot1, QLabel* lblColaRobot1, QSpinBox* sbxColaRobot1, cola<Monstruo*>* colaRobot2, QLabel* lblColaRobot2, QSpinBox* sbxColaRobot2, Almacen* listaAlmacen, QLabel* lblAlmacenCant, Lista<Monstruo*>* basureroDeMonstruos, QLabel* lblBasureroCant, QMutex* mutexColaEnergia, QMutex* mutexColaMaterial, QMutex* mutexColaMaldad){
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
        this->colaBandeja1 = colaBandeja1;
        this->lblContenido1 = lblContenido1;
        this->colaBandeja2 = colaBandeja2;
        this->lblContenido2 = lblContenido2;
        this->colaBandeja3 = colaBandeja3;
        this->lblContenido3 = lblContenido3;
        this->colaBandeja4 = colaBandeja4;
        this->lblContenido4 = lblContenido4;
        this->lblColaRobot1 = lblColaRobot1;
        this->colaRobot1 = colaRobot1;
        this->sbxColaRobot1 = sbxColaRobot1;
        this->lblColaRobot2 = lblColaRobot2;
        this->colaRobot2 = colaRobot2;
        this->sbxColaRobot2 = sbxColaRobot2;
        this->listaAlmacen = listaAlmacen;
        this->lblAlmacenCant = lblAlmacenCant;
        this->basureroDeMonstruos = basureroDeMonstruos;
        this->lblBasureroCant = lblBasureroCant;
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
    cola<Monstruo*>* colaBandeja1;
    QLabel* lblContenido1;
    cola<Monstruo*>* colaBandeja2;
    QLabel* lblContenido2;
    cola<Monstruo*>* colaBandeja3;
    QLabel* lblContenido3;
    cola<Monstruo*>* colaBandeja4;
    QLabel* lblContenido4;
    cola<Monstruo*>* colaRobot1;
    QLabel* lblColaRobot1;
    QSpinBox* sbxColaRobot1;
    cola<Monstruo*>* colaRobot2;
    QLabel* lblColaRobot2;
    QSpinBox* sbxColaRobot2;
    Almacen* listaAlmacen;
    QLabel* lblAlmacenCant;
    Lista<Monstruo*>* basureroDeMonstruos;
    QLabel* lblBasureroCant;
    QMutex* mutexColaEnergia;
    QMutex* mutexColaMaterial;
    QMutex* mutexColaMaldad;
};

#endif // REFRESH_H
