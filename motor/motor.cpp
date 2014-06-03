#include "motor.h"

Motor::Motor() : estado(0), TAM_TABLERO(0) {}
Motor::~Motor()	{	destruyeEstadoActual();}
void	Motor::setEstadoJuego(EstadoJuego* e){
	estado=e;
	TAM_TABLERO=estado->getTamTablero();
	restableceAdyacentes();
}
void Motor::destruyeEstadoActual(){	if(!estado) delete estado;}
EstadoJuego* Motor::getEstadoJuego(){	return estado; }
int**	Motor::getMatriz(){ 	return estado->getMatriz(); }
int**	Motor::getAdyacentes(){ return estado->getAdyacentes(); }
int	Motor::getTamTablero(){ return estado->getTamTablero(); }
void 	Motor::sustituirMatriz(int **nueva){	estado->sustituirMatriz(nueva);}
void 	Motor::encontrarAdyacentes(int x, int y){
	Posicion p;
	p.fila=x;
	p.col=y;
	encontrarAdyacentes(p);
}
void 	Motor::encontrarAdyacentes(Posicion &p){
	// Vamos a ver que bolas adyacentes son del
	// mismo color que la que esta en 'p'
	Posicion nuevaPos;
	estado->setNumSeleccionadas(estado->getNumSeleccionadas()+1);
	
	// Si p esta fuera del tablero hemos terminado
	if(p.fila<0 || p.fila>=TAM_TABLERO || p.col<0 || p.col>=TAM_TABLERO) return;
	estado->getAdyacentes()[p.fila][p.col]=1;
	
	nuevaPos.fila=p.fila-1;
	nuevaPos.col=p.col;
	//		· X ·
	//		· o ·
	//		· · ·
	if(p.fila>0 && estado->getAdyacentes()[p.fila-1][p.col]==0 &&
	estado->getMatriz()[nuevaPos.fila][nuevaPos.col]==estado->getMatriz()[p.fila][p.col]){
		encontrarAdyacentes(nuevaPos);
	}
	
	nuevaPos.fila=p.fila+1;
	nuevaPos.col=p.col;
	//		· · ·
	//		· o ·
	//		· X ·
	if(p.fila<TAM_TABLERO-1 && estado->getAdyacentes()[p.fila+1][p.col]==0 &&
	estado->getMatriz()[nuevaPos.fila][nuevaPos.col]==estado->getMatriz()[p.fila][p.col]){
		encontrarAdyacentes(nuevaPos);
	}
	
	nuevaPos.fila=p.fila;
	nuevaPos.col=p.col-1;
	//		· · ·
	//		X o ·
	//		· · ·
	if(p.col>0 && estado->getAdyacentes()[p.fila][p.col-1]==0  &&
	estado->getMatriz()[nuevaPos.fila][nuevaPos.col]==estado->getMatriz()[p.fila][p.col]){
		encontrarAdyacentes(nuevaPos);
	}
	
	nuevaPos.fila=p.fila;
	nuevaPos.col=p.col+1;
	//		· · ·
	//		· o X
	//		· · ·
	if(p.col<TAM_TABLERO-1 && estado->getAdyacentes()[p.fila][p.col+1]==0 &&
	estado->getMatriz()[nuevaPos.fila][nuevaPos.col]==estado->getMatriz()[p.fila][p.col]){
		encontrarAdyacentes(nuevaPos);
	}
}
void 	Motor::restableceAdyacentes(){
	for(int i=0; i<TAM_TABLERO; i++){
		for(int j=0; j<TAM_TABLERO; j++){
			if(estado->getMatriz()[i][j]!=0) estado->getAdyacentes()[i][j]=0;
			else estado->getAdyacentes()[i][j]=-1;
		}
	}
	restableceSeleccionadas();
}
void 	Motor::restableceSeleccionadas(){	estado->setNumSeleccionadas(0); }
void 	Motor::go(int estilo){
	// Calcula la nueva puntuacion
	estado->setPuntos(estado->getPuntos()+calcularPuntos());
	borrarAdyacentes();
	
	moverDerecha();
	if(!estilo) bajarColumnas();
	if(hayColumnasLibres()) meteNuevaColumna();
}
bool	Motor::hayColumnasLibres(){return estado->getMatriz()[0][TAM_TABLERO-1]==0; }
void	Motor::meteNuevaColumna(){
	// Copio la matriz en una temporal
	// con el constructor de copia
	//~ int** temp=estado->getMatriz();
	//~ int** matrizTemp=temp;
	
}
bool	Motor::finPartida(){		return false;}
void	Motor::intercambia(int &a, int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int	Motor::calcularPuntos(){return estado->getNumSeleccionadas()*(estado->getNumSeleccionadas()-1);}
int	Motor::getPuntos() { 	return estado->getPuntos(); }
int	Motor::getNumSeleccionadas() {return estado->getNumSeleccionadas(); }
void	Motor::bajarColumnas(){
	int k;
	for(int b=0; b<estado->getNumSeleccionadas(); b++){	
		for(int i=TAM_TABLERO-1; i>0; --i){
			for(int j=0; j<TAM_TABLERO; j++){
				if(estado->getMatriz()[i][j]==0){
					k=i-1;
					intercambia(estado->getMatriz()[i][j], estado->getMatriz()[k][j]);
				}
			}
		}
	}
}
void	Motor::moverDerecha(int *v){
	for(int i=TAM_TABLERO-1, j; i>=0; i--){
		j=i-1;
		while(v[j+1]==0 && j>=0){
			intercambia(v[j], v[j+1]);
			j--;
		}
	}	
}
void	Motor::moverDerecha(){
	for(int j=0; j<estado->getNumSeleccionadas(); j++){
		for(int i=0; i<TAM_TABLERO; i++){
			moverDerecha(estado->getMatriz()[i]);
		}
	}
}
void	Motor::borrarAdyacentes(){
	if(estado->getNumSeleccionadas()>1){
		for(int i=0; i<TAM_TABLERO; i++){
			for(int j=0; j<TAM_TABLERO; j++){
				if(estado->getAdyacentes()[i][j]==1) estado->getMatriz()[i][j]=0;
			}
		}	
	}
}
