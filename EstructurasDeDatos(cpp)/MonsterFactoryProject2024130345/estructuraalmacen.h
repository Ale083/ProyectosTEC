    #ifndef ESTRUCTURAALMACEN_H
#define ESTRUCTURAALMACEN_H
#include "estructuras.h"
#include "estructuramonstruo.h"
#include "pedido.h"
#include <QCheckBox>

struct Almacen {
public:
    Lista<Monstruo*>* almacen[9];
    int size;



    Almacen(Lista<Pedido*>* listaDePedidos, Lista<Pedido*>* listaDePedidosPrioridad, QCheckBox* checkBoxEntregas) {
        for (int i = 0; i < 9; i++) {
            almacen[i] = new Lista<Monstruo*>;
        }
        this->listaDePedidos = listaDePedidos;
        this->listaDePedidosPrioridad = listaDePedidosPrioridad;
        this->checkBoxEntregas = checkBoxEntregas;
        size = 0;
    }


    void insertarMonstruo(Monstruo* monstruo) {

        size++;
        almacen[monstruo->tipoEnInt]->insertarAlFinal(monstruo);
        if(checkBoxEntregas->isChecked()){
            revisarPedidosPendientes();
        }
    }

private:
    Lista<Pedido*>* listaDePedidos;
    Lista<Pedido*>* listaDePedidosPrioridad;
    QCheckBox* checkBoxEntregas;


    void revisarPedidosPendientes() {

        if (!procesarListaDePedidos(listaDePedidosPrioridad)) {
            procesarListaDePedidos(listaDePedidos);
        }
    }


    bool procesarListaDePedidos(Lista<Pedido*>* listaPedidos) {
        Nodo<Pedido*>* pedidoNodo = listaPedidos->primerNodo;
        Pedido* primerPedido;
        if(listaDePedidosPrioridad->size() != 0){
            primerPedido = listaDePedidosPrioridad->primerNodo->dato;
        } else {
            primerPedido = pedidoNodo ? pedidoNodo->dato : nullptr;  //revisa si pedidoNodo es válido, si si, entonces guarda ->dato
        }


        while (pedidoNodo != nullptr) {
            bool seEntregoPedido = false;
            Pedido* pedido = pedidoNodo->dato;

            if (pedido == primerPedido || verificarSuficientesMonstruosSinAfectar(primerPedido, pedido)) {
                if (verificarPedidoCompleto(pedido)) {

                    reservarMonstruosParaPedido(pedido);
                    //quitar pedido de la lista

                    seEntregoPedido = true;


                } else {
                }
            } else {
            }

            if(seEntregoPedido){
                listaPedidos->borrarNodo(pedidoNodo);
                return true;
            }
            pedidoNodo = pedidoNodo->siguiente;

        }

        return false;
    }

    // Verifica si el pedido tiene suficientes monstruos sin quitarle al primer pedido de la lista
    bool verificarSuficientesMonstruosSinAfectar(Pedido* primerPedido, Pedido* pedido) {
        Nodo<int>* tipoNodo = pedido->monstruosPedidos->primerNodo;

        while (tipoNodo != nullptr) {
            int tipoMonstruo = tipoNodo->dato;
            int monstruosNecesariosParaPedido = contarMonstruosNecesarios(pedido, tipoMonstruo);
            int monstruosReservadosParaPrimero = contarMonstruosReservados(primerPedido, tipoMonstruo);

            // Verifica que haya suficientes monstruos del tipo en exceso para el segundo pedido
            int monstruosDisponibles = contarMonstruosDisponibles(tipoMonstruo);
            if (monstruosDisponibles - monstruosReservadosParaPrimero < monstruosNecesariosParaPedido) {
                return false;
            }

            tipoNodo = tipoNodo->siguiente;
        }
        return true;
    }


    bool verificarPedidoCompleto(Pedido* pedido) {
        Nodo<int>* tipoNodo = pedido->monstruosPedidos->primerNodo;

        while (tipoNodo != nullptr) {
            int tipoMonstruo = tipoNodo->dato;
            int monstruosNecesariosDeEsteTipo = contarMonstruosNecesarios(pedido, tipoMonstruo);
            int monstruosDisponibles = contarMonstruosDisponibles(tipoMonstruo);

            if (monstruosDisponibles < monstruosNecesariosDeEsteTipo) {
                return false;
            }

            tipoNodo = tipoNodo->siguiente;
        }
        return true;
    }


    int contarMonstruosReservados(Pedido* pedido, int tipoMonstruo) {
        int contador = 0;
        Nodo<Monstruo*>* monstruoNodo = almacen[tipoMonstruo]->primerNodo;

        while (monstruoNodo != nullptr) {
            Monstruo* monstruo = monstruoNodo->dato;
            if (monstruo->pedidoEntregado == pedido->numPedido) {
                contador++;
            }
            monstruoNodo = monstruoNodo->siguiente;
        }

        return contador;
    }

    int contarMonstruosNecesarios(Pedido* pedido, int tipoMonstruo) {
        int contador = 0;
        Nodo<int>* tipoNodo = pedido->monstruosPedidos->primerNodo;

        while (tipoNodo != nullptr) {
            if (tipoNodo->dato == tipoMonstruo) {
                contador++;
            }
            tipoNodo = tipoNodo->siguiente;
        }

        return contador;
    }

    int contarMonstruosDisponibles(int tipoMonstruo) {
        int contador = 0;
        Nodo<Monstruo*>* monstruoNodo = almacen[tipoMonstruo]->primerNodo;

        while (monstruoNodo != nullptr) {
            Monstruo* monstruo = monstruoNodo->dato;

            if (!monstruo->entregado) {
                contador++;
            }

            monstruoNodo = monstruoNodo->siguiente;
        }

        return contador;
    }

    void reservarMonstruosParaPedido(Pedido* pedido) {
        Nodo<int>* tipoNodo = pedido->monstruosPedidos->primerNodo;

        while (tipoNodo != nullptr) {
            int tipoMonstruo = tipoNodo->dato;
            int monstruosNecesariosDeEsteTipo = contarMonstruosNecesarios(pedido, tipoMonstruo);
            int monstruosReservadosDeEsteTipo = contarMonstruosReservados(pedido, tipoMonstruo);

            Nodo<Monstruo*>* monstruoNodo = almacen[tipoMonstruo]->primerNodo;

            while (monstruoNodo != nullptr && monstruosReservadosDeEsteTipo < monstruosNecesariosDeEsteTipo) {
                Monstruo* monstruo = monstruoNodo->dato;

                if (!monstruo->entregado && monstruo->pedidoEntregado == 0) {
                    monstruo->pedidoEntregado = pedido->numPedido;
                    monstruosReservadosDeEsteTipo++;
                    monstruo->entregado = true;
                    monstruo->timestampEntrega = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
                }

                monstruoNodo = monstruoNodo->siguiente;
            }

            tipoNodo = tipoNodo->siguiente;
        }
    }
};

#endif // ESTRUCTURAALMACEN_H
