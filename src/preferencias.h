#ifndef PREFERENCIAS_H_
#define PREFERENCIAS_H_

#include "ui_preferencias.h"

class Preferencias : public QDialog, private Ui_DialogNuevo {
	Q_OBJECT
public:
	Preferencias(QWidget *parent=0);
	int getDisposicion();
	int getEstilo();
	int getNumColores();
	
	
	
private slots:
	void actualizarDisposicion(bool);
	void actualizarEstilo(bool);
	void actualizarNumColores(int);
	void cantidadRojas(int);
	void cantidadAmarillas(int);
	void cantidadAzules(int);
	void cantidadRosas(int);
	void cantidadVerdes(int);

signals:
	void restaurarRojas(int);
	void restaurarAzules(int);
	void restaurarAmarillas(int);
	void restaurarRosas(int);
	void restaurarVerdes(int);

private:
	enum Estilo { CONTINUO, CLASICO } estilo;
	enum Disposicion { ALEATORIO, MANUAL } disposicion;
	int num_colores;
	
	// Cantidad de bolas para el modo manual
	int rojas, verdes, amarillas, azules, rosas;
	
	void establecerConexiones();
};

#endif
