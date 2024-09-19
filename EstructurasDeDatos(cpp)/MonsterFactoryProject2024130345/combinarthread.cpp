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
    QThread::sleep(1);
    while(true){
        colaDeMonstruosLabel -> setText(QString::number(colaDeMonstruos->size()) + " de " + QString::number(capacidadColaMonstruos->value()));
        int secondsLeft = this->tiempoSbx->value();
        while(secondsLeft > 0){
            colaDeMonstruosLabel -> setText(QString::number(colaDeMonstruos->size()) + " de " + QString::number(capacidadColaMonstruos->value()));
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
        countdownLabel->setText("0"); //Solo para que si se vea que llegó a 0, sino lo deja en 1 el label.
        int conteo = 1;
        mutexColaEnergia->lock(); mutexColaMaterial->lock(); mutexColaMaldad->lock();
        QString energia = colaEnergia->desencolar()->dato;
        QString material = colaMaterial->desencolar()->dato;
        QString maldad = colaMaldad->desencolar()->dato;
        mutexColaEnergia->unlock(); mutexColaMaterial->unlock(); mutexColaMaldad->unlock();

        //Combinaciones:
        if (energia == "Energia Cosmica" && material == "Material Organico" && maldad == "Maldad Astuta"){
            colaDeMonstruos->encolar(new Monstruo(conteo++,energia,material,maldad,"Monstruo de Inteligencia",false,"")); //Inteligencia
        }
        else if (energia == "Energia Elemental" && material == "Material Radioactivo" && maldad == "Maldad Caotica") {
            colaDeMonstruos->encolar(new Monstruo(conteo++, energia, material, maldad, "Monstruo de Destruccion", false, "")); //Destruccion
        }
        else if (energia == "Energia Oscura" && material == "Material Organico" && maldad == "Maldad Despiadada") {
            colaDeMonstruos->encolar(new Monstruo(conteo++, energia, material, maldad, "Monstruo de Regeneracion", false, "")); //Regeneracion
        }
        else if (energia == "Energia Elemental" && material == "Material Metalico" && maldad == "Maldad Despiadada") {
            colaDeMonstruos->encolar(new Monstruo(conteo++, energia, material, maldad, "Monstruo de Fuerza", false, "")); //Fuerza
        }
        else if (energia == "Energia Oscura" && material == "Material Metalico" && maldad == "Maldad Astuta") {
            colaDeMonstruos->encolar(new Monstruo(conteo++, energia, material, maldad, "Monstruo de Maldad", false, "")); //Maldad
        }
        else if (energia == "Energia Oscura" && material == "Material Radioactivo" && maldad == "Maldad Despiadada") {
            colaDeMonstruos->encolar(new Monstruo(conteo++, energia, material, maldad, "Monstruo de Veneno", false, "")); //Veneno
        }
        else if (energia == "Energia Cosmica" && material == "Material Radioactivo" && maldad == "Maldad Caotica") {
            colaDeMonstruos->encolar(new Monstruo(conteo++, energia, material, maldad, "Monstruo de Locura", false, "")); //Locura
        }
        else if (energia == "Energia Cosmica" && material == "Material Metalico" && maldad == "Maldad Astuta") {
            colaDeMonstruos->encolar(new Monstruo(conteo++, energia, material, maldad, "Monstruo de Tecnologia", false, "")); //Tecnologia
        }
        else if (energia == "Energia Elemental" && material == "Material Organico" && maldad == "Maldad Caotica") {
            colaDeMonstruos->encolar(new Monstruo(conteo++, energia, material, maldad, "Monstruo de Velocidad", false, "")); //Velocidad
        } else{
            basureroDeMonstruos->insertarAlFinal(new Monstruo(conteo++, energia, material, maldad, "Monstruo Defectuoso", true, "Por combinacion"));
        }

        capacidadColaMonstruos->setMinimum(colaDeMonstruos->size());
        //El mínimo de la capacidad debe ser la cantidad que hay en la cola. Esto para que no ocurra 12 de 10 por ejemplo.
    }
}
