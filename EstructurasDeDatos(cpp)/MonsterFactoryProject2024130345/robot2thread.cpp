#include "robot2thread.h"

Robot2Thread::Robot2Thread() {}
void Robot2Thread::run(){
    while (true){
        QThread::sleep(1);

        if(checkBoxRobot2->isChecked() && !colaRobot2->isEmpty()){
            mutexColaRobot2->lock();
            Monstruo* monstruo = colaRobot2->desencolar()->dato;
            mutexColaRobot2->unlock();
            sbxColaRobot2->setMinimum(colaRobot2->size());
            int randomNumber = (QRandomGenerator::global()->generate())%101; //da un número entre 0-100
            if(randomNumber < sbxProbaRobot2->value()){
                actualizarBitacora(monstruo->toStringInspeccion("2"));
                mutexListaAlmacen->lock();
                listaAlmacen->insertarMonstruo(monstruo);
                mutexListaAlmacen->unlock();
                bitacoraAlmacen();
            } else {
                monstruo->esBueno = true;
                monstruo->siEsBuenoPorque = "rechazo";
                actualizarBitacora(monstruo->toStringInspeccion("2"));
                bitacoraBasurero(monstruo -> toStringRechazo());
                basureroDeMonstruos->insertarAlFinal(monstruo);
            }
        }
    }
}

void Robot2Thread::actualizarBitacora(QString historico){
    QFile archivo("C:\\Users\\Proyecto Diseño\\Desktop\\monsterFactoryFileBitacoras\\bitacoraRobot2.txt");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream stream(&archivo);
        stream << historico << Qt::endl;
        archivo.close();
    } else {
        qDebug() << "Error al abrir el archivo";
    }
}

void Robot2Thread::bitacoraBasurero(QString historico){
    QFile archivo("C:\\Users\\Proyecto Diseño\\Desktop\\monsterFactoryFileBitacoras\\bitacoraBasureroDeMonstruos.txt");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream stream(&archivo);
        stream << historico << Qt::endl;
        archivo.close();
    } else {
        qDebug() << "Error al abrir el archivo";
    }
}

void Robot2Thread::bitacoraAlmacen(){
    QFile archivo("C:\\Users\\Proyecto Diseño\\Desktop\\monsterFactoryFileBitacoras\\bitacoraAlmacen.txt");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&archivo);
        for (Lista<Monstruo*>* listaTipoMonstruo : listaAlmacen->almacen){
            Nodo<Monstruo*>* tmp = listaTipoMonstruo->primerNodo;
            while (tmp != nullptr){
                stream  << tmp->dato->toStringAlmacen() << Qt::endl;
                tmp = tmp ->siguiente;
            }
        }
        archivo.close();
    } else {
        qDebug() << "Error al abrir el archivo";
    }
}
