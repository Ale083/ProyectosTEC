#include <iostream>
#include <cstdlib> //Solo para clear terminal.
#include <limits> //Para poder clear los cin cuando dan error.
using namespace std;
void printMenu();
void wait();
int pedirEntero();
double pedirDouble();


struct Ingrediente {
	string nombre;
	float cantidad;
	string medida;
	
	Ingrediente(){
		nombre = "";
		cantidad = 0;
		medida = "";
	}
	void resetIngrediente(){
		nombre = "";
		cantidad = 0;
		medida = "";
	}
	void inicializarIngrediente(Ingrediente ingredientes[], int contIngredientes){
		cout << "Que nombre tiene el ingrediente?" << endl;
		getline(cin, nombre);
		
		for (int i=0;i<contIngredientes;i++){
			if (ingredientes[i].nombre == nombre){
				cout << "Ya añadiste este ingrediente. Intentelo de nuevo." << endl;
				inicializarIngrediente(ingredientes,contIngredientes);
				return;
			}
		}
		
		
		cout << "Que cantidad de " + nombre << " se necesita? (sin la medida)" << endl;
		cantidad = pedirDouble();
		cout << "En que medida es esa cantidad?" << endl;
		getline(cin,medida);
	}
	
	void cambiarCantidad(){
		cout << "Cual es la nueva cantidad para el ingrediente? \t Cantidad anterior -> " << cantidad << endl;
		cantidad = pedirDouble();
	}
	
	void imprimir(){
		cout << "- " << cantidad  << medida << " de " << nombre << endl;
	}
	
	void imprimirMultiplicadorCantidad(double multiplicador){
		double nuevaCantidad = cantidad*multiplicador;
		cout << "- " << nuevaCantidad  << medida << " de " << nombre << endl;
	}
	
	void inicializarIngredienteSinValidacion(){
		cout << "Que nombre tiene el ingrediente?" << endl;
		getline(cin, nombre);
		
		cout << "Que cantidad de " + nombre << " se necesita?" << endl;
		cantidad = pedirDouble();
		cout << "En que medida es esa cantidad?" << endl;
		getline(cin,medida);
	}
	
};


struct Receta {
	string nombre;
	int porciones;
	Ingrediente ingredientes[20];
	int contIngredientes;
	
	Receta(){
		nombre = "";
		porciones = 0;
		contIngredientes = 0;
	}
	
	
	void resetReceta(){
		for(int i=0;i<contIngredientes;i++){
			ingredientes[i].resetIngrediente();
		}
		nombre = "";
		porciones = 0;
		contIngredientes = 0;
	}
	
	
	void _init_(Receta libroDeRecetas[], int numRecetas){ 
		cout << "Que nombre tiene la receta?" << endl;
		getline(cin, nombre);
		
		for (int i=0;i<numRecetas;i++){
			if (libroDeRecetas[i].nombre == nombre){
				cout << "Ya existe esta receta. Intentelo de nuevo." << endl;
				_init_(libroDeRecetas, numRecetas);
				return;
			}
		}
		
		while (contIngredientes <20){
			cout << "Ingrediente " << (contIngredientes+1) << endl;
			ingredientes[contIngredientes].inicializarIngrediente(ingredientes, contIngredientes);
			contIngredientes++;
			cout << "Escribe 'Si' si quieres agregar otro ingrediente, presiona enter si no.";
			string respuesta;
			getline(cin,respuesta);
			if (respuesta != "Si" ){	
				break;
			} 
		}
		if (contIngredientes == 20){
			cout << "Ya tienes 20 ingredientes." << endl;
		}
		cout << "Para cuantas porciones son esa cantidad de ingredientes" << endl;
		porciones = pedirEntero();
	}
	
	
	void cambiarCantIngrediente(){
		int indexIngrediente = buscarIndexIngrediente();
		if (indexIngrediente == -1){
			return;
		} else {
			ingredientes[indexIngrediente].cambiarCantidad();
		}
		
	}
	
	int buscarIndexIngrediente(){
		cout << "Pon el nombre del ingrediente" << endl;
		string busqueda;
		getline(cin,busqueda);
		for (int i=0;i<contIngredientes;i++){
			if(ingredientes[i].nombre == busqueda){
				return i;
			}
		}
		cout << "No se encontró el ingrediente" << endl;
		wait();
		return -1;
	}
	
	void cambiarNombre(Receta LibroDeRecetas[],int numRecetas){
		cout << "A que nombre lo quieres cambiar?" << endl;
		string nuevoNombre;
		getline(cin,nuevoNombre);
		for (int i=0;i<numRecetas;i++){
			if (LibroDeRecetas[i].nombre == nuevoNombre){
				cout << "Ya existe esta receta. Intentelo de nuevo." << endl;
				return cambiarNombre(LibroDeRecetas, numRecetas);
			}
		}
		nombre = nuevoNombre;
	}
	
	void imprimir(){
		cout << "-----------------" << endl;
		cout << "Receta de " << nombre << ". Da para " << porciones << " porciones. Ingredientes:" << endl;
		for (int i=0; i<contIngredientes;i++){
			ingredientes[i].imprimir();
		}
	}
	
	void anadirIngrediente(){
		if (contIngredientes != 20){
			ingredientes[contIngredientes].inicializarIngrediente(ingredientes, contIngredientes);
			contIngredientes++;
		} else {
			cout << "Ya tienes 20 ingredientes, no puedes añadir más" << endl;
		}
	}
	
	void calcularParaPorciones(){
		cout << "Para cuantas porciones quieres calcular?" << endl;
		int calcPorciones;
		double multiplicador;
		calcPorciones = pedirEntero();
		multiplicador = (double)calcPorciones/porciones;
		cout << "Receta de " << nombre << ". Para " << calcPorciones << " porciones. Ingredientes:" << endl;
		for (int i=0; i<contIngredientes;i++){
			ingredientes[i].imprimirMultiplicadorCantidad(multiplicador);
		}
	}
	
	void sustituirIngredienteEnReceta(string busqueda,Ingrediente nuevoIngrediente){
		for (int i=0;i<contIngredientes;i++){
			if(ingredientes[i].nombre == busqueda){
				ingredientes[i] = nuevoIngrediente;
			}
		}
	}
};

