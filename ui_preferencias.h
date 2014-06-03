/********************************************************************************
** Form generated from reading UI file 'preferencias.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCIAS_H
#define UI_PREFERENCIAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogNuevo
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QRadioButton *radio_Aleatorio;
    QRadioButton *radio_Manual;
    QWidget *widget_4;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *nrojas;
    QLabel *label_3;
    QSpinBox *nazules;
    QLabel *label_4;
    QSpinBox *namarillas;
    QLabel *label_5;
    QSpinBox *nrosas;
    QLabel *label_6;
    QSpinBox *nverdes;
    QWidget *layoutWidget1;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QSpinBox *spinBox_Colores;
    QGroupBox *groupBox_2;
    QRadioButton *radio_Continuo;
    QRadioButton *radio_Clasico;

    void setupUi(QDialog *DialogNuevo)
    {
        if (DialogNuevo->objectName().isEmpty())
            DialogNuevo->setObjectName(QString::fromUtf8("DialogNuevo"));
        DialogNuevo->setWindowModality(Qt::ApplicationModal);
        DialogNuevo->resize(384, 345);
        const QIcon icon = QIcon(QString::fromUtf8(":/imagenes/preferencias.png"));
        DialogNuevo->setWindowIcon(icon);
        DialogNuevo->setModal(true);
        buttonBox = new QDialogButtonBox(DialogNuevo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(200, 300, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(DialogNuevo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 171, 271));
        radio_Aleatorio = new QRadioButton(groupBox);
        radio_Aleatorio->setObjectName(QString::fromUtf8("radio_Aleatorio"));
        radio_Aleatorio->setGeometry(QRect(30, 20, 90, 24));
        radio_Aleatorio->setChecked(true);
        radio_Manual = new QRadioButton(groupBox);
        radio_Manual->setObjectName(QString::fromUtf8("radio_Manual"));
        radio_Manual->setEnabled(false);
        radio_Manual->setGeometry(QRect(30, 50, 90, 24));
        widget_4 = new QWidget(groupBox);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setEnabled(false);
        widget_4->setGeometry(QRect(10, 80, 151, 191));
        layoutWidget = new QWidget(widget_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 110, 166));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        nrojas = new QSpinBox(layoutWidget);
        nrojas->setObjectName(QString::fromUtf8("nrojas"));
        nrojas->setMaximum(121);
        nrojas->setValue(25);

        gridLayout->addWidget(nrojas, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        nazules = new QSpinBox(layoutWidget);
        nazules->setObjectName(QString::fromUtf8("nazules"));
        nazules->setMaximum(121);
        nazules->setValue(24);

        gridLayout->addWidget(nazules, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        namarillas = new QSpinBox(layoutWidget);
        namarillas->setObjectName(QString::fromUtf8("namarillas"));
        namarillas->setMaximum(121);
        namarillas->setValue(24);

        gridLayout->addWidget(namarillas, 2, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        nrosas = new QSpinBox(layoutWidget);
        nrosas->setObjectName(QString::fromUtf8("nrosas"));
        nrosas->setMaximum(121);
        nrosas->setValue(24);

        gridLayout->addWidget(nrosas, 3, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        nverdes = new QSpinBox(layoutWidget);
        nverdes->setObjectName(QString::fromUtf8("nverdes"));
        nverdes->setMaximum(121);
        nverdes->setValue(24);

        gridLayout->addWidget(nverdes, 4, 1, 1, 1);

        layoutWidget1 = new QWidget(DialogNuevo);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(200, 40, 163, 30));
        hboxLayout = new QHBoxLayout(layoutWidget1);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout->addWidget(label);

        spinBox_Colores = new QSpinBox(layoutWidget1);
        spinBox_Colores->setObjectName(QString::fromUtf8("spinBox_Colores"));
        spinBox_Colores->setEnabled(false);
        spinBox_Colores->setMinimum(3);
        spinBox_Colores->setMaximum(5);
        spinBox_Colores->setValue(5);

        hboxLayout->addWidget(spinBox_Colores);

        groupBox_2 = new QGroupBox(DialogNuevo);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(200, 90, 151, 101));
        radio_Continuo = new QRadioButton(groupBox_2);
        radio_Continuo->setObjectName(QString::fromUtf8("radio_Continuo"));
        radio_Continuo->setGeometry(QRect(20, 30, 90, 24));
        radio_Continuo->setChecked(true);
        radio_Clasico = new QRadioButton(groupBox_2);
        radio_Clasico->setObjectName(QString::fromUtf8("radio_Clasico"));
        radio_Clasico->setEnabled(false);
        radio_Clasico->setGeometry(QRect(20, 60, 90, 24));
#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(nrojas);
        label_3->setBuddy(nazules);
        label_4->setBuddy(namarillas);
        label_5->setBuddy(nrosas);
        label_6->setBuddy(nverdes);
        label->setBuddy(spinBox_Colores);
#endif // QT_NO_SHORTCUT

        retranslateUi(DialogNuevo);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogNuevo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogNuevo, SLOT(reject()));
        QObject::connect(radio_Manual, SIGNAL(toggled(bool)), widget_4, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(DialogNuevo);
    } // setupUi

    void retranslateUi(QDialog *DialogNuevo)
    {
        DialogNuevo->setWindowTitle(QApplication::translate("DialogNuevo", "Preferencias", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DialogNuevo", "Disposici\303\263n", 0, QApplication::UnicodeUTF8));
        radio_Aleatorio->setText(QApplication::translate("DialogNuevo", "Aleatorio", 0, QApplication::UnicodeUTF8));
        radio_Manual->setText(QApplication::translate("DialogNuevo", "Manual", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogNuevo", "Rojos", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogNuevo", "Azules", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogNuevo", "Amarillos", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DialogNuevo", "Rosas", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DialogNuevo", "Verdes", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogNuevo", "N\303\272mero de colores", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DialogNuevo", "Estilo", 0, QApplication::UnicodeUTF8));
        radio_Continuo->setText(QApplication::translate("DialogNuevo", "Continuo", 0, QApplication::UnicodeUTF8));
        radio_Clasico->setText(QApplication::translate("DialogNuevo", "Cl\303\241sico", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogNuevo: public Ui_DialogNuevo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCIAS_H
