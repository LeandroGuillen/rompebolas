#include "estadojuego.h"

EstadoJuego::EstadoJuego(){ // CONSTRUCTOR
	numero_seleccionadas=0;
	puntuacion=0;
	tamTablero=TAM;
	// Reserva espacio en memoria
	matriz = new int*[tamTablero];
	adyacentes = new int*[tamTablero];
	for(int i= 0; i<tamTablero; i++){
		matriz[i]= new int [tamTablero];
		adyacentes[i]= new int [tamTablero];
	}
}
EstadoJuego::EstadoJuego(EstadoJuego* ej){
	if(ej){
		this->puntuacion=ej->puntuacion;
		this->tamTablero=ej->tamTablero;
		this->numero_seleccionadas=0;
		this->puntuacion=ej->puntuacion;
		// Reserva espacio en memoria
		matriz = new int*[tamTablero];
		adyacentes = new int*[tamTablero];
		for(int i= 0; i<tamTablero; i++){
			matriz[i]= new int [tamTablero];
			adyacentes[i]= new int [tamTablero];
		}
		sustituirAdyacentes(ej->getAdyacentes());
		sustituirMatriz(ej->getMatriz());
	}
}
EstadoJuego::~EstadoJuego(){ // DESTRUCTOR
	for(int i= 0; i<tamTablero; i++){
		delete matriz[i];
		delete adyacentes[i];
	}
	delete [] matriz;
	delete [] adyacentes;
}
int**	EstadoJuego::getMatriz(){ return matriz; }
int**	EstadoJuego::getAdyacentes(){ return adyacentes; }
int		EstadoJuego::getNumSeleccionadas(){ return numero_seleccionadas; }
void	EstadoJuego::setNumSeleccionadas(int n){ numero_seleccionadas=n; }
void	EstadoJuego::setPuntos(int puntos){	puntuacion=puntos;}
int		EstadoJuego::getPuntos(){ return puntuacion; }
void	EstadoJuego::sustituirMatriz(int **nueva){
	int **temp=matriz;
	matriz=nueva;
	for(int i=0; i<tamTablero; i++){
		delete temp[i];
	}
	delete [] temp;
}
void 	EstadoJuego::sustituirAdyacentes(int** nueva){
	int **temp=adyacentes;
	adyacentes=nueva;
	for(int i=0; i<tamTablero; i++){
		delete temp[i];
	}
	delete [] temp;
}

