#include <iostream>
using namespace std;
struct NodoChar{
	char dato;
	NodoChar* siguiente;
	NodoChar* anterior;
	
	NodoChar(char _dato){
		dato = _dato;
		siguiente = anterior = NULL;
		
	}
};

struct NodoDouble{
	double dato;
	NodoDouble* siguiente;
	NodoDouble* anterior;
	
	NodoDouble(double _dato){
		dato = _dato;
		siguiente = anterior = NULL;
		
	}
		//Pila = Stack
	//bool isEmpty()
	//void push(int) //insertar al inicio
	//Nodo* pop() //elimina el tope de la pila, y lo retorna. //borrar al inicio
	//nodo* peek() //Devuelve el tope de la pila //return top.
	//Pila es un LiFo (Last in First out).
};


struct PilaChar{
	NodoChar* top;
	
	Pila(){
		top = NULL;
	}
	
	bool isEmpty(){
		if (top == NULL){
			return true;
		}
		return false;
	}
	
	void push(char dato){
		if (top == NULL){
			top = new NodoChar(dato);
			return;
		}
		top -> siguiente = new NodoChar(dato);
		top-> siguiente->anterior = top;
		top = top -> siguiente;
	}
	
	NodoChar* pop(){
		if (top == NULL){
			return NULL;
		}
		if (top -> anterior == NULL){ //Si solo hay 1 nodo.
			NodoChar* borrado = top;
			top = NULL;
			return borrado;
		}
		NodoChar* borrado = top;
		top = top->anterior;
		top -> siguiente = NULL;
		return borrado;
	}
	NodoChar* peek(){
		return top;
	} 
};

struct PilaDouble{
	NodoDouble* top;
	
	Pila(){
		top = NULL;
	}
	
	bool isEmpty(){
		if (top == NULL){
			return true;
		}
		return false;
	}
	
	void push(double dato){
		if (top == NULL){
			top = new NodoDouble(dato);
			return;
		}
		top -> siguiente = new NodoDouble(dato);
		top-> siguiente->anterior = top;
		top = top -> siguiente;
	}
	
	NodoDouble* pop(){
		if (top == NULL){
			return NULL;
		}
		if (top -> anterior == NULL){ //Si solo hay 1 nodo.
			NodoDouble* borrado = top;
			top = NULL;
			return borrado;
		}
		NodoDouble* borrado = top;
		top = top->anterior;
		top -> siguiente = NULL;
		return borrado;
	}
	NodoDouble* peek(){
		return top;
	} 
};
