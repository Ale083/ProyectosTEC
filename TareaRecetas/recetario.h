struct Recetario{
	Receta LibroDeRecetas[100];
	int numRecetas;
	
	Recetario(){ //constructor default.
		numRecetas = 0;
	}
	
void nuevaReceta(){
	LibroDeRecetas[numRecetas]._init_(LibroDeRecetas,numRecetas); // Necesita llevarse libroDeRecetas y numRecetas para que no repita nombre
	++numRecetas;
}

void buscarReceta(){
	int indexReceta = buscarIndexReceta();
	if (indexReceta == -1){ //si dio error
		return;
	} else{
		LibroDeRecetas[indexReceta].imprimir();
		wait();
		return;
	}
}

void borrarReceta(){
	int indexReceta = buscarIndexReceta();
	if (indexReceta == -1){ //si dio error
		return;
	} else{
		for (int i = indexReceta; i < numRecetas - 1; i++) {
        	LibroDeRecetas[i] = LibroDeRecetas[i + 1];
    	}
    	LibroDeRecetas[--numRecetas] = Receta();
    	return;
	}
}


void printRecetas(){
	for(int i=0;i<numRecetas;i++){
		LibroDeRecetas[i].imprimir();
	}
	wait();
	return;
}


void modificarNombreReceta(){
	int indexReceta = buscarIndexReceta();
	if (indexReceta == -1){ //si dio error
		return;
	} else{
		LibroDeRecetas[indexReceta].cambiarNombre(LibroDeRecetas, numRecetas); // Necesita parametros para que no repita nombre
    	return;
	}
}

void modificarCantIngrediente(){
	int indexReceta = buscarIndexReceta();
	if (indexReceta == -1){//si dio error
		return;
	} else{
		LibroDeRecetas[indexReceta].cambiarCantIngrediente();
    	return;
	}
}

void agregarIngrediente(){
	int indexReceta = buscarIndexReceta();
	if (indexReceta == -1){//si dio error
		return;
	} else{
		LibroDeRecetas[indexReceta].anadirIngrediente();
    	return;
	}
}

void calcularParaPorciones(){
	int indexReceta = buscarIndexReceta();
	if (indexReceta == -1){//si dio error
		return;
	} else{
		LibroDeRecetas[indexReceta].calcularParaPorciones();
		wait();
    	return;
	}	
}

void sustituirIngredienteEnRecetas(){
	cout << "Cual es el ingrediente que quieres modificar" << endl;
	string busqueda;
	getline(cin,busqueda);
	cout << "A continuación vas a declarar el nuevo ingrediente con el que lo sustituirás." << endl;
	Ingrediente nuevoIngrediente;
	nuevoIngrediente.inicializarIngredienteSinValidacion();
	for (int i=0;i<numRecetas;i++){ 
		LibroDeRecetas[i].sustituirIngredienteEnReceta(busqueda,nuevoIngrediente);
	}
}


int buscarIndexReceta(){
	cout << "Pon el nombre de la receta" << endl;
	string busqueda;
	getline(cin,busqueda);
	for (int i=0;i<numRecetas;i++){
		if(LibroDeRecetas[i].nombre == busqueda){
			return i;
		}
	}
	cout << "No se encontró la receta" << endl;
	wait();
	return -1;
}

};
