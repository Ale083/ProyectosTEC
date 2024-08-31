#include <iostream>
using namespace std;
struct nodoAuxiliar;

struct nodoPrincipal{
	int dato;
	nodoAuxiliar* arriba;
	nodoAuxiliar* abajo;
	
	nodoPrincipal(int _dato){
		dato = _dato;
		arriba = abajo = NULL;
	}
	
	nodoPrincipal(){
		dato = 0;
		arriba = abajo = NULL;
	}
};


struct nodoAuxiliar{
	int dato;
	nodoPrincipal* siguiente;
	
	nodoAuxiliar(int _dato){
		dato = _dato;
		siguiente = NULL;
	}
	nodoAuxiliar(){
		dato = 0;
		siguiente = NULL;
	}
};

struct EstructuraEspecial{
	nodoPrincipal* primerNodo;
	
	EstructuraEspecial(){
		primerNodo = NULL;
	}
	
	void insertar(int dato){
		if (dato % 10 == 0){
			insertarArriba(dato);
		} else if(dato % 2 == 0){
			insertarNodoPrincipal(dato);
		} else{
			insertarAbajo(dato);
		}
	}
	
	void insertarArriba(int dato){
		nodoPrincipal* tmp = primerNodo;
		if(primerNodo == NULL){ //Si no hay nada
			return;
		}
		while(tmp != NULL){
			if(tmp -> arriba == NULL){
				nodoAuxiliar* nuevo = new nodoAuxiliar(dato);
				tmp -> arriba = nuevo;
				nodoPrincipal* siguientePrincipal = siguiente(tmp);
				tmp -> arriba -> siguiente = siguientePrincipal;
				return;
			} else{
				tmp = siguiente(tmp);
			}
		}
	}
	
	void insertarAbajo(int dato){
		nodoPrincipal* tmp = primerNodo;
		if(primerNodo == NULL){ //Si no hay nada
			return;
		}
		while(tmp != NULL){
			if(tmp -> abajo == NULL){
				nodoAuxiliar* nuevo = new nodoAuxiliar(dato);
				tmp -> abajo = nuevo;
				nodoPrincipal* siguientePrincipal = siguiente(tmp);
				tmp -> abajo -> siguiente = siguientePrincipal;
				return;
			} else{
				tmp = siguiente(tmp);
			}
		}
	}
	
	void insertarNodoPrincipal(int dato){
		nodoPrincipal* tmp = primerNodo;
		if (primerNodo == NULL) { //Si no hay nada
			primerNodo = new nodoPrincipal(dato);
			return;
		} while (siguiente(tmp) != NULL){ //mueve tmp al ultimo nodoPrincipal existente
			tmp = siguiente(tmp);
		}
		if ((tmp -> arriba != NULL) || (tmp -> abajo != NULL)){
			//^^^ si existe un nodo auxiliar arriba o abajo (no hay que validar que siguiente sea null porque ya se sabe por el while.
			enlazarNodos(tmp,new nodoPrincipal(dato));
		}
	}
	
	nodoPrincipal* siguiente (nodoPrincipal* nodo){ //Devuelve el siguiente principal si hay alguno, sino null.
		if (nodo -> arriba != NULL){
			return nodo -> arriba -> siguiente;
		} else if (nodo -> abajo != NULL){
			return nodo-> abajo -> siguiente;
		} else{
			return NULL;
		}
	}
	
	nodoPrincipal* eliminarPrincipal (int dato){
		if (primerNodo == NULL){
			return NULL;
		}
		nodoPrincipal* tmp = primerNodo;
		if (primerNodo -> dato == dato){ //si es el primer nodo
			primerNodo = siguiente(primerNodo);
			enlazarNodos(tmp,NULL); //conecta los auxiliares del nodo borrado con NULL
			return tmp;
		}
		while (tmp != NULL){
			if (siguiente(tmp) -> dato == dato){
				nodoPrincipal* nodoBorrado = siguiente(tmp);
				
				enlazarNodos(tmp, siguiente(nodoBorrado));
				enlazarNodos(nodoBorrado,NULL);
				return nodoBorrado;
			} else {
				tmp = siguiente(tmp);
			}
		}
		return NULL; 
	}
	
	bool esta(int d){
		if (primerNodo == NULL){
			return false;
		}
		nodoPrincipal* tmp = primerNodo;
		while(tmp != NULL){
			if (tmp -> dato == d || (tmp -> arriba != NULL && tmp -> arriba -> dato == d) || (tmp -> abajo != NULL && tmp -> abajo -> dato == d)){
				return true;
			} else {
				tmp = siguiente(tmp);
			}
		}
		return false;
	}
	
	void imprimir(){
		nodoPrincipal* tmp = primerNodo;
		while (tmp != NULL){
			if (tmp -> arriba != NULL){
				cout << "\t" << tmp -> arriba -> dato << "\t";
				tmp = siguiente(tmp);
			} else {
				cout << "\t\t";
				tmp = siguiente(tmp);
			}
		}
		cout << endl;
		
		tmp = primerNodo;
		while (tmp != NULL){
			cout << tmp -> dato << "\t\t";
			tmp = siguiente(tmp);
		}
		cout << endl;
		
		tmp = primerNodo;
		while (tmp != NULL){
			if (tmp -> arriba != NULL){
				cout << "\t" << tmp -> abajo -> dato << "\t";
				tmp = siguiente(tmp);
			} else {
				cout << "\t\t";
				tmp = siguiente(tmp);
			}
		}
		cout << endl;
	}
	
	void enlazarNodos(nodoPrincipal* nodoAEnlazar, nodoPrincipal* nodoAApuntar){
		if(nodoAEnlazar -> arriba != NULL) { 
			nodoAEnlazar -> arriba -> siguiente = nodoAApuntar;
		} 
		if (nodoAEnlazar -> abajo != NULL){
			nodoAEnlazar -> abajo -> siguiente = nodoAApuntar;
		}
	}
	
};

