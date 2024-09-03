#include "estructuras.h"

void linea();
int main(int argc, char** argv) {
    EstructuraEspecial* estructura = new EstructuraEspecial;

    estructura->insertar(20);
    estructura->insertar(46);  
    estructura->insertar(25);  
    estructura->insertar(40);
    estructura->insertar(8);  
    estructura->insertar(80);
    estructura->insertar(13);  
	estructura->insertar(15); 
    estructura->imprimir();
	
    linea();
    
    //Pruebas aquí
    
    
    
    linea();
    
	EstructuraEspecial* estructura2 = new EstructuraEspecial; //Tests de que no se cae cuando hay 0 o solo 1 nodo

	estructura2 -> insertar(46); //arriba
	estructura2 -> insertar(45); //abajo
	estructura2 -> esta(46); //no deberia haber nada entonces false
	estructura2 ->eliminarPrincipal(80); //no hay nada, NULL
	estructura2 ->eliminarPrincipal(46); //no hay nada, NULL
	estructura2 -> insertar(50); //principal
	estructura2 -> insertar(48); //arriba
	estructura2 -> insertar(49); //abajo
	estructura2 -> imprimir();
	cout << (estructura2 -> esta(4)) << endl; // 0 si es false, 1 si es true. En este caso deberia dar 0
	estructura2 ->eliminarPrincipal(46); 
	estructura2 -> imprimir();
	
	linea();
	return 0;
}

void linea(){
	cout << "|------------------------------------------|" << endl;
}
