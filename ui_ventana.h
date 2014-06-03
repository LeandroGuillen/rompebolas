/********************************************************************************
** Form generated from reading UI file 'ventana.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_H
#define UI_VENTANA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>
#include "lpanel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo;
    QAction *actionSalir;
    QAction *action_C_mo_se_juega;
    QAction *actionPreferencias;
    QWidget *centralwidget;
    LPanel *widget;
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QLabel *puntos_label;
    QLabel *puntos;
    QLabel *puntosJugadaActual;
    QMenuBar *menubar;
    QMenu *menuJuego;
    QMenu *menuAyuda;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(404, 453);
        MainWindow->setMinimumSize(QSize(404, 453));
        MainWindow->setMaximumSize(QSize(404, 453));
        const QIcon icon = QIcon(QString::fromUtf8(":/imagenes/icono.png"));
        MainWindow->setWindowIcon(icon);
        actionNuevo = new QAction(MainWindow);
        actionNuevo->setObjectName(QString::fromUtf8("actionNuevo"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/imagenes/nuevopj.png"));
        actionNuevo->setIcon(icon1);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/imagenes/apagar.png"));
        actionSalir->setIcon(icon2);
        action_C_mo_se_juega = new QAction(MainWindow);
        action_C_mo_se_juega->setObjectName(QString::fromUtf8("action_C_mo_se_juega"));
        actionPreferencias = new QAction(MainWindow);
        actionPreferencias->setObjectName(QString::fromUtf8("actionPreferencias"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/imagenes/preferencias.png"));
        actionPreferencias->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new LPanel(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 50, 351, 351));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 161, 20));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        puntos_label = new QLabel(layoutWidget);
        puntos_label->setObjectName(QString::fromUtf8("puntos_label"));

        hboxLayout->addWidget(puntos_label);

        puntos = new QLabel(layoutWidget);
        puntos->setObjectName(QString::fromUtf8("puntos"));
        puntos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hboxLayout->addWidget(puntos);

        puntosJugadaActual = new QLabel(centralwidget);
        puntosJugadaActual->setObjectName(QString::fromUtf8("puntosJugadaActual"));
        puntosJugadaActual->setGeometry(QRect(300, 400, 54, 18));
        puntosJugadaActual->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 404, 26));
        menuJuego = new QMenu(menubar);
        menuJuego->setObjectName(QString::fromUtf8("menuJuego"));
        menuAyuda = new QMenu(menubar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuJuego->menuAction());
        menubar->addAction(menuAyuda->menuAction());
        menuJuego->addAction(actionNuevo);
        menuJuego->addAction(actionPreferencias);
        menuJuego->addSeparator();
        menuJuego->addAction(actionSalir);
        menuAyuda->addAction(action_C_mo_se_juega);

        retranslateUi(MainWindow);
        QObject::connect(actionSalir, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Rompe Bolas", 0, QApplication::UnicodeUTF8));
        actionNuevo->setText(QApplication::translate("MainWindow", "&Nueva partida", 0, QApplication::UnicodeUTF8));
        actionNuevo->setIconText(QApplication::translate("MainWindow", "Nueva Partida", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNuevo->setToolTip(QApplication::translate("MainWindow", "Empieza una nueva partida", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNuevo->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("MainWindow", "&Salir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSalir->setToolTip(QApplication::translate("MainWindow", "Sale del programa", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSalir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_C_mo_se_juega->setText(QApplication::translate("MainWindow", "\302\277&C\303\263mo se juega?", 0, QApplication::UnicodeUTF8));
        actionPreferencias->setText(QApplication::translate("MainWindow", "&Preferencias...", 0, QApplication::UnicodeUTF8));
        actionPreferencias->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        puntos_label->setText(QApplication::translate("MainWindow", "Puntuaci\303\263n", 0, QApplication::UnicodeUTF8));
        puntos->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        puntosJugadaActual->setText(QString());
        menuJuego->setTitle(QApplication::translate("MainWindow", "&Juego", 0, QApplication::UnicodeUTF8));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "&Ayuda", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_H
