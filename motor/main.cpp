#include "automata.h"

int main(void){
	// Declaro objetos del programa
	Automata *anthony;

	// TIPO 0 -> Tablero aleatorio
	anthony=new Automata(0);

	anthony->setNumColores(5);
	anthony->ejecutar();
	
	// Eliminar objetos
	if(anthony) delete anthony;
	return 0;
}
