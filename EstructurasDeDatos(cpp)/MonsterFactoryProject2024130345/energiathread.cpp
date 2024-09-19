#include "energiathread.h"

EnergiaThread::EnergiaThread() {}

void EnergiaThread::run(){
    while(true){
        // queueLabel -> setText(QString::number(colaEnergia->size()) + " de " + QString::number(capacidadSbx->value()));
        int secondsLeft = this->tiempoSbx->value();
        while(secondsLeft > 0){
            qDebug() << secondsLeft;
            if(!(this->corriendoChbx->isChecked())){
                if(!corriendoChbx->isEnabled()){ //si no está enabled, es porque en algun momento paró por overflow
                    if(capacidadSbx -> value() > colaEnergia->size()){
                        corriendoChbx->setChecked(true);
                        corriendoChbx->setEnabled(true);
                    }
                }
                QThread::sleep(1);
                continue;
            }
            countdownLabel->setText(QString::number(secondsLeft--));
            // secondsLeft--;

            QThread::sleep(1);
        }
        if(capacidadSbx -> value() <= colaEnergia->size()){
            corriendoChbx->setChecked(false);
            corriendoChbx->setEnabled(false);
            continue;
        }
        //cuando secondsLeft llega a 0, sigue aqui.

        int randomNumber = QRandomGenerator::global()->generate();
        mutexColaEnergia->lock();
        if(randomNumber%3==0){
            this->colaEnergia->encolar("Energia Oscura");
        } else if (randomNumber%2 == 1){
            this->colaEnergia->encolar("Energia Cosmica");
        } else{
            this->colaEnergia->encolar("Energia Elemental");
        }
        capacidadSbx->setMinimum(colaEnergia->size());
        mutexColaEnergia->unlock();
        //El mínimo de la capacidad debe ser la cantidad que hay en la cola. Esto para que no ocurra 12 de 10 por ejemplo.
    }
}
