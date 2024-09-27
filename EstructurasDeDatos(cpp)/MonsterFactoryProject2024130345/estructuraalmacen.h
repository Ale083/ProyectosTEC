#ifndef ESTRUCTURAALMACEN_H
#define ESTRUCTURAALMACEN_H
#include "estructuras.h"
#include "estructuramonstruo.h"
#include "pedido.h"

struct Almacen {
public:
    Lista<Monstruo*>* almacen[9];  // Almacén para 9 tipos diferentes de monstruos
    int inteligenciaDisponibles;
    int destruccionDisponibles;
    int regeneracionDisponibles;
    int fuerzaDisponibles;
    int maldadDisponibles;
    int venenoDisponibles;
    int locuraDisponibles;
    int tecnologiaDisponibles;
    int velocidadDisponibles;

    // Constructor que ahora toma listas en vez de colas
    Almacen(Lista<Pedido*>* listaDePedidos, Lista<Pedido*>* listaDePedidosPrioridad) {
        for (int i = 0; i < 9; i++) {
            almacen[i] = new Lista<Monstruo*>;
        }
        inteligenciaDisponibles = destruccionDisponibles = regeneracionDisponibles =
            fuerzaDisponibles = maldadDisponibles = venenoDisponibles =
            locuraDisponibles = tecnologiaDisponibles = velocidadDisponibles = 0;

        this->listaDePedidos = listaDePedidos;
        this->listaDePedidosPrioridad = listaDePedidosPrioridad;
    }

    // Funciones para insertar monstruos de distintos tipos, revisan los pedidos tras la inserción
    void insertarInteligencia(Monstruo* monstruo) {
        almacen[0]->insertarAlFinal(monstruo);
        inteligenciaDisponibles++;
        revisarPedidosPendientes();
    }

    void insertarDestruccion(Monstruo* monstruo) {
        almacen[1]->insertarAlFinal(monstruo);
        destruccionDisponibles++;
        revisarPedidosPendientes();
    }

    void insertarRegeneracion(Monstruo* monstruo) {
        almacen[2]->insertarAlFinal(monstruo);
        regeneracionDisponibles++;
        revisarPedidosPendientes();
    }

    void insertarFuerza(Monstruo* monstruo) {
        almacen[3]->insertarAlFinal(monstruo);
        fuerzaDisponibles++;
        revisarPedidosPendientes();
    }

    void insertarMaldad(Monstruo* monstruo) {
        almacen[4]->insertarAlFinal(monstruo);
        maldadDisponibles++;
        revisarPedidosPendientes();
    }

    void insertarVeneno(Monstruo* monstruo) {
        almacen[5]->insertarAlFinal(monstruo);
        venenoDisponibles++;
        revisarPedidosPendientes();
    }

    void insertarLocura(Monstruo* monstruo) {
        almacen[6]->insertarAlFinal(monstruo);
        locuraDisponibles++;
        revisarPedidosPendientes();
    }

    void insertarTecnologia(Monstruo* monstruo) {
        almacen[7]->insertarAlFinal(monstruo);
        tecnologiaDisponibles++;
        revisarPedidosPendientes();
    }

    void insertarVelocidad(Monstruo* monstruo) {
        almacen[8]->insertarAlFinal(monstruo);
        velocidadDisponibles++;
        revisarPedidosPendientes();
    }

private:
    Lista<Pedido*>* listaDePedidos;
    Lista<Pedido*>* listaDePedidosPrioridad;



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
                    qDebug() << "Pedido entregado: " << pedido->numPedido;
                    seEntregoPedido = true;

                } else {
                    qDebug() << "No se puede completar el pedido " << pedido->numPedido;
                }
            } else {
                qDebug() << "Pedido " << pedido->numPedido << " no puede completarse sin afectar el primer pedido";
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
                }

                monstruoNodo = monstruoNodo->siguiente;
            }

            tipoNodo = tipoNodo->siguiente;
        }
    }
};

#endif // ESTRUCTURAALMACEN_H
