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
    ProcesadorPedidos(QString pathPedidos, QString pathProcesados, cola<Pedido*>* colaPedidos, cola<Pedido*>* colaPedidosPrioridad){
        this->pathPedidos = pathPedidos;
        this->pathProcesados = pathProcesados;
        this->colaPedidos = colaPedidos;
        this->colaPedidosPrioridad = colaPedidosPrioridad;
    }

    void run();

private:
    QString pathPedidos;
    QString pathProcesados;
    cola<Pedido*>* colaPedidos;
    cola<Pedido*>* colaPedidosPrioridad;

    void procesarArchivo(const QString &filePath);
};

#endif // PROCESADORPEDIDOS_H
