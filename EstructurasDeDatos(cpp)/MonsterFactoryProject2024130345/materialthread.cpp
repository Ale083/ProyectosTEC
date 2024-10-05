#include "materialthread.h"

MaterialThread::MaterialThread() {}

void MaterialThread::run(){
    while(true){
        int secondsLeft = this->tiempoSbx->value();
        while(secondsLeft > 0){
            if(!(this->corriendoChbx->isChecked())){
                if(!corriendoChbx->isEnabled()){ //si no está enabled, es porque en algun momento paró por overflow
                    if(capacidadSbx -> value() > colaMaterial->size()){
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
        if(capacidadSbx -> value() <= colaMaterial->size()){
            corriendoChbx->setChecked(false);
            corriendoChbx->setEnabled(false);
            continue;
        }
        //cuando secondsLeft llega a 0, sigue aqui.
        int randomNumber = QRandomGenerator::global()->generate();
        mutexColaMaterial->lock();
        if(randomNumber%3==0){
            this->colaMaterial->encolar("Material Organico");
        } else if (randomNumber%2 == 1){
            this->colaMaterial->encolar("Material Metalico");
        } else{
            this->colaMaterial->encolar("Material Radioactivo");
        }
        capacidadSbx->setMinimum(colaMaterial->size());
        mutexColaMaterial->unlock();
        //El mínimo de la capacidad debe ser la cantidad que hay en la cola. Esto para que no ocurra 12 de 10 por ejemplo.
    }
}
