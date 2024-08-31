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
			insertarPrincipalDerecha(x);
			return;
		}
		if (y == 0 && x < 0){
			insertarPrincipalIzquierda(x);
			return;
		}
	}
	
	void insertarPrincipalDerecha(int x){
		nodoPrincipal* tmp = primerNodo;
			while(tmp -> derecha != NULL){
				if (x  <  tmp -> derecha -> x){ //Si la x del siguiente, es mayor al que queremos insertar, osea que si está en posición.
					nodoPrincipal* nuevoNodo = new nodoPrincipal(x,0);
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
			nodoPrincipal* nuevoNodo = new nodoPrincipal(x,0);
			tmp -> derecha = nuevoNodo;
			nuevoNodo -> izquierda = tmp;
	}
	
	void insertarPrincipalIzquierda(int x){ //Misma lógica que insertarPrincipalDerecha pero al revés (izquierda <-> derecha).
		nodoPrincipal* tmp = primerNodo;
			while(tmp -> izquierda != NULL){
				if (x  <  tmp -> izquierda -> x){ 
					nodoPrincipal* nuevoNodo = new nodoPrincipal(x,0);
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
			nodoPrincipal* nuevoNodo = new nodoPrincipal(x,0);
			tmp -> izquierda = nuevoNodo;
			nuevoNodo -> derecha = tmp;
	}
};
