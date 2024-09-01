#include <iostream>
using namespace std;
struct nodoAuxiliar;

struct nodoPrincipal{
	int x;
	int y;
	int auxiliaresArriba;
	int auxiliaresAbajo;
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
		auxiliaresArriba = 0;
		auxiliaresAbajo = 0;
	}
	nodoPrincipal(int _x, int _y){
		x = _x;
		y = _y;
		izquierda = NULL;
		derecha = NULL;
		arriba = NULL;
		abajo = NULL;
		auxiliaresArriba = 0;
		auxiliaresAbajo = 0;
	}
	imprimir(){
		cout << "(" << x << "," << y << ")\t\t";
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
	imprimir(){
		cout << "(" << x << "," << y << ")\t\t";
	}
};

struct listaCoordenadas{
	nodoPrincipal* primerNodo;
	
	listaCoordenadas(){
		primerNodo = new nodoPrincipal(0,0);
	}
	//TODO: simplificar, no es necesario 8 ifs.
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
		if (x == 0 && y > 0){
			insertarAuxiliarArriba(x,y,primerNodo);
			return;
		}
		if (x == 0 && y < 0){
			insertarAuxiliarAbajo(x,y,primerNodo);
			return;
		}
		if (x > 0 && y > 0){ //cuadrante 1
			nodoPrincipal* nodoX = insertarPrincipalDerecha(x);
			insertarAuxiliarArriba(x,y,nodoX);
		}
		if (x < 0 && y >0){ //cuadrante 2
			nodoPrincipal* nodoX = insertarPrincipalIzquierda(x);
			insertarAuxiliarArriba(x,y,nodoX);
		}
		if (x < 0 && y < 0){ //cuadrante 3
			nodoPrincipal* nodoX = insertarPrincipalIzquierda(x);
			insertarAuxiliarAbajo(x,y,nodoX);
		}
		if (x > 0 && y < 0){ //cuadrante 4
			nodoPrincipal* nodoX = insertarPrincipalDerecha(x);
			insertarAuxiliarAbajo(x,y,nodoX);
		}
	}
	
	nodoPrincipal* insertarPrincipalDerecha(int x){
		nodoPrincipal* tmp = primerNodo;
			while(tmp -> derecha != NULL){
				if (x  <  tmp -> derecha -> x){ //Si la x del siguiente, es mayor al que queremos insertar, osea que si está en posición.
					nodoPrincipal* nuevoNodo = new nodoPrincipal(x,0);
					nuevoNodo -> derecha = tmp -> derecha;
					tmp -> derecha -> izquierda = nuevoNodo;
					tmp -> derecha = nuevoNodo;
					nuevoNodo -> izquierda = tmp;
					return nuevoNodo;
				} else if (x == tmp -> derecha -> x){ //Si se repite con alguno ya existente
					return tmp -> derecha;
				} else{
					tmp = tmp -> derecha;
				}
			}
			//Si llega aquí significa que el de la derecha si es null, el que se inserta es el mayor de la lista.
			nodoPrincipal* nuevoNodo = new nodoPrincipal(x,0);
			tmp -> derecha = nuevoNodo;
			nuevoNodo -> izquierda = tmp;
			return nuevoNodo;
	}
	
	nodoPrincipal* insertarPrincipalIzquierda(int x){ //Misma lógica que insertarPrincipalDerecha pero al revés (izquierda <-> derecha).
		nodoPrincipal* tmp = primerNodo;
			while(tmp -> izquierda != NULL){
				if (x  >  tmp -> izquierda -> x){ 
					nodoPrincipal* nuevoNodo = new nodoPrincipal(x,0);
					nuevoNodo -> izquierda = tmp -> izquierda;
					tmp -> izquierda -> derecha = nuevoNodo;
					tmp -> izquierda = nuevoNodo;
					nuevoNodo -> derecha = tmp;
					return nuevoNodo;
				} else if (x == tmp -> izquierda -> x){
					return tmp->izquierda;
				} else{
					tmp = tmp -> izquierda;
				}
			}
			nodoPrincipal* nuevoNodo = new nodoPrincipal(x,0);
			tmp -> izquierda = nuevoNodo;
			nuevoNodo -> derecha = tmp;
			return nuevoNodo;
	}
	
	void insertarAuxiliarArriba(int x, int y, nodoPrincipal* nodoX){
		nodoX -> auxiliaresArriba++;
		nodoAuxiliar* tmp = nodoX -> arriba;
		if (tmp == NULL){ //Si no tiene nada arriba.
			nodoX -> arriba = new nodoAuxiliar(x,y);
			return;
		} else if (y < tmp -> y){ //Si tiene que insertar nodo justo al principio por decir asi.
			nodoAuxiliar* nuevo = new nodoAuxiliar(x,y);
			tmp -> abajo = nuevo;
			nuevo -> arriba = tmp;
			nodoX -> arriba = nuevo;
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
				nodoX -> auxiliaresArriba--;
				return;
			} else {
				tmp = tmp -> arriba;
			}
		}
		nodoAuxiliar* nuevo = new nodoAuxiliar(x,y);
		tmp -> arriba = nuevo;
		nuevo -> abajo = tmp;
	}
	
	void insertarAuxiliarAbajo(int x, int y, nodoPrincipal* nodoX){ //misma lógica que insertarAuxiliarArriba
		nodoX -> auxiliaresAbajo++;
		nodoAuxiliar* tmp = nodoX -> abajo;
		if (tmp == NULL){
			nodoX -> abajo = new nodoAuxiliar(x,y);
			return;
		} else if (y > tmp -> y){ 
			nodoAuxiliar* nuevo = new nodoAuxiliar(x,y);
			tmp -> arriba = nuevo;
			nuevo -> abajo = tmp;
			nodoX -> abajo = nuevo;
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
				nodoX -> auxiliaresAbajo--;
				return;
			} else {
				tmp = tmp -> abajo;
			}
		}
		nodoAuxiliar* nuevo = new nodoAuxiliar(x,y);
		tmp -> abajo = nuevo;
		nuevo -> arriba = tmp;
	}
	
	void imprimir(){
		nodoPrincipal* tmp = primerNodo;
		while(tmp -> izquierda != NULL){
			tmp = tmp -> izquierda;
		}
		nodoPrincipal* nodoExtremoIzquierda = tmp;
		int mayorAuxArriba = 0;
		int mayorAuxAbajo = 0;
		while(tmp != NULL){ //Recorre toda la lista para ver cual es el mayor número de auxiliares que tiene un nodoPrincipal tanto arriba como abajo
			if(tmp -> auxiliaresArriba > mayorAuxArriba){
				mayorAuxArriba = tmp -> auxiliaresArriba;
			}
			if(tmp -> auxiliaresAbajo > mayorAuxAbajo){
				mayorAuxAbajo = tmp -> auxiliaresAbajo;
			}
			tmp = tmp -> derecha;
		}
		imprimirArribaAux(nodoExtremoIzquierda, mayorAuxArriba);
		imprimirPrincipales(nodoExtremoIzquierda);	
		imprimirAbajoAux(nodoExtremoIzquierda, mayorAuxAbajo);
	}
	
	void imprimirArribaAux(nodoPrincipal* nodoExtremoIzquierda, int mayorAuxArriba){
		for (int i = mayorAuxArriba;i>0;i--){ // empieza a imprimir desde arriba de todo.
			nodoPrincipal* tmp = nodoExtremoIzquierda;
			while(tmp != NULL){ 
				printCoordsArribaIPosiciones(tmp,i);
				tmp = tmp -> derecha;
			}
			cout << endl;
		}
	}
	
	void printCoordsArribaIPosiciones(nodoPrincipal* nodo, int altura){
		nodoAuxiliar* tmp = nodo -> arriba;
		if (tmp == NULL){ //Si no tenía aux arriba.
			cout << "\t\t";
			return;
		}
		for(int i=0;i<altura-1;i++){ 
			if (tmp -> arriba == NULL){
				cout << "\t\t";
				return;
			} else {
				tmp = tmp -> arriba;
			}
		}
		tmp -> imprimir(); 
		return;
	}
	
	void imprimirPrincipales(nodoPrincipal* nodoExtremoIzquierda){
		nodoPrincipal* tmp = nodoExtremoIzquierda;
		while (tmp != NULL){
			tmp -> imprimir();
			tmp = tmp -> derecha;
		}
		cout << endl;
	}
	
	void imprimirAbajoAux(nodoPrincipal* nodoExtremoIzquierda, int mayorAuxAbajo){
		for (int i = 1;i<=mayorAuxAbajo;i++){ 
			nodoPrincipal* tmp = nodoExtremoIzquierda;
			while(tmp != NULL){ 
				printCoordsAbajoIPosiciones(tmp,i);
				tmp = tmp -> derecha;
			}
			cout << endl;
		}
	}
	
	void printCoordsAbajoIPosiciones(nodoPrincipal* nodo, int altura){
		nodoAuxiliar* tmp = nodo -> abajo;
		if (tmp == NULL){ //Si no tenía aux arriba.
			cout << "\t\t";
			return;
		}
		for(int i=0;i<altura-1;i++){ 
			if (tmp -> abajo == NULL){
				cout << "\t\t";
				return;
			} else {
				tmp = tmp -> abajo;
			}
		}
		tmp -> imprimir(); 
		return;
	}
};
