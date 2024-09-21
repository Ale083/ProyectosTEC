#include "refresh.h"

Refresh::Refresh() {}
void Refresh::run(){
    while(true){
        mutexColaEnergia->lock(); mutexColaMaterial->lock(); mutexColaMaldad->lock();
        lblColaMonstruos -> setText(QString::number(colaDeMonstruos->size()) + " de " + QString::number(sbxCapacidadColaDeMonstruos->value()));
        lblColaEnergia -> setText(QString::number(colaEnergia->size()) + " de " + QString::number(sbxCapacidadColaEnergia->value()));
        lblColaMaterial -> setText(QString::number(colaMaterial->size()) + " de " + QString::number(sbxCapacidadColaMaterial->value()));
        lblColaMaldad -> setText(QString::number(colaMaldad->size()) + " de " + QString::number(sbxCapacidadColaMaldad->value()));
        lblContenido1->setText(QString::number(colaBandeja1->size()));
        lblContenido2->setText(QString::number(colaBandeja2->size()));
        lblContenido3->setText(QString::number(colaBandeja3->size()));
        lblContenido4->setText(QString::number(colaBandeja4->size()));
        lblColaRobot1->setText(QString::number(colaRobot1->size()) + " de " + QString::number(sbxColaRobot1->value()));
        lblColaRobot2->setText(QString::number(colaRobot2->size()) + " de " + QString::number(sbxColaRobot2->value()));
        lblAlmacenCant->setText("Se han almacenado " + QString::number(listaAlmacen->size()) + " monstruos");
        lblBasureroCant->setText("Se han botado " + QString::number(basureroDeMonstruos->size()) + " monstruos");
        mutexColaEnergia->unlock(); mutexColaMaterial->unlock(); mutexColaMaldad->unlock();
        QThread::msleep(500);
    }
}
