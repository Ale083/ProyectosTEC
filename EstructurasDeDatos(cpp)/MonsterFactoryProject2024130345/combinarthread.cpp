#include "combinarthread.h"
// this->id = id;
// this->colaEnergia = colaEnergia;
// this->colaMaterial = colaMaterial;
// this->colaMaldad = colaMaldad;
// this->countdownLabel = countdownLabel;
// this->tiempoSbx = tiempoSbx;
// this->corriendoChbx = corriendoChbx;
// this->colaDeMonstruosLabel = colaDeMonstruosLabel;
// this->capacidadColaMonstruos = capacidadColaMonstruos;
// this->colaDeMonstruos = colaDeMonstruos;
CombinarThread::CombinarThread() {}

void CombinarThread::run(){
    while(true){
        // colaDeMonstruosLabel -> setText(QString::number(colaDeMonstruos->size()) + " de " + QString::number(capacidadColaMonstruos->value()));
        int secondsLeft = this->tiempoSbx->value();
        while(secondsLeft > 0){
            if(!(this->corriendoChbx->isChecked())){
                if(!corriendoChbx->isEnabled()){ //si no está enabled, es porque en algun momento paró por overflow
                    if(capacidadColaMonstruos -> value() > colaDeMonstruos->size()){
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
        if(capacidadColaMonstruos -> value() <= colaDeMonstruos->size()){
            corriendoChbx->setChecked(false);
            corriendoChbx->setEnabled(false);
            continue;
        }
        if(colaEnergia->isEmpty() || colaMaterial->isEmpty() || colaMaldad->isEmpty()){
            continue;
        }
        //cuando secondsLeft llega a 0, sigue aqui.
        mutexColaEnergia->lock(); mutexColaMaterial->lock(); mutexColaMaldad->lock();
        QString energia = colaEnergia->desencolar()->dato;
        QString material = colaMaterial->desencolar()->dato;
        QString maldad = colaMaldad->desencolar()->dato;
        mutexColaEnergia->unlock(); mutexColaMaterial->unlock(); mutexColaMaldad->unlock();

        //Combinaciones:
        mutexColaMonstruos->lock();
        if (energia == "Energia Cosmica" && material == "Material Organico" && maldad == "Maldad Astuta") {
            Monstruo* monstruo = new Monstruo(conteo++,energia,material,maldad,"Monstruo de Inteligencia",false,"",0);
            colaDeMonstruos->encolar(monstruo); //Inteligencia
            actualizarBitacora(monstruo->toStringColaMonstruos());
        }
        else if (energia == "Energia Elemental" && material == "Material Radioactivo" && maldad == "Maldad Caotica") {
            Monstruo* monstruo = new Monstruo(conteo++, energia, material, maldad, "Monstruo de Destruccion", false, "", 1);
            colaDeMonstruos->encolar(monstruo); //Destruccion
            actualizarBitacora(monstruo->toStringColaMonstruos());
        }
        else if (energia == "Energia Oscura" && material == "Material Organico" && maldad == "Maldad Despiadada") {
            Monstruo* monstruo = new Monstruo(conteo++, energia, material, maldad, "Monstruo de Regeneracion", false, "", 2);
            colaDeMonstruos->encolar(monstruo); //Regeneracion
            actualizarBitacora(monstruo->toStringColaMonstruos());
        }
        else if (energia == "Energia Elemental" && material == "Material Metalico" && maldad == "Maldad Despiadada") {
            Monstruo* monstruo = new Monstruo(conteo++, energia, material, maldad, "Monstruo de Fuerza", false, "", 3);
            colaDeMonstruos->encolar(monstruo); //Fuerza
            actualizarBitacora(monstruo->toStringColaMonstruos());
        }
        else if (energia == "Energia Oscura" && material == "Material Metalico" && maldad == "Maldad Astuta") {
            Monstruo* monstruo = new Monstruo(conteo++, energia, material, maldad, "Monstruo de Maldad", false, "", 4);
            colaDeMonstruos->encolar(monstruo); //Maldad
            actualizarBitacora(monstruo->toStringColaMonstruos());
        }
        else if (energia == "Energia Oscura" && material == "Material Radioactivo" && maldad == "Maldad Despiadada") {
            Monstruo* monstruo = new Monstruo(conteo++, energia, material, maldad, "Monstruo de Veneno", false, "", 5);
            colaDeMonstruos->encolar(monstruo); //Veneno
            actualizarBitacora(monstruo->toStringColaMonstruos());
        }
        else if (energia == "Energia Cosmica" && material == "Material Radioactivo" && maldad == "Maldad Caotica") {
            Monstruo* monstruo = new Monstruo(conteo++, energia, material, maldad, "Monstruo de Locura", false, "", 6);
            colaDeMonstruos->encolar(monstruo); //Locura
            actualizarBitacora(monstruo->toStringColaMonstruos());
        }
        else if (energia == "Energia Cosmica" && material == "Material Metalico" && maldad == "Maldad Astuta") {
            Monstruo* monstruo = new Monstruo(conteo++, energia, material, maldad, "Monstruo de Tecnologia", false, "", 7);
            colaDeMonstruos->encolar(monstruo); //Tecnologia
            actualizarBitacora(monstruo->toStringColaMonstruos());
        }
        else if (energia == "Energia Elemental" && material == "Material Organico" && maldad == "Maldad Caotica") {
            Monstruo* monstruo = new Monstruo(conteo++, energia, material, maldad, "Monstruo de Velocidad", false, "", 8);
            colaDeMonstruos->encolar(monstruo); //Velocidad
            actualizarBitacora(monstruo->toStringColaMonstruos());
        }
        else {
            Monstruo* monstruo = new Monstruo(conteo++, energia, material, maldad, "Monstruo Defectuoso", true, "combinacion", -1);
            basureroDeMonstruos->insertarAlFinal(monstruo);
            bitacoraBasurero(monstruo->toStringBasurero());
        }
        mutexColaMonstruos->unlock();
        capacidadColaMonstruos->setMinimum(colaDeMonstruos->size());
        //El mínimo de la capacidad debe ser la cantidad que hay en la cola. Esto para que no ocurra 12 de 10 por ejemplo.
    }
}


void CombinarThread::actualizarBitacora(QString historico){
    QFile archivo("C:\\Users\\Proyecto Diseño\\Desktop\\monsterFactoryFileBitacoras\\bitacoraColaMonstruos.txt");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream stream(&archivo);
        stream << historico << Qt::endl;
        archivo.close();
    } else {
        qDebug() << "Error al abrir el archivo";
    }
}

void CombinarThread::bitacoraBasurero(QString historico){
    QFile archivo("C:\\Users\\Proyecto Diseño\\Desktop\\monsterFactoryFileBitacoras\\bitacoraBasureroDeMonstruos.txt");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream stream(&archivo);
        stream << historico << Qt::endl;
        archivo.close();
    } else {
        qDebug() << "Error al abrir el archivo";
    }
}
