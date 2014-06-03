#include "automata.h"

Automata::Automata(int tipo):num_colores(5){
	int** matriz=0;
	
	// Reservar espacio
	motor=new Motor;
	EstadoJuego *estadoInicial=new EstadoJuego;
	
	motor->setEstadoJuego(estadoInicial);

	tamTablero=motor->getTamTablero();

	matriz=new int*[tamTablero];
	for (int i= 0; i<tamTablero; i++) {
		matriz[i]= new int[tamTablero];
	}
	// Semilla aleatoria
	if(tipo==0){
		std::srand((unsigned)std::time(0));
		for(int i=0; i<tamTablero; i++){
			for(int j=0; j<tamTablero; j++){
				matriz[i][j]=(std::rand()%num_colores)+1;
			}
		}
	}
	motor->sustituirMatriz(matriz);
	

}
Automata::~Automata(){	delete motor;}
bool Automata::reservaEspacioMatriz(int** mat, int tam){
	// Reserva espacio en memoria para una matriz
	// de tamaño [tam x tam]
	mat=new int*[tam];
	if(!mat) return false;
	for (int i= 0; i<tam; i++) {
		mat[i]= new int[tam];
		if (!mat[i]) return false;
	}
	return true;
}
void Automata::copiarMatriz(int** destino, int** origen){
	if(!destino or !origen) return;
	for(int i=0; i<tamTablero; i++){
		for(int j=0; j<tamTablero; j++){
			destino[i][j]=origen[i][j];
		}
	}
}
void Automata::setNumColores(int x){ num_colores=x; }
void Automata::imprimeMatriz(int** matriz){
	for(int i=0; i<tamTablero; i++){
		for(int j=0; j<tamTablero; j++){
			std::cout << " " << matriz[i][j];
		}
		std::cout <<"\n";
	}
}
void Automata::muestraEstado(EstadoJuego* e){
	imprimeMatriz(e->getMatriz());
	std::cout << "Puntos: " << e->getPuntos();
	std::cout << "\n";	
}
void Automata::ejecutar(){
	std::cout << "\nHola soy Anthony...\n";
	
	EstadoJuego* inicial=motor->getEstadoJuego();
	std::cout << "Esto es el estado inicial:\n";
	muestraEstado(inicial);
	//std::cout << "Puntos totales : " << recursion(inicial, motor, 0, 0);
	std::cout << std::endl;
	r2(new EstadoJuego(inicial), 0, 0, 3);
	std::cout << "Esto es el estado inicial despues de r2:\n";
	muestraEstado(inicial);
}
int Automata::calculaMovimientosPosibles(EstadoJuego* e, int x, int y){
	
}
int Automata::r2(EstadoJuego* e, int x, int y, int iteraciones){
	
	// Encontrar posibles movimientos:
	// Si hay 0 movimientos posibles o no podemos
	// hacer más iteraciones acaba la recursión.
	
	motor->encontrarAdyacentes(x,y);
	motor->go();
	
	std::cout << "Esto es el estado inicial dentro de r2:\n";
	muestraEstado(e);
	//int p=calculaMovimientosPosibles(e, x, y);
	//if(p==0 or iteraciones==0) return 0;
	
	
	return 0;
}

