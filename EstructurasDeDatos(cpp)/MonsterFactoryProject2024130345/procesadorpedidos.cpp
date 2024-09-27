#include "procesadorpedidos.h"
#include "pedido.h"
// Constructor predeterminado
ProcesadorPedidos::ProcesadorPedidos() {}

// Función principal del hilo
void ProcesadorPedidos::run()
{
    QDir dirPedidos(pathPedidos);  //carpeta de pedidos
    QDir dirProcesados(pathProcesados);  //carpeta de procesados

    if (!dirPedidos.exists()) {
        qDebug() << "La carpeta de pedidos no existe o se puso un path incorrecto.";
        return;
    }

    if (!dirProcesados.exists()) {
        qDebug() << "La carpeta de procesados no existe o se puso un path incorrecto.";
        return;
    }


    while (true) {
        //coge los archivos de la carpeta y los pone como en una "lista".
        QFileInfoList listaArchivos = dirPedidos.entryInfoList(QDir::Files);

        if (!listaArchivos.isEmpty()) {
            QFileInfo archivoInfo = listaArchivos.at(0);  //el primer archivo de la lista
            procesarArchivo(archivoInfo.absoluteFilePath());  //lo procesa con la función creada, parámetro es el path al archivo.

            QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");

            QString nombreBase = archivoInfo.completeBaseName();
            QString extension = archivoInfo.suffix();
            QString nuevoNombreArchivo = nombreBase + "_" + timestamp + "." + extension;

            QString rutaDestino = dirProcesados.absoluteFilePath(nuevoNombreArchivo);
            QFile::rename(archivoInfo.absoluteFilePath(), rutaDestino);
        }

        QThread::sleep(1);
    }
}

void ProcesadorPedidos::procesarArchivo(const QString &filePath)
{
    QFile archivo(filePath);

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) { //si no se puede abrir el archivo en modo lectura.
        qDebug() << "No se pudo abrir el archivo para lectura.";
        return;
    }

    QTextStream in(&archivo);

    QString nombreCliente;
    QString clavePrioridad;
    QString numeroPedido;
    Lista<int>* monstruosSolicitados = new Lista<int>;

    int lineaActual = 0;

    while (!in.atEnd()) {
        QString linea = in.readLine();
        lineaActual++;

        if (lineaActual == 1) {
            nombreCliente = linea;
            qDebug() << "Cliente:" << nombreCliente;

        } else if (lineaActual == 2) {
            clavePrioridad = linea;
            qDebug() << "Clave de prioridad:" << clavePrioridad;

        } else if (lineaActual == 3) {
            numeroPedido = linea;
            qDebug() << "Número de pedido:" << numeroPedido;

        } else {
            if (linea == "INTELIGENCIA")
                monstruosSolicitados->insertarAlFinal(0);
            else if (linea == "DESTRUCCION")
                monstruosSolicitados->insertarAlFinal(1);
            else if (linea == "REGENERACION")
                monstruosSolicitados->insertarAlFinal(2);
            else if (linea == "FUERZA")
                monstruosSolicitados->insertarAlFinal(3);
            else if (linea == "MALDAD")
                monstruosSolicitados->insertarAlFinal(4);
            else if (linea == "VENENO")
                monstruosSolicitados->insertarAlFinal(5);
            else if (linea == "LOCURA")
                monstruosSolicitados->insertarAlFinal(6);
            else if (linea == "TECNOLOGIA")
                monstruosSolicitados->insertarAlFinal(7);
            else if (linea == "VELOCIDAD")
                monstruosSolicitados->insertarAlFinal(8);
            qDebug() << "Monstruo solicitado:" << linea;
        }
    }

    Pedido* nuevoPedido = new Pedido(nombreCliente,numeroPedido.toInt());
    Nodo<int>* tmp = monstruosSolicitados->primerNodo;
    while (tmp != nullptr){
        nuevoPedido ->monstruosPedidos->insertarAlFinal(tmp->dato);
        tmp = tmp->siguiente;
    }

    if (clavePrioridad == "1ST PROGRA") {
        listaPedidosPrioridad->insertarAlFinal(nuevoPedido);
        qDebug() << "Pedido prioritario añadido:" << nuevoPedido->numPedido;
    } else {
        listaPedidos->insertarAlFinal(nuevoPedido);
        qDebug() << "Pedido añadido:" << nuevoPedido->numPedido;
    }
    archivo.close();
}
