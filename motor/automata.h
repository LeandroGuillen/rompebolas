#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

#include "estadojuego.h"
#include "motor.h"

class Automata {
public:
	Automata(int);
	~Automata();
	
	// Métodos publicos
	void ejecutar();
	void setNumColores(int);
private:
	// Atributos privados
	Motor* motor;
	int num_colores;
	int tamTablero;

	// Métodos privados
	bool reservaEspacioMatriz(int**, int);
	void copiarMatriz(int**, int**);
	void imprimeMatriz(int**);
	void muestraEstado(EstadoJuego*);

	int calculaMovimientosPosibles(EstadoJuego*, int, int);
	int r2(EstadoJuego*, int, int, int);
};

#endif
