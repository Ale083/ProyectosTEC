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

        // Dormir el hilo por 1 segundo antes de revisar nuevamente
        QThread::sleep(1);
    }
}

// Función para procesar el archivo
void ProcesadorPedidos::procesarArchivo(const QString &filePath)
{

}
