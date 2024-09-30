#include "robot1thread.h"
/*
        this->id = id;
        this->colaRobot1 = colaRobot1;
        this->checkBoxRobot1 = checkBoxRobot1;
        this->sbxTiempoRobot1 = sbxTiempoRobot1;
        this->colaRobot2 = colaRobot2;
        this->mutexColaRobot1 = mutexColaRobot1;
        this->mutexColaRobot2 = mutexColaRobot2;
*/
Robot1Thread::Robot1Thread() {}
void Robot1Thread::run(){
    while (true){
        QThread::sleep(1);
        if(checkBoxRobot1->isChecked() && !colaRobot1->isEmpty() && colaRobot2->size() != sbxColaRobot2->value()) { //la ultima cond, es que el segundo robot no esté lleno.
            mutexColaRobot1->lock();
            Monstruo* monstruo = colaRobot1->desencolar()->dato;
            mutexColaRobot1->unlock();
            sbxColaRobot1->setMinimum(colaRobot1->size());
            int randomNumber = (QRandomGenerator::global()->generate())%101; //da un número entre 0-100
            if(randomNumber < sbxProbaRobot1->value()){
                monstruo->inspectoresQueLoReviso = 2;
                actualizarBitacora(monstruo->toStringInspeccion("1"));
                mutexColaRobot2->lock();
                colaRobot2->encolar(monstruo);
                mutexColaRobot2->unlock();
            } else {
                monstruo->inspectoresQueLoReviso = 1;
                monstruo->esBueno = true;
                monstruo->siEsBuenoPorque = "rechazo";
                actualizarBitacora(monstruo->toStringInspeccion("1"));
                bitacoraBasurero(monstruo -> toStringRechazo());
                basureroDeMonstruos->insertarAlFinal(monstruo);
            }
        }
    }
}

void Robot1Thread::actualizarBitacora(QString historico){
    QFile archivo("C:\\Users\\Proyecto Diseño\\Desktop\\monsterFactoryFileBitacoras\\bitacoraRobot1.txt");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream stream(&archivo);
        stream << historico << Qt::endl;
        archivo.close();
    } else {
        qDebug() << "Error al abrir el archivo";
    }
}

void Robot1Thread::bitacoraBasurero(QString historico){
    QFile archivo("C:\\Users\\Proyecto Diseño\\Desktop\\monsterFactoryFileBitacoras\\bitacoraBasureroDeMonstruos.txt");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream stream(&archivo);
        stream << historico << Qt::endl;
        archivo.close();
    } else {
        qDebug() << "Error al abrir el archivo";
    }
}
