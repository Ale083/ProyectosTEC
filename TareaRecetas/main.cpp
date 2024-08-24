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
	int opcion;
    cin >> opcion;
    cin.ignore();
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
	cout << "Presiona enter para volver al men�";
	getline(cin,temp);
	system("cls");
}
