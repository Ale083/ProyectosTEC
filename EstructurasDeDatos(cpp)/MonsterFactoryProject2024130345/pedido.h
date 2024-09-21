#ifndef PEDIDO_H
#define PEDIDO_H
#include <QString>
#include "estructuramonstruo.h"

#include "estructuras.h"

struct Pedido{
public:
    QString nombreCliente;
    bool prioridad;
    int numPedido;
    Lista<Monstruo*>* monstruosPedidos;

    Pedido(QString _nombreCliente, bool _prioridad, int _numPedido){
        nombreCliente = _nombreCliente;
        prioridad = _prioridad;
        numPedido = _numPedido;
        monstruosPedidos = new Lista<Monstruo*>;
    }
};
#endif // PEDIDO_H
