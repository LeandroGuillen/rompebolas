#ifndef ESTADOJUEGO_H
#define ESTADOJUEGO_H

#define TAM 11

class EstadoJuego {

public:
	EstadoJuego();
	EstadoJuego(EstadoJuego*);
	~EstadoJuego();
	int** getMatriz();
	int** getAdyacentes();
	
	int getNumSeleccionadas();
	int getPuntos();
	int getNumColores(){ return num_colores; }
	int getTamTablero(){ return tamTablero; }
	void setNumColores(int x){ num_colores=x; }
	void setNumSeleccionadas(int);
	void sustituirMatriz(int**);
	void sustituirAdyacentes(int**);
	void setPuntos(int);
	

private:
	int ** matriz;
	int ** adyacentes;
	int numero_seleccionadas;
	int puntuacion;
	int num_colores;
	int tamTablero;
};

#endif
