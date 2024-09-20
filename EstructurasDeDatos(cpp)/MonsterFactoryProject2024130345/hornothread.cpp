#include "hornothread.h"
/*        this->id = id;
        this->colaDeMonstruos = colaDeMonstruos;

        this->colaBandeja1 = colaBandeja1;
        this->checkBoxBandeja1 = checkBoxBandeja1;
        this->lblContenido1 = lblContenido1;
        this->sbxBandeja1 = sbxBandeja1;

        this->colaBandeja2 = colaBandeja2;
        this->checkBoxBandeja2 = checkBoxBandeja2;
        this->lblContenido2 = lblContenido2;
        this->sbxBandeja2 = sbxBandeja2;

        this->colaBandeja3 = colaBandeja3;
        this->checkBoxBandeja3 = checkBoxBandeja3;
        this->lblContenido3 = lblContenido3;
        this->sbxBandeja3 = sbxBandeja3;

        this->colaBandeja4 = colaBandeja4;
        this->checkBoxBandeja4 = checkBoxBandeja4;
        this->lblContenido4 = lblContenido4;
        this->sbxBandeja4 = sbxBandeja4;

        this->lblCountdownHorno = lblCountdownHorno;
        this->sbxHorno = sbxHorno;
        this->mutexColaMonstruos = mutexColaMonstruos;
*/
HornoThread::HornoThread() {}
void HornoThread::run(){
    while(true){
        if(colaDeMonstruos->isEmpty()){
            QThread::sleep(1);
            continue;
        }
        if (checkBoxBandeja1->isChecked() && colaBandeja1->size() != sbxBandeja1->value()){
            colaBandeja1->encolar(colaDeMonstruos->desencolar()->dato);
            checkBoxBandeja1->setEnabled(false);
            sbxBandeja1->setEnabled(false);
            continue;
        }
        QThread::sleep(1);
        //en vez de while hacer 4 ifs, y ponerle continue
        //El while revisa las bandejas, cada una ve si está corriendo y si está no está lleno, es decir si aún le falta meter ahí. Está ordenado de la forma (bandeja1 || bandeja2...) Para que si a alguna le falte, entonces siga el while.
        //llenar las bandejas.
        //countdown
        //ponerles a los monstruos que ya están cocinados.
    }
}
