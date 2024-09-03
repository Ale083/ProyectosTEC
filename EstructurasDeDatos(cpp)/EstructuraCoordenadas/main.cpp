#include "estructuras.h"



int main(int argc, char** argv) {
	listaCoordenadas* estructura = new listaCoordenadas();
	estructura -> insertar(-10,0);
	estructura -> insertar(0,70);
	estructura -> insertar(0,100);
	estructura -> insertar(0,-60);
	estructura -> insertar(10,-20);
	estructura -> insertar(10,-90);
	estructura -> insertar(20,10);
	estructura -> insertar(40,0);
	estructura -> insertar(40,20);
	estructura -> insertar(40,-50);
	
	estructura -> imprimir();	
	cout << "--------------------------------------------------------------------"<< endl << endl;;
	
	//Los insertar que hay como casos en el pdf
	estructura -> insertar(30,20);
	estructura -> insertar(30,0);
	estructura -> insertar(0,80);
	estructura -> imprimir();	
}
