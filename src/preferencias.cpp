#include "preferencias.h"

Preferencias::Preferencias(QWidget *parent) :QDialog(parent){
	setupUi(this);
	
	disposicion=ALEATORIO;
	estilo=CONTINUO;
	num_colores=5;
	
	// Para el modo manual
	rojas=25;
	amarillas=azules=rosas=verdes=24;
	
	establecerConexiones();
}

void Preferencias::cantidadRojas(int n){
	if(rojas+amarillas+azules+rosas+verdes <= 121)
		rojas=n;
	else emit restaurarRojas(n-1);
}
void Preferencias::cantidadVerdes(int n){
	if(rojas+amarillas+azules+rosas+verdes <= 121)
		verdes=n;
	else emit restaurarVerdes(n-1);
}
void Preferencias::cantidadAzules(int n){
	if(rojas+amarillas+azules+rosas+verdes <= 121)
		azules=n;
	else emit restaurarAzules(n-1);
}
void Preferencias::cantidadRosas(int n){
	if(rojas+amarillas+azules+rosas+verdes <= 121)
		rosas=n;
	else emit restaurarRosas(n-1);
}
void Preferencias::cantidadAmarillas(int n){
	if(rojas+amarillas+azules+rosas+verdes <= 121)
		amarillas=n;
	else emit restaurarAmarillas(n-1);
}
void Preferencias::actualizarDisposicion(bool b){
	if(b) disposicion=ALEATORIO;
	else disposicion=MANUAL;
}

void Preferencias::actualizarEstilo(bool b){
	if(b) estilo=CONTINUO;
	else estilo=CLASICO;
}

void Preferencias::actualizarNumColores(int n){
	if(n>=3 and n<=5) num_colores=n;
}

void Preferencias::establecerConexiones(){
	connect(radio_Aleatorio, SIGNAL(toggled(bool)),
			this, SLOT(actualizarDisposicion(bool)));
	connect(radio_Continuo, SIGNAL(toggled(bool)),
			this, SLOT(actualizarEstilo(bool)));
	connect(spinBox_Colores, SIGNAL(valueChanged(int)),
			this, SLOT(actualizarNumColores(int)));
	
	connect(nrojas, SIGNAL(valueChanged(int)),
			this, SLOT(cantidadRojas(int)));
	connect(nverdes, SIGNAL(valueChanged(int)),
			this, SLOT(cantidadVerdes(int)));
	connect(nazules, SIGNAL(valueChanged(int)),
			this, SLOT(cantidadAzules(int)));
	connect(namarillas, SIGNAL(valueChanged(int)),
			this, SLOT(cantidadAmarillas(int)));
	connect(nrosas, SIGNAL(valueChanged(int)),
			this, SLOT(cantidadRosas(int)));
	
	connect(this, SIGNAL(restaurarRojas(int)),
			nrojas, SLOT(setValue(int)));
	connect(this, SIGNAL(restaurarVerdes(int)),
			nverdes, SLOT(setValue(int)));
	connect(this, SIGNAL(restaurarAzules(int)),
			nazules, SLOT(setValue(int)));
	connect(this, SIGNAL(restaurarRosas(int)),
			nrosas, SLOT(setValue(int)));
	connect(this, SIGNAL(restaurarAmarillas(int)),
			namarillas, SLOT(setValue(int)));
}

int Preferencias::getDisposicion(){ return disposicion; }
int Preferencias::getEstilo(){ return estilo; }
int Preferencias::getNumColores(){ return num_colores; }
