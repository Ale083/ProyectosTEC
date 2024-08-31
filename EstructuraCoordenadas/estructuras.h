#include <iostream>
using namespace std;
struct nodoAuxiliar;

struct nodoPrincipal{
	int x;
	int y;
	nodoPrincipal* izquierda;
	nodoPrincipal* derecha;
	nodoAuxiliar* arriba;
	nodoAuxiliar* abajo;
	
	nodoPrincipal(){
		x =0;
		y=0;
		izquierda = NULL;
		derecha = NULL;
		arriba = NULL;
		abajo = NULL;
	}
	nodoPrincipal(int _x, int _y){
		x = _x;
		y = _y;
		izquierda = NULL;
		derecha = NULL;
		arriba = NULL;
		abajo = NULL;
	}
	
};

struct nodoAuxiliar{
	int x;
	int y;
	nodoAuxiliar* arriba;
	nodoAuxiliar* abajo;
	
	nodoAuxiliar(){
		x =0;
		y=0;
		arriba = NULL;
		abajo = NULL;
	}
	nodoAuxiliar(int _x, int _y){
		x = _x;
		y = _y;
		arriba = NULL;
		abajo = NULL;
	}
};

struct listaCoordenadas{
	nodoPrincipal* primerNodo;
	
	listaCoordenadas(){
		primerNodo = new nodoPrincipal(0,0);
	}
	
	void insertar(int x, int y){
		if (y % 10 != 0 || (x==0 && y==0)){
			return; //y debe ser multiplo de 10, si no lo es entonces no se inserta. Además no podemos insertar otro (0,0)
		}
		if (y == 0 && x > 0){
			insertarPrincipalDerecha(x,0);
			return;
		}
		if (y == 0 && x < 0){
			insertarPrincipalIzquierda(x,0);
			return;
		}
		if (x == 0 && y > 0){
			insertarAuxiliarArriba(0,y);
		}
		if (x == 0 && y < 0){
			insertarAuxiliarAbajo(0,y);
		}
	}
	
	void insertarPrincipalDerecha(int x, int y){
		nodoPrincipal* tmp = primerNodo;
			while(tmp -> derecha != NULL){
				if (x  <  tmp -> derecha -> x){ //Si la x del siguiente, es mayor al que queremos insertar, osea que si está en posición.
					nodoPrincipal* nuevoNodo = new nodoPrincipal(x,y);
					nuevoNodo -> derecha = tmp -> derecha;
					tmp -> derecha -> izquierda = nuevoNodo;
					tmp -> derecha = nuevoNodo;
					nuevoNodo -> izquierda = tmp;
					return;
				} else if (x == tmp -> derecha -> x){ //Si se repite con alguno ya existente
					return;
				} else{
					tmp = tmp -> derecha;
				}
			}
			//Si llega aquí significa que el de la derecha si es null, el que se inserta es el mayor de la lista.
			nodoPrincipal* nuevoNodo = new nodoPrincipal(x,y);
			tmp -> derecha = nuevoNodo;
			nuevoNodo -> izquierda = tmp;
	}
	
	void insertarPrincipalIzquierda(int x, int y){ //Misma lógica que insertarPrincipalDerecha pero al revés (izquierda <-> derecha).
		nodoPrincipal* tmp = primerNodo;
			while(tmp -> izquierda != NULL){
				if (x  >  tmp -> izquierda -> x){ 
					nodoPrincipal* nuevoNodo = new nodoPrincipal(x,y);
					nuevoNodo -> izquierda = tmp -> izquierda;
					tmp -> izquierda -> derecha = nuevoNodo;
					tmp -> izquierda = nuevoNodo;
					nuevoNodo -> derecha = tmp;
					return;
				} else if (x == tmp -> izquierda -> x){
					return;
				} else{
					tmp = tmp -> izquierda;
				}
			}
			nodoPrincipal* nuevoNodo = new nodoPrincipal(x,y);
			tmp -> izquierda = nuevoNodo;
			nuevoNodo -> derecha = tmp;
	}
	
	void insertarAuxiliarArriba(int x, int y){
		nodoAuxiliar* tmp = primerNodo -> arriba;
		if (tmp == NULL){ //Si no tiene nada arriba.
			primerNodo -> arriba = new nodoAuxiliar(x,y);
			return;
		} else if (y < tmp -> y){ //Si tiene que insertar nodo justo al principio por decir asi.
			nodoAuxiliar* nuevo = new nodoAuxiliar(x,y);
			tmp -> abajo = nuevo;
			nuevo -> arriba = tmp;
			primerNodo -> arriba = nuevo;
			return;
		}
		while(tmp -> arriba != NULL){ //desde aquí misma lógica que los otros insertar.
			if (y < tmp -> arriba -> y){
				nodoAuxiliar* nuevo = new nodoAuxiliar(x,y);
				nuevo -> arriba = tmp -> arriba;
				tmp -> arriba -> abajo = nuevo;
				tmp -> arriba = nuevo;
				nuevo -> abajo = tmp;
				return;
			} else if (y == tmp -> arriba -> y){
				return;
			} else {
				tmp = tmp -> arriba;
			}
		}
		nodoAuxiliar* nuevo = new nodoAuxiliar(x,y);
		tmp -> arriba = nuevo;
		nuevo -> abajo = tmp;
	}
	
	void insertarAuxiliarAbajo(int x, int y){ //misma lógica que insertarAuxiliarArriba
		nodoAuxiliar* tmp = primerNodo -> abajo;
		if (tmp == NULL){
			primerNodo -> abajo = new nodoAuxiliar(x,y);
			return;
		} else if (y > tmp -> y){ 
			nodoAuxiliar* nuevo = new nodoAuxiliar(x,y);
			tmp -> arriba = nuevo;
			nuevo -> abajo = tmp;
			primerNodo -> abajo = nuevo;
			return;
		}
		while(tmp -> abajo != NULL){ 
			if (y > tmp -> abajo -> y){
				nodoAuxiliar* nuevo = new nodoAuxiliar(x,y);
				nuevo -> abajo = tmp -> abajo;
				tmp -> abajo -> arriba = nuevo;
				tmp -> abajo = nuevo;
				nuevo -> arriba = tmp;
				return;
			} else if (y == tmp -> abajo -> y){
				return;
			} else {
				tmp = tmp -> abajo;
			}
		}
		nodoAuxiliar* nuevo = new nodoAuxiliar(x,y);
		tmp -> abajo = nuevo;
		nuevo -> arriba = tmp;
	}
};
