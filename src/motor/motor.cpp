#include "motor.h"

Motor::Motor(){
	numero_seleccionadas=0;
	puntuacion=0;
	// Reserva espacio en memoria
	matriz = new int*[TAM_TABLERO];
	adyacentes = new int*[TAM_TABLERO];
	for(int i= 0; i<TAM_TABLERO; i++){
		matriz[i]= new int [TAM_TABLERO];
		adyacentes[i]= new int [TAM_TABLERO];
	}
	restableceAdyacentes();
}

int** Motor::getMatriz(){ return matriz; }
int** Motor::getAdyacentes(){ return adyacentes; }
void Motor::sustituirMatriz(int **nueva){
	int **temp=matriz;
	matriz=nueva;
	
	for(int i= 0; i<TAM_TABLERO; i++){
		delete temp[i];
	}
	delete [] temp;
}

Motor::~Motor(){	
	for(int i= 0; i<TAM_TABLERO; i++){
		delete matriz[i];
		delete adyacentes[i];
	}
	delete [] matriz;
	delete [] adyacentes;
}
void Motor::rellenaConAleatorios(){
	// implementado en la interfaz
}
void Motor::encontrarAdyacentes(int x, int y){
	Posicion p;
	p.fila=x;
	p.col=y;
	encontrarAdyacentes(p);
}
void Motor::encontrarAdyacentes(Posicion &p){
	
	Posicion nuevaPos;
	
	numero_seleccionadas++;
	
	if(p.fila<0 || p.fila>=TAM_TABLERO || p.col<0 || p.col>=TAM_TABLERO) return;
	adyacentes[p.fila][p.col]=1;
	
	nuevaPos.fila=p.fila-1;
	nuevaPos.col=p.col;
	
	if(p.fila>0 && adyacentes[p.fila-1][p.col]==0 &&
	matriz[nuevaPos.fila][nuevaPos.col]==matriz[p.fila][p.col]){
		encontrarAdyacentes(nuevaPos);
	}
	
	nuevaPos.fila=p.fila+1;
	nuevaPos.col=p.col;
	
	if(p.fila<TAM_TABLERO-1 && adyacentes[p.fila+1][p.col]==0 &&
	matriz[nuevaPos.fila][nuevaPos.col]==matriz[p.fila][p.col]){
		encontrarAdyacentes(nuevaPos);
	}
	
	nuevaPos.fila=p.fila;
	nuevaPos.col=p.col-1;
	
	if(p.col>0 && adyacentes[p.fila][p.col-1]==0  &&
	matriz[nuevaPos.fila][nuevaPos.col]==matriz[p.fila][p.col]){
		encontrarAdyacentes(nuevaPos);
	}
	
	nuevaPos.fila=p.fila;
	nuevaPos.col=p.col+1;
	
	if(p.col<TAM_TABLERO-1 && adyacentes[p.fila][p.col+1]==0 &&
	matriz[nuevaPos.fila][nuevaPos.col]==matriz[p.fila][p.col]){
		encontrarAdyacentes(nuevaPos);
	}
}

void Motor::restableceAdyacentes(){
	for(int i=0; i<TAM_TABLERO; i++){
		for(int j=0; j<TAM_TABLERO; j++){
			if(matriz[i][j]!=0) adyacentes[i][j]=0;
			else adyacentes[i][j]=-1;
		}
	}
	numero_seleccionadas=0;
}

void Motor::go(int estilo){
	puntuacion+=calcularPuntos();
	borrarAdyacentes();
	
	moverDerecha();
	if(!estilo) bajarColumnas();
}

bool Motor::hayColumnasLibres(){ return matriz[0][TAM_TABLERO-1]==0; }
bool Motor::finPartida(){ return false; }

void Motor::intercambia(int &a, int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int Motor::calcularPuntos(){	return numero_seleccionadas*(numero_seleccionadas-1);}
int Motor::getPuntos() { return puntuacion; }

void Motor::bajarColumnas(){
	int k;
	for(int b=0; b<numero_seleccionadas; b++){	
		for(int i=TAM_TABLERO-1; i>0; --i){
			for(int j=0; j<TAM_TABLERO; j++){
				if(matriz[i][j]==0){
					k=i-1;
					intercambia(matriz[i][j], matriz[k][j]);
				}
			}
		}
	}
}
void Motor::moverDerecha(int *v){
	for(int i=TAM_TABLERO-1, j; i>=0; i--){
		j=i-1;
		while(v[j+1]==0 && j>=0){
			intercambia(v[j], v[j+1]);
			j--;
		}
	}	
}
void Motor::moverDerecha(){
	for(int j=0; j<numero_seleccionadas; j++){
		for(int i=0; i<TAM_TABLERO; i++){
			moverDerecha(matriz[i]);
		}
	}
}

void Motor::borrarAdyacentes(){
	if(numero_seleccionadas>1){
		for(int i=0; i<TAM_TABLERO; i++){
			for(int j=0; j<TAM_TABLERO; j++){
				if(adyacentes[i][j]==1) matriz[i][j]=0;
			}
		}	
	}
}
