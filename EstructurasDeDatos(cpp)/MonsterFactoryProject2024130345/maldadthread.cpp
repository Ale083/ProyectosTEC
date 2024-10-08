#include "maldadthread.h"

MaldadThread::MaldadThread() {}

void MaldadThread::run() {
    while (true) {
        int secondsLeft = this->tiempoSbx->value();
        while (secondsLeft > 0) {
            if (!(this->corriendoChbx->isChecked())) {
                if (!corriendoChbx->isEnabled()) {  // Si no está habilitado, es porque se detuvo por overflow.
                    if (capacidadSbx->value() > colaMaldad->size()) {
                        corriendoChbx->setChecked(true);
                        corriendoChbx->setEnabled(true);
                    }
                }
                QThread::sleep(1);
                continue;
            }
            countdownLabel->setText(QString::number(secondsLeft--));

            QThread::sleep(1);
        }

        if (capacidadSbx->value() <= colaMaldad->size()) {
            corriendoChbx->setChecked(false);
            corriendoChbx->setEnabled(false);
            continue;
        }


        // Generar un número aleatorio y agregar diferentes tipos de maldad
        int randomNumber = QRandomGenerator::global()->generate();
        mutexColaMaldad->lock();
        if (randomNumber % 3 == 0) {
            this->colaMaldad->encolar("Maldad Despiadada");
        } else if (randomNumber % 2 == 1) {
            this->colaMaldad->encolar("Maldad Astuta");
        } else {
            this->colaMaldad->encolar("Maldad Caotica");
        }
        capacidadSbx->setMinimum(colaMaldad->size());
        mutexColaMaldad->unlock();
        // El mínimo de la capacidad debe ser la cantidad que hay en la cola. Esto para que no ocurra algo como "12 de 10".
    }
}
