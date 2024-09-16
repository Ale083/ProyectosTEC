#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
template<typename T>
struct Nodo{
private:
    T dato;
    Nodo* siguiente;
    Nodo* anterior;
public:
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

//bool isempty()
//void encolar()
//Nodo* desencolar()


#endif // ESTRUCTURAS_H
