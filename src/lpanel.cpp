#include "lpanel.h"
#include <QApplication>
#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QTime>

LPanel::LPanel(QWidget *parent=0) : QWidget(parent) {
	motor=new Motor;
	
	// Opciones por defecto
	estilo=CONTINUO;
	disposicion=ALEATORIO;
	num_colores=5;
	
	// Cargamos cada imagen en una variable
	rojaPNG=new QImage(":/imagenes/roja.png");
	azulPNG=new QImage(":/imagenes/azul.png");
	verdePNG=new QImage(":/imagenes/verde.png");
	rosaPNG=new QImage(":/imagenes/rosa.png");
	amarillaPNG=new QImage(":/imagenes/amarilla.png");
	nadaPNG=new QImage(":/imagenes/nada.PNG");
	
	TAM_BOLA=rojaPNG->width();
	bolaSola=false;
	
	nuevo(true);
}

void LPanel::nuevo(bool b){
	if(b){
		int tamTablero=motor->getTamTablero();
		int **mat;
		QTime tiempo(QTime::currentTime());
		
		// Reserva espacio en memoria
		mat = new int*[tamTablero];
		for(int i= 0; i<tamTablero; i++){
			mat[i]= new int [tamTablero];
		}
		// Distribuye las bolas segun la disposicion
		// escogida.
		switch(disposicion){
			case ALEATORIO:
				qsrand(tiempo.msec()+tiempo.second());
				for(int i=0; i<tamTablero; i++){
					for(int j=0; j<tamTablero; j++){
						mat[i][j]=(qrand()%num_colores)+1;
					}
				}
				// Le digo al motor que matriz debe usar
				motor->sustituirMatriz(mat);
				break;
			case MANUAL:
				// *** No implementado ***
				break;
		}
		update();
	}
}

void LPanel::mousePressEvent(QMouseEvent* event){
	// Calcula la bola correspondiente
	// a las coordenadas del evento
	posx=calculaCoordenada(event->x());
	posy=calculaCoordenada(event->y());
	
	// Reiniciamos bolas seleccionadas
	motor->restableceAdyacentes();
	
	if(posx>=0 and posy>=0){
		// Buscamos bolas adyacentes a la seleccion
		motor->encontrarAdyacentes(posx, posy);
		
		// Si hay mas de una bola adyacente 
		// informamos de que nos va a dar puntos
		if(motor->nSeleccionadas()>1)
			emit puntosActuales(motor->calcularPuntos());
		else {
			emit puntosLimpiar("");
			motor->restableceAdyacentes();
		}
	}
	else emit puntosLimpiar("");
	// Refrescamos el widget
	update();
}
void LPanel::mouseDoubleClickEvent(QMouseEvent* event){
	int puntosTemp=0;
	// Calcula la bola correspondiente
	// a las coordenadas del evento
	posx=calculaCoordenada(event->x());
	posy=calculaCoordenada(event->y());
	
	if(posx>=0 and posy>=0){
		// Buscamos bolas adyacentes a la seleccion
		motor->encontrarAdyacentes(posx, posy);
		if(motor->nSeleccionadas()>1){
			motor->go(estilo);
			puntosTemp=motor->getPuntos();
			if(puntosTemp!=puntos){
				puntos=puntosTemp;
				emit puntosCambiados(puntos);
			}
		} else motor->restableceSeleccionadas();
	}
	emit puntosLimpiar("");
	motor->restableceAdyacentes();
	update();
}

int LPanel::calculaCoordenada(int n){
	if(n>0 and n<TAM_BOLA*motor->getTamTablero())
		return n/TAM_BOLA;
	else return -1;
}

void LPanel::paintEvent(QPaintEvent *event){
	QPainter painter(this);
	pintaBolas(painter);
}

void LPanel::pintaBolas(QPainter& painter){
	int **mat=motor->getMatriz();
	for(int i=0; i<11; i++){
		for(int j=0; j<11; j++){
			pintaBola(painter, i, j, mat[i][j]);
		}
	}
}

void LPanel::pintaBola(QPainter &painter, int x, int y, int color){
	// Pinta la imagen 't' segun que bola sea
	QImage *t;
	switch(color){
		case ROJO:
			t=rojaPNG;
			break;
		case AZUL:
			t=azulPNG;
			break;
		case AMARILLO:
			t=amarillaPNG;
			break;
		case ROSA:
			t=rosaPNG;
			break;
		case VERDE:
			t=verdePNG;
			break;
		default:
			t=nadaPNG;
	}
	painter.drawImage(x*TAM_BOLA, y*TAM_BOLA, *t);
	if(motor->getAdyacentes()[x][y]==1 and motor->nSeleccionadas()>1)
		painter.drawRect(x*TAM_BOLA, y*TAM_BOLA, TAM_BOLA, TAM_BOLA);
	
}


