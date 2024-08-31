#include "estructuras.h"

void linea();
int main(int argc, char** argv) {
    EstructuraEspecial* estructura = new EstructuraEspecial;

    estructura->insertarNodoPrincipal(20);
    estructura->insertarArriba(46);  
    estructura->insertarAbajo(25);  
    estructura->insertarNodoPrincipal(40);
    estructura->insertarArriba(8);  
    estructura->insertarNodoPrincipal(80);
    estructura->insertarAbajo(13);  
	estructura->insertarAbajo(16); 
    estructura->imprimir();
    
    linea();
    
    //Pruebas aquí
    
    
    
    
    
	EstructuraEspecial* estructura2 = new EstructuraEspecial; //Tests de que no se cae cuando hay 0 o solo 1 nodo
	estructura2 -> insertarArriba(46);
	estructura2 -> insertarAbajo(46);
	estructura2 -> esta(46);
	estructura2 ->eliminarPrincipal(80);
	estructura2 ->eliminarPrincipal(46);
	estructura2 -> insertarNodoPrincipal(46);
	estructura2 -> insertarArriba(47);
	estructura2 -> insertarAbajo(48);
	estructura2 -> imprimir();
	cout << (estructura2 -> esta(4)); // 0 si es false, 1 si es true. En este caso deberia dar 0
	estructura2 ->eliminarPrincipal(46);
	estructura2 -> imprimir();
	linea();
	return 0;
}

void linea(){
	cout << "|------------------------------------------|" << endl;
}
