#ifndef ESTRUCTURAMONSTRUO_H
#define ESTRUCTURAMONSTRUO_H
#include <QString>
#include <QDateTime>
//QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
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

    Monstruo(int _consecutivo, QString energia, QString material, QString maldad, QString _tipo, bool _esBueno, QString _siEsBuenoPorque){
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
    }

    QString toString(){
        QString resultado = tipo + " de consecutivo " + QString::number(consecutivo) + " generado por la combinación de " + combinacion[0] + ", " + combinacion[1] + " y " + combinacion[2] + " en " + timestampCreacion;
        //TODO
        return resultado;
    }
};

#endif // ESTRUCTURAMONSTRUO_H
