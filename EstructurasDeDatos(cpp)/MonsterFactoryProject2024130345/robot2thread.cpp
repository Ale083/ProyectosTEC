#include "robot2thread.h"
/*
        this->id = id;
        this->colaRobot1 = colaRobot1;
        this->checkBoxRobot1 = checkBoxRobot1;
        this->sbxTiempoRobot1 = sbxTiempoRobot1;
        this->colaRobot2 = colaRobot2;
        this->mutexColaRobot1 = mutexColaRobot1;
        this->mutexColaRobot2 = mutexColaRobot2;
*/
Robot2Thread::Robot2Thread() {}
void Robot2Thread::run(){
    while (true){
        QThread::sleep(1);

        if(checkBoxRobot2->isChecked() && !colaRobot2->isEmpty()){
            mutexColaRobot2->lock();
            Monstruo* monstruo = colaRobot2->desencolar()->dato;
            mutexColaRobot2->unlock();

            int randomNumber = (QRandomGenerator::global()->generate())%101; //da un número entre 0-100
            if(randomNumber < sbxProbaRobot2->value()){
                mutexListaAlmacen->lock();
                listaAlmacen->insertarAlFinal(monstruo);
                mutexListaAlmacen->unlock();
            } else {
                monstruo->esBueno = true;
                monstruo->siEsBuenoPorque = "Por rechazo";
                basureroDeMonstruos->insertarAlFinal(monstruo);
            }
        }
    }
}
