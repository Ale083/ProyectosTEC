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
    CombinarThread(QString id, cola<QString>* colaEnergia, cola<QString>* colaMaterial, cola<QString>* colaMaldad, QLabel* countdownLabel,QSpinBox* tiempoSbx, QCheckBox* corriendoChbx, QLabel* colaDeMonstruosLabel, QSpinBox* capacidadColaMonstruos, cola<Monstruo*>* colaDeMonstruos, Lista<Monstruo*>* basureroDeMonstruos, QMutex* mutexColaEnergia, QMutex* mutexColaMaterial, QMutex* mutexColaMaldad, QMutex* mutexColaMonstruos){
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
        this->mutexColaEnergia = mutexColaEnergia;
        this->mutexColaMaterial = mutexColaMaterial;
        this->mutexColaMaldad = mutexColaMaldad;
        this->mutexColaMonstruos = mutexColaMonstruos;
        this->conteo = 1;
    }
    void run();
    void actualizarBitacora(QString historico);
    void bitacoraBasurero(QString historico);
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
    QMutex* mutexColaEnergia;
    QMutex* mutexColaMaterial;
    QMutex* mutexColaMaldad;
    QMutex* mutexColaMonstruos;
    int conteo;
};

#endif // COMBINARTHREAD_H
