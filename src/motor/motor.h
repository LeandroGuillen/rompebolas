#ifndef MOTOR_H_
#define MOTOR_H_

#define TAM_TABLERO 11

class Motor {
public:
	Motor();
	~Motor();
	
	int** getMatriz();
	int** getAdyacentes();
	int getPuntos();
	int calcularPuntos();
	int getTamTablero(){ return TAM_TABLERO; }
	int nSeleccionadas(){ return numero_seleccionadas; }
	void sustituirMatriz(int **);
	void encontrarAdyacentes(int, int);
	void restableceAdyacentes();
	void go(int);
	void restableceSeleccionadas(){numero_seleccionadas=0;};
	
	
private:
	int ** matriz;
	int ** adyacentes;
	int numero_seleccionadas;
	int puntuacion;
	
	struct Posicion {
		int fila, col;
	};

	bool hayColumnasLibres();
	/** finPartida
	 * Comprueba si la partida se puede continuar o no,
	 * basandose en si hay al menos dos bolas del mismo
	 * color adyacentes.*/
	bool finPartida();
	void rellenaConAleatorios();
	void encontrarAdyacentes(Posicion&);
	void intercambia(int&, int&);
	/** borrarAdyacentes
	 * Dado un tablero marca como borradas (borra) las bolas que habian
	 * sido seleccionadas por encontrarAdyacentes.*/
	void borrarAdyacentes();
	/** bajarColumnas
	 * Baja todas las bolas por "gravedad".*/
	void bajarColumnas();
	/** moverDerecha
	 * Mueve todos las bolas hacia la derecha en una fila.
	 * @param v Vector que contiene las bolas.*/
	void moverDerecha(int *v);
	/** moverDerecha
	 * Mueve todas las bolas del tablero a la derecha.
	 * @param t Tablero cuyas bolas se mueven.*/
	void moverDerecha();
};

#endif
