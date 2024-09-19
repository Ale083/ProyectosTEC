#include "refresh.h"

Refresh::Refresh() {}
void Refresh::run(){
    while(true){
        mutexColaEnergia->lock(); mutexColaMaterial->lock(); mutexColaMaldad->lock();
        lblColaMonstruos -> setText(QString::number(colaDeMonstruos->size()) + " de " + QString::number(sbxCapacidadColaDeMonstruos->value()));
        lblColaEnergia -> setText(QString::number(colaEnergia->size()) + " de " + QString::number(sbxCapacidadColaEnergia->value()));
        lblColaMaterial -> setText(QString::number(colaMaterial->size()) + " de " + QString::number(sbxCapacidadColaMaterial->value()));
        lblColaMaldad -> setText(QString::number(colaMaldad->size()) + " de " + QString::number(sbxCapacidadColaMaldad->value()));
        mutexColaEnergia->unlock(); mutexColaMaterial->unlock(); mutexColaMaldad->unlock();
        QThread::msleep(500);
    }
}
