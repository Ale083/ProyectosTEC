#ifndef ESTRUCTURAALMACEN_H
#define ESTRUCTURAALMACEN_H
#include "estructuras.h"
#include "estructuramonstruo.h"
struct Almacen{
public:
    Lista<Monstruo*>* almacen[9];
    int inteligenciaDisponibles;
    //...
    void insertarInteligencia(Monstruo* monstruo){
        almacen[0]->insertarAlFinal(monstruo);
        inteligenciaDisponibles++;
    }
    //Cada vez que entra un monstruo, desde el principio revisar la primera orden,
    /*
    Por ejemplo quiere 1 tipo 3, 2 tipo 4 y 1 tipo 3.
    un while (monstruosReservadosParaLaOrden != monstruos que quiere la orden).

    busca en el almacen uno por uno:
        revisa si hay tipo 3, si hay disponibles, entonces busca en el almacen.
        si encuentra alguno que no esté entregado, entonces revisa si está reservado para alguien, si no, entonces lo reserva para él, incrementa el número de "monstruosReservadosParaLaOrden".
        Revisa si hay tipo 4, pasa lo mismo digamo
    */

};

#endif // ESTRUCTURAALMACEN_H
