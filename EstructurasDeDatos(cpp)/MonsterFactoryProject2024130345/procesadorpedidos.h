#ifndef PROCESADORPEDIDOS_H
#define PROCESADORPEDIDOS_H

#include <QThread>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "estructuras.h"
#include "pedido.h"

class ProcesadorPedidos : public QThread
{
public:
    ProcesadorPedidos();
    ProcesadorPedidos(QString pathPedidos, QString pathProcesados, Lista<Pedido*>* listaPedidos, Lista<Pedido*>* listaPedidosPrioridad){
        this->pathPedidos = pathPedidos;
        this->pathProcesados = pathProcesados;
        this->listaPedidos = listaPedidos;
        this->listaPedidosPrioridad = listaPedidosPrioridad;
    }

    void run();

private:
    QString pathPedidos;
    QString pathProcesados;
    Lista<Pedido*>* listaPedidos;
    Lista<Pedido*>* listaPedidosPrioridad;

    void procesarArchivo(const QString &filePath);
};

#endif // PROCESADORPEDIDOS_H
