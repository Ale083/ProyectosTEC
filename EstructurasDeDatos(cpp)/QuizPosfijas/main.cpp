#include "estructuras.h"
bool esValido(char operador);
int obtenerPrioridad(char operador);
bool esNum(char caracter);
string infijasAPosfijas(string expInfija);
double posfijasAInfijas(string expPosfija);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//string expresionInfija = "(5*(3+8*2)*5)/2";
	char expresionInfija[] = "(5*(3+8*2)*5)/2"; //Demuestra que si sirve con string, sirve con char*
	string expresionPosfija = infijasAPosfijas(expresionInfija);
	cout << expresionPosfija << endl;
	cout << posfijasAInfijas(expresionPosfija) << endl;
	
	return 0;
}
bool esValido(char operador){
	if(obtenerPrioridad(operador) == -1){
		return false;
	}
	return true;
}

int obtenerPrioridad(char operador){
	switch (operador){
		case '^': return 3;
		case '*': return 2;
		case '/': return 2;
		case '+': return 1;
		case '-': return 1;
		case '(': return 0;
		case ')': return 0;
		default: return -1; //usar para validar casos de error.
	}
}

bool esNum(char caracter){
	if (caracter == '0' || caracter == '1' || caracter == '2' || caracter == '3' || caracter == '4' || caracter == '5' || caracter == '6' || caracter == '7' || caracter == '8' || caracter == '9'){
		return true;
	} else {
		return false;
	}
}

string infijasAPosfijas(string expInfija){
	PilaChar* pila = new PilaChar();
	string resultado = "";
	while(expInfija != ""){
		
		char caracter = expInfija[0];
		if (caracter == ' '){ //Si es espacio
		} 
		
		else if (esNum(caracter)){ //Si es número
			resultado += caracter;
			resultado += ' ';
		} 
		
		else if(caracter == '('){ //Si es (
			pila -> push(caracter);
		} 
		
		else if (caracter == ')'){ //Si es )
			while (pila -> peek() -> dato != '('){
				resultado += pila -> pop() -> dato;
				resultado += ' ';
			}
			//El top de la pila en este momento sería el (
			pila -> pop();
		} 
		
		else if (esValido(caracter)){ //Si es operador
			while (!(pila -> isEmpty()) && obtenerPrioridad(pila -> peek() -> dato) >= obtenerPrioridad(caracter)){
				resultado += pila -> pop() -> dato;
				resultado += ' ';
				
			}
			pila -> push(caracter);
		} else { //Si es caracter invalido.
			cout << "Uno o más caracteres no son válidos." << endl;
			return "";
		}
		
		expInfija.erase(0,1);
	}
	
	while(!(pila -> isEmpty())){
		resultado += pila -> pop() -> dato;
		resultado += ' ';
	}
	return resultado;
}

double posfijasAInfijas(string expPosfija){
	PilaDouble* pila = new PilaDouble();
	while(expPosfija != ""){
		char caracter = expPosfija[0];
		if (caracter == ' '){
		}
		
		else if (esNum(caracter)){
			int valor = caracter - '0';
			pila -> push (valor);
		}
		
		else if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/' || caracter == '^') {
            if (pila -> isEmpty() || pila -> peek()->anterior == NULL) {
                cout << "No hay suficientes operandos para el operador." << endl;
                return -1;
            }
            double b = pila -> pop() -> dato;
            double a = pila -> pop() -> dato;
            switch (caracter) {
                case '+': 
					pila -> push(a+b); 
					break;
                case '-': 
					pila -> push(a-b); 
					break;
                case '*': 
					pila -> push(a*b); 
					break;
                case '/':
                    if (b == 0) {
                        cout << "Error: división por cero." << endl;
                        return -1;
                    }
                    pila -> push(a/b);
					break;
                default:
                    cout << "Operador no reconocido." << endl;
                    return -1;
            }
		}
		expPosfija.erase(0,1);
	}
	if (pila -> isEmpty() || pila-> peek()->anterior != NULL) { //el resultado deberia ser el unico en la pila. No puede tener ni 0 ni mas de 1.
        cout << "Error: la expresión no es válida." << endl;
    	return -1;
   	}
	return pila -> pop() -> dato;
}
