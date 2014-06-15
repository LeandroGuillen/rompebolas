#ifndef MOTOR_H_
#define MOTOR_H_

#include "estadojuego.h"

class Motor {
public:
	Motor();
	~Motor();
	
	int** getMatriz();
	int** getAdyacentes();
	
	int getPuntos();
	int calcularPuntos();
	int getTamTablero();
	int getNumSeleccionadas();
	void sustituirMatriz(int **);
	void encontrarAdyacentes(int, int);
	void restableceAdyacentes();
	void go(int estilo=0);
	void restableceSeleccionadas();
	
	void setEstadoJuego(EstadoJuego*);
	EstadoJuego* getEstadoJuego();
	void destruyeEstadoActual();
	
private:
	EstadoJuego* estado;
	int TAM_TABLERO;
	
	struct Posicion {
		int fila, col;
	};
	void meteNuevaColumna();

	/**
	 * Condicion para saber si se han de añadir nuevas
	 * columnas por la izquierda.
	 */
	bool hayColumnasLibres();

	/**
	 * Comprueba si la partida se puede continuar o no,
	 * basandose en si hay al menos dos bolas del mismo
	 * color adyacentes.
	 */
	bool finPartida(); // NO IMPLEMENTADO

	/**
	 * Procedimiento recursivo que busca en la rejilla
	 * hacia arriba, hacia abajo, hacia la izquierda y
	 * hacia la derecha del la posicion actual, avanzando
	 * por las ramas en que las bolas son adyacentes.
	 */
	void encontrarAdyacentes(Posicion&);

	/**
	 * Intecambia el valor de dos enteros.
	 */
	void intercambia(int&, int&);

	/**
	 * Dado un tablero marca como borradas (borra) las bolas que habian
	 * sido seleccionadas por encontrarAdyacentes.
	 */
	void borrarAdyacentes();

	/**
	 * Baja todas las bolas por "gravedad".
	 */
	void bajarColumnas();

	/**
	 * Mueve todos las bolas hacia la derecha en una fila.
	 * @param v Vector que contiene las bolas.
	 */
	void moverDerecha(int *v);

	/**
	 * Mueve todas las bolas del tablero a la derecha.
	 */
	void moverDerecha();
};

#endif
