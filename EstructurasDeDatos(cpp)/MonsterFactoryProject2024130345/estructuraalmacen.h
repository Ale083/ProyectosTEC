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
};

#endif // ESTRUCTURAALMACEN_H
/*
Cada vez que entra un monstruo nuevo al almacén:
    Revisar todas las órdenes de prioridad:
        Mientras exista una orden en la cola de prioridad:
            Para cada tipo de monstruo que necesita la orden:
                Contar cuántos monstruos de ese tipo necesita la orden.
                Contar cuántos monstruos de ese tipo ya han sido reservados.

                Mientras el número de monstruos reservados < número de monstruos necesarios:
                    Buscar un monstruo disponible de ese tipo en el almacén.

                    Si se encuentra un monstruo no reservado:
                        Reservar el monstruo para la orden.
                        Incrementar el contador de monstruos reservados para esa orden.

                    Si no se encuentra un monstruo disponible:
                        Terminar la búsqueda para ese tipo.

            Después de intentar reservar para todos los tipos que necesita la orden:
                Si el número total de monstruos reservados == número total de monstruos necesarios:
                    Marcar la orden como "Lista para entrega".
                Si no:
                    La orden no puede completarse todavía.

    Después de revisar todas las órdenes de prioridad:
        Revisar las órdenes sin prioridad de la misma forma.

*/
