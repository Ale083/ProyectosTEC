#include "estructuras.h"
#include "recetario.h"
void menu(Recetario* r1);

int main(int argc, char** argv) {
	Recetario* r1 = new Recetario(); 
	menu(r1);
	return 0;
}

void menu(Recetario* r1){
	system("cls");
	printMenu();
	int opcion = pedirEntero();
    system("cls");
    switch(opcion){
    	case 1:
    		r1 -> nuevaReceta();
    		menu(r1);
    		break;
    	case 2:
    		r1 -> buscarReceta();
    		menu(r1);
    		break;
    	case 3:
    		r1 -> borrarReceta();
    		menu(r1);
    		break;
    	case 4:
    		r1 -> printRecetas();
    		menu(r1);
    		break;
    	case 5:
    		r1 -> modificarNombreReceta();
    		menu(r1);
    		break;
    	case 6:
    		r1 -> modificarCantIngrediente();
    		menu(r1);
    		break;
    	case 7:
    		r1 -> agregarIngrediente();
    		menu(r1);
    		break;
    	case 8:
    		r1 -> calcularParaPorciones();
    		menu(r1);
    		break;
    	case 9:
    		r1 -> sustituirIngredienteEnRecetas();
    		menu(r1);
    		break;
    	case 10:
    		break;
    	default:
    		cout << "Ese número no está en el menu, intentalo de nuevo" << endl;
    		wait();
    		menu(r1);
    		break;
	}
}

void printMenu(){
	cout << "1. Agregar receta" << endl;
    cout << "2. Buscar receta" << endl;
    cout << "3. Borrar receta" << endl;
    cout << "4. Imprimir todas las recetas" << endl;
    cout << "5. Modificar nombre de una receta" << endl;
    cout << "6. Modificar cantidad de un ingrediente de una receta" << endl;
    cout << "7. Agregar ingrediente a una receta" << endl;
    cout << "8. Calcular para porciones" << endl;
    cout << "9. Modificar ingrediente de todas las recetas" << endl;
    cout << "10. Salir." << endl;
}


void wait(){
	string temp;
	cout << "Presiona enter para volver al menú";
	getline(cin,temp);
	system("cls");
}
int pedirEntero(){
	int numero;
	while(true){
		cin >> numero;
		if(cin.fail()){
			cout << "Entrada no válida, debes ingresar un número entero, intentalo de nuevo" << endl;
			cin.clear(); //quita el flag de error
			cin.ignore(numeric_limits<streamsize>::max(),'\n'); //quita todo lo restante en el buffer
		} else {
			cin.ignore(numeric_limits<streamsize>::max(),'\n'); //quita lo restante del buffer, por ejemplo \t, \n, etc.
			return numero;
		}
	}
}

double pedirDouble(){
	double numero;
	while(true){
		cin >> numero;
		if(cin.fail()){
			cout << "Entrada no válida, debes ingresar un número, intentalo de nuevo" << endl;
			cin.clear(); //quita el flag de error
			cin.ignore(numeric_limits<streamsize>::max(),'\n'); //quita todo lo restante en el buffer
		} else {
			cin.ignore(numeric_limits<streamsize>::max(),'\n'); //quita lo restante del buffer, por ejemplo \t, \n, etc.
			return numero;
		}
	}
}
