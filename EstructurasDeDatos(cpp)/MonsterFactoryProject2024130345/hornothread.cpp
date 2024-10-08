#include "hornothread.h"

HornoThread::HornoThread() {}
void HornoThread::run(){
    while(true){
        if(colaDeMonstruos->isEmpty() || (!checkBoxBandeja1->isChecked() && !checkBoxBandeja2->isChecked() && !checkBoxBandeja3->isChecked() && !checkBoxBandeja4->isChecked())){ //Si cola de monstruos empty o si todas las bandejas están deshabilitadas.
            QThread::sleep(1);
            continue;
        }
        if (checkBoxBandeja1->isChecked() && colaBandeja1->size() != sbxBandeja1->value()){
            mutexColaMonstruos->lock(); colaBandeja1->encolar(colaDeMonstruos->desencolar()->dato); mutexColaMonstruos->unlock();
            checkBoxBandeja1->setEnabled(false);
            sbxBandeja1->setEnabled(false);
            QThread::sleep(1);
            continue;
        } else if (checkBoxBandeja2->isChecked() && colaBandeja2->size() != sbxBandeja2->value()) {
            mutexColaMonstruos->lock(); colaBandeja2->encolar(colaDeMonstruos->desencolar()->dato); mutexColaMonstruos->unlock();
            checkBoxBandeja2->setEnabled(false);
            sbxBandeja2->setEnabled(false);
            QThread::sleep(1);
            continue;
        } else if (checkBoxBandeja3->isChecked() && colaBandeja3->size() != sbxBandeja3->value()) {
            mutexColaMonstruos->lock(); colaBandeja3->encolar(colaDeMonstruos->desencolar()->dato); mutexColaMonstruos->unlock();
            checkBoxBandeja3->setEnabled(false);
            sbxBandeja3->setEnabled(false);
            QThread::sleep(1);
            continue;
        } else if (checkBoxBandeja4->isChecked() && colaBandeja4->size() != sbxBandeja4->value()) {
            mutexColaMonstruos->lock(); colaBandeja4->encolar(colaDeMonstruos->desencolar()->dato); mutexColaMonstruos->unlock();
            checkBoxBandeja4->setEnabled(false);
            sbxBandeja4->setEnabled(false);
            QThread::sleep(1);
            continue;
        }

        checkBoxBandeja1->setEnabled(false); checkBoxBandeja2->setEnabled(false); checkBoxBandeja3->setEnabled(false); checkBoxBandeja4->setEnabled(false);
        sbxBandeja1->setEnabled(false); sbxBandeja2->setEnabled(false); sbxBandeja3->setEnabled(false); sbxBandeja4->setEnabled(false);
        int secondsLeft = this->sbxHorno->value();
        QString timestampInicioHorneado = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        while(secondsLeft > 0){
            if(running){
                lblCountdownHorno->setText(QString::number(secondsLeft--));
            }
            QThread::sleep(1);
        }

        lblCountdownHorno->setText(QString::number(sbxHorno->value()));

        while(!colaBandeja1->isEmpty()){
            while(colaRobot1->size() == sbxColaRobot1->value()) { QThread::sleep(1);}
            Monstruo* monstruo = colaBandeja1 -> desencolar()->dato;
            monstruo -> bandejaDondeSeHorneo = 1;
            monstruo -> timestampInicioHorneado = timestampInicioHorneado;
            monstruo -> timestampFinalHorneado = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            actualizarBitacora(monstruo->toStringHorno());
            mutexColaRobot1->lock(); colaRobot1 -> encolar(monstruo); mutexColaRobot1->unlock();
            sbxColaRobot1->setMinimum(colaRobot1->size());
        }

        while (!colaBandeja2->isEmpty()) {
            while(colaRobot1->size() == sbxColaRobot1->value()) { QThread::sleep(1);}
            Monstruo* monstruo = colaBandeja2->desencolar()->dato;
            monstruo->bandejaDondeSeHorneo = 2;
            monstruo->timestampInicioHorneado = timestampInicioHorneado;
            monstruo->timestampFinalHorneado = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            actualizarBitacora(monstruo->toStringHorno());
            mutexColaRobot1->lock(); colaRobot1 -> encolar(monstruo); mutexColaRobot1->unlock();
            sbxColaRobot1->setMinimum(colaRobot1->size());
        }

        while (!colaBandeja3->isEmpty()) {
            while(colaRobot1->size() == sbxColaRobot1->value()) { QThread::sleep(1);}
            Monstruo* monstruo = colaBandeja3->desencolar()->dato;
            monstruo->bandejaDondeSeHorneo = 3;
            monstruo->timestampInicioHorneado = timestampInicioHorneado;
            monstruo->timestampFinalHorneado = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            actualizarBitacora(monstruo->toStringHorno());
            mutexColaRobot1->lock(); colaRobot1 -> encolar(monstruo); mutexColaRobot1->unlock();
            sbxColaRobot1->setMinimum(colaRobot1->size());
        }

        while (!colaBandeja4->isEmpty()) {
            while(colaRobot1->size() == sbxColaRobot1->value()) { QThread::sleep(1);}
            Monstruo* monstruo = colaBandeja4->desencolar()->dato;
            monstruo->bandejaDondeSeHorneo = 4;
            monstruo->timestampInicioHorneado = timestampInicioHorneado;
            monstruo->timestampFinalHorneado = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            actualizarBitacora(monstruo->toStringHorno());
            mutexColaRobot1->lock(); colaRobot1 -> encolar(monstruo); mutexColaRobot1->unlock();
            sbxColaRobot1->setMinimum(colaRobot1->size());
        }

        checkBoxBandeja1->setEnabled(true); checkBoxBandeja2->setEnabled(true); checkBoxBandeja3->setEnabled(true); checkBoxBandeja4->setEnabled(true);
        sbxBandeja1->setEnabled(true); sbxBandeja2->setEnabled(true); sbxBandeja3->setEnabled(true); sbxBandeja4->setEnabled(true);
        QThread::sleep(5); //Cooldown, además da tiempo para que el usuario deshabilite bandejas si quiere.
    }
}

void HornoThread::actualizarBitacora(QString historico){
    QFile archivo("C:\\Users\\Proyecto Diseño\\Desktop\\monsterFactoryFileBitacoras\\bitacoraHorno.txt");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream stream(&archivo);
        stream << historico << Qt::endl;
        archivo.close();
    } else {
        qDebug() << "Error al abrir el archivo";
    }
}
