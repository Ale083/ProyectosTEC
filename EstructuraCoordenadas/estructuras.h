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
};
