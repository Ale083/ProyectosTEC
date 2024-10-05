#ifndef ESTRUCTURAMONSTRUO_H
#define ESTRUCTURAMONSTRUO_H
#include <QString>
#include <QDateTime>

struct Monstruo{
public:
    int consecutivo;
    QString combinacion[3];
    QString timestampCreacion;
    QString tipo;
    QString timestampInicioHorneado;
    QString timestampFinalHorneado;
    int bandejaDondeSeHorneo;
    int inspectoresQueLoReviso;
    bool esBueno;
    QString siEsBuenoPorque;
    bool entregado;
    int pedidoEntregado;
    QString timestampEntrega;
    int tipoEnInt;

    Monstruo(int _consecutivo, QString energia, QString material, QString maldad, QString _tipo, bool _esBueno, QString _siEsBuenoPorque, int _tipoEnInt){
        consecutivo = _consecutivo;
        combinacion[0] = energia;
        combinacion[1] = material;
        combinacion[2] = maldad;
        timestampCreacion = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        tipo = _tipo;
        timestampInicioHorneado = "";
        timestampFinalHorneado = "";
        bandejaDondeSeHorneo = 0;
        inspectoresQueLoReviso = 0;
        esBueno = _esBueno;
        siEsBuenoPorque = _siEsBuenoPorque;
        entregado = false;
        pedidoEntregado = 0;
        timestampEntrega = "";
        tipoEnInt = _tipoEnInt;
    }

    QString toStringColaMonstruos(){
        QString resultado = tipo + " de consecutivo " + QString::number(consecutivo) + " generado por la combinación de " + combinacion[0] + ", " + combinacion[1] + " y " + combinacion[2] + " en " + timestampCreacion + "\n";
        return resultado;
    }

    QString toStringBasurero(){
        QString resultado = tipo + " de consecutivo " + QString::number(consecutivo) + " generado por la combinación de " + combinacion[0] + ", " + combinacion[1] + " y " + combinacion[2] + " creado " + timestampCreacion + " fue botado al basurero por " + siEsBuenoPorque + "\n";
        return resultado;
    }

    QString toStringHorno(){
        QString resultado = tipo + " de consecutivo " + QString::number(consecutivo) + " empezo a hornearse " + timestampInicioHorneado + " y terminó " + timestampFinalHorneado + " en la bandeja " + QString::number(bandejaDondeSeHorneo) + "\n";
        return resultado;
    }

    QString toStringInspeccion(QString numRobot){
        QString timestampInspeccion = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        QString resultado = tipo + " de consecutivo " + QString::number(consecutivo) + " fue inspeccionado por el robot " + numRobot + " ";
        if (esBueno){
            resultado += "y fue rechazado";
        } else {
            resultado += "y la pasó exitosamente";
        }
        resultado += "\n";
        return resultado;
    }

    QString toStringAlmacen(){
        QString resultado = tipo + " de consecutivo " + QString::number(consecutivo) + " ";
        if(entregado){
            resultado += ("fue entregado al pedido " + QString::number(pedidoEntregado) + " en " + timestampEntrega);
        } else {
            resultado += "sigue en almacén";
        }
        resultado += "\n";
        return resultado;
    }

    QString toStringRechazo(){
        QString resultado = tipo + " de consecutivo " + QString::number(consecutivo) + " creado " + timestampCreacion + " fue botado al basurero por " + siEsBuenoPorque + "\n";
        return resultado;
    }
};

#endif // ESTRUCTURAMONSTRUO_H
