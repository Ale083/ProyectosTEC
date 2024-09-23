#ifndef PEDIDO_H
#define PEDIDO_H
#include <QString>

#include "estructuras.h"

struct Pedido{
public:
    QString nombreCliente;
    int numPedido;
    Lista<int>* monstruosPedidos;

    Pedido(QString _nombreCliente, int _numPedido){
        nombreCliente = _nombreCliente;
        numPedido = _numPedido;
        monstruosPedidos = new Lista<int>;
    }
};
#endif // PEDIDO_H
