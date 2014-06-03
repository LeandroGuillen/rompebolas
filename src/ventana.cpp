#include "ventana.h"

Ventana::Ventana(QWidget *parent) : QMainWindow(parent) {
	setupUi(this);
	preferencias=NULL;
	
	connect(actionPreferencias, SIGNAL(triggered()),
			this, SLOT(muestraPreferencias()));
	connect(actionNuevo, SIGNAL(triggered(bool)),
			widget, SLOT(nuevo(bool)));
	
	connect(widget, SIGNAL(puntosCambiados(int)), puntos, SLOT(setNum(int)));
	connect(widget, SIGNAL(puntosActuales(int)), puntosJugadaActual, SLOT(setNum(int)));
	connect(widget, SIGNAL(puntosLimpiar(QString)), puntosJugadaActual, SLOT(setText(QString)));
	
}


void Ventana::muestraPreferencias(){
	if(!preferencias) preferencias=new Preferencias;
	preferencias->show();
	preferencias->activateWindow();
}
