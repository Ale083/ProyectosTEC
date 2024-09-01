#include "estructuras.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	listaCoordenadas* estructura = new listaCoordenadas();
	estructura -> insertar(1,10);
	estructura -> insertar(2,20);
	estructura -> insertar(3,30);
	estructura -> insertar(4,10);
	estructura -> insertar(4,30);
	estructura -> insertar(-4,10);
	estructura -> insertar(-4,-30);
	estructura -> imprimir();	
	cout << "------------------------------------------------"<< endl;
	listaCoordenadas* estructura2 = new listaCoordenadas();
	estructura2 -> insertar(2,0);
	estructura2 -> insertar(3,0);
	estructura2 -> insertar(4,0);
	estructura2 -> insertar(5,0);
	estructura2 -> imprimir();
	return 0;
}
