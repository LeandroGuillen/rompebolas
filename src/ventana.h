#ifndef VENTANA_H_
#define VENTANA_H_

#include "ui_ventana.h"
#include "preferencias.h"

class Ventana : public QMainWindow, private Ui_MainWindow {
	Q_OBJECT
public:
	Ventana(QWidget *parent=0);
	
private:
	Preferencias *preferencias;
	
private slots:
	void muestraPreferencias();
};

#endif
