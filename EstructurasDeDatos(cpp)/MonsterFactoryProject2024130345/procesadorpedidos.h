#ifndef PROCESADORPEDIDOS_H
#define PROCESADORPEDIDOS_H

#include <QThread>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "estructuramonstruo.h"
#include "estructuras.h"

class ProcesadorPedidos : public QThread
{
public:
    ProcesadorPedidos();
    ProcesadorPedidos(QString pathPedidos, QString pathProcesados, cola<Monstruo*> colaPedidos, cola<Monstruo*> colaPedidosPrioridad){
        this->pathPedidos = pathPedidos;
        this->pathProcesados = pathProcesados;
        this->colaPedidos = colaPedidos;
        this->colaPedidosPrioridad = colaPedidosPrioridad;
    }

    void run();

private:
    QString pathPedidos;
    QString pathProcesados;
    cola<Monstruo*> colaPedidos;
    cola<Monstruo*> colaPedidosPrioridad;

    void procesarArchivo(const QString &filePath);
};

#endif // PROCESADORPEDIDOS_H
