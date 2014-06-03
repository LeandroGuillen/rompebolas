#ifndef LPANEL_H_
#define LPANEL_H_

#include <QWidget>
#include <QPainter>
#include "motor.h"

class LPanel : public QWidget{
	Q_OBJECT
public:
	LPanel(QWidget*);
	
private slots:
	void nuevo(bool);

signals:
	void puntosCambiados(int);
	void puntosActuales(int);
	void puntosLimpiar(QString);
private:
	// Colores para las distintas bolas
	static const int ROJO=1;
	static const int AZUL=2;
	static const int AMARILLO=3;
	static const int VERDE=4;
	static const int ROSA=5;
	int TAM_BOLA;
	int posx, posy;
	int puntos;
	
	bool bolaSola;
	
	QImage *rojaPNG;
	QImage *azulPNG;
	QImage *verdePNG;
	QImage *amarillaPNG;
	QImage *rosaPNG;
	QImage *nadaPNG;
	
	// Calcula estados del juego
	Motor *motor;
	
	// Guarda las opciones de la partida
	enum Estilo { CONTINUO, CLASICO } estilo;
	enum Disposicion { ALEATORIO, MANUAL } disposicion;
	int num_colores;
	
	// Funciones
	void pintaBola(QPainter&, int, int, int);
	void pintaBolas(QPainter&);
	
	// Dado un punto en el widget
	// devuelven la posicion en la matriz
	int calculaCoordenada(int);

protected:
	void paintEvent(QPaintEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseDoubleClickEvent(QMouseEvent*);
};

#endif
