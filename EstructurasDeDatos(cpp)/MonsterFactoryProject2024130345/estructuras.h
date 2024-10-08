#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
template<typename T>
struct Nodo{
public:
    T dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(T _dato){
        dato = _dato;
        siguiente = anterior = nullptr;
    }
};

template<typename T>
struct cola{
private:
    Nodo<T>* nodoFondo;//fondo
    Nodo<T>* nodoFrente;//frente
    int longitud;
public:
    cola(){
        nodoFondo=nodoFrente = nullptr;
        longitud = 0;
    }

    bool isEmpty(){
        if(longitud == 0){
            return true;
        } else {
            return false;
        }
    }

    void encolar(T dato){
        if(nodoFondo == nullptr){ //Si hay 0 nodos.
            nodoFondo = nodoFrente = new Nodo(dato);
            longitud++;
        } else{ //si hay 1 o mas nodos.
            Nodo<T>* nuevoNodo = new Nodo(dato);
            nuevoNodo -> siguiente = nodoFondo;
            nodoFondo -> anterior = nuevoNodo;
            nodoFondo = nuevoNodo;
            longitud++;
        }
    }

    Nodo<T>* desencolar(){
        if(nodoFondo == nullptr){ //si hay 0 nodos.
            return nullptr;
        } else if (nodoFondo == nodoFrente){ //si hay 1 nodo.
            Nodo<T>* nodoBorrado = nodoFrente;
            nodoFondo = nodoFrente = nullptr;
            longitud--;
            return nodoBorrado;
        } else{ //mas de 1 nodo.
            Nodo<T>* nodoBorrado = nodoFrente;
            nodoFrente = nodoFrente -> anterior;
            nodoFrente -> siguiente = nullptr;
            nodoBorrado -> anterior = nullptr;
            longitud--;
            return nodoBorrado;
        }
    }

    int size(){
        return longitud;
    }
};

template<typename T>
struct Lista{
public:
    Nodo<T>* primerNodo;
    Nodo<T>* ultimoNodo;
    int longitud;

    Lista(){
        primerNodo = ultimoNodo = nullptr;
        longitud = 0;
    }
    void insertarAlFinal(T dato){
        longitud++;
        if (ultimoNodo == nullptr){ //Si hay 0 nodos
            primerNodo = ultimoNodo = new Nodo(dato);
        } else{
            Nodo<T>* nuevoNodo = new Nodo(dato);
            ultimoNodo -> siguiente = nuevoNodo;
            nuevoNodo -> anterior = ultimoNodo;
            ultimoNodo = nuevoNodo;
        }
    }
    int size(){
        return longitud;
    }

    void borrarNodo(Nodo<T>* nodo){
        longitud--;
        if(primerNodo == ultimoNodo){
            primerNodo = ultimoNodo = nullptr;
        } else if(primerNodo == nodo){
            primerNodo = nodo->siguiente;
            primerNodo->anterior = nullptr;
            nodo->siguiente = nullptr;
        } else if(ultimoNodo == nodo){
            ultimoNodo = nodo->anterior;
            ultimoNodo->siguiente = nullptr;
            nodo->anterior = nullptr;
        } else {
            Nodo<T>* nodoAnterior = nodo->anterior;
            Nodo<T>* nodoSiguiente = nodo->siguiente;

            nodoAnterior->siguiente = nodoSiguiente;
            nodoSiguiente->anterior = nodoAnterior;

            nodo->anterior = nodo->siguiente = nullptr;
        }
    }
};

#endif // ESTRUCTURAS_H
