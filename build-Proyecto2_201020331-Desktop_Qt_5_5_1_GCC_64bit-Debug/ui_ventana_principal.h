/********************************************************************************
** Form generated from reading UI file 'ventana_principal.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_PRINCIPAL_H
#define UI_VENTANA_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ventana_principal
{
public:
    QAction *actionAbrir;
    QAction *actionNuevo;
    QAction *actionGuardar;
    QAction *actionGuardar_Como;
    QAction *actionSalir;
    QAction *actionCompilar;
    QAction *actionEjecutar;
    QAction *actionErrores;
    QAction *actionTabla_de_S_mbolos;
    QAction *actionAyuda;
    QAction *actionManual_Tecnico;
    QAction *actionAyuda_2;
    QWidget *centralWidget;
    QGroupBox *gB1;
    QPlainTextEdit *pTEentrada;
    QGroupBox *gB2;
    QPlainTextEdit *pTEconsola;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuEjecutar;
    QMenu *menuAyuda;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Ventana_principal)
    {
        if (Ventana_principal->objectName().isEmpty())
            Ventana_principal->setObjectName(QStringLiteral("Ventana_principal"));
        Ventana_principal->resize(939, 552);
        actionAbrir = new QAction(Ventana_principal);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        actionNuevo = new QAction(Ventana_principal);
        actionNuevo->setObjectName(QStringLiteral("actionNuevo"));
        actionGuardar = new QAction(Ventana_principal);
        actionGuardar->setObjectName(QStringLiteral("actionGuardar"));
        actionGuardar_Como = new QAction(Ventana_principal);
        actionGuardar_Como->setObjectName(QStringLiteral("actionGuardar_Como"));
        actionSalir = new QAction(Ventana_principal);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionCompilar = new QAction(Ventana_principal);
        actionCompilar->setObjectName(QStringLiteral("actionCompilar"));
        actionEjecutar = new QAction(Ventana_principal);
        actionEjecutar->setObjectName(QStringLiteral("actionEjecutar"));
        actionErrores = new QAction(Ventana_principal);
        actionErrores->setObjectName(QStringLiteral("actionErrores"));
        actionTabla_de_S_mbolos = new QAction(Ventana_principal);
        actionTabla_de_S_mbolos->setObjectName(QStringLiteral("actionTabla_de_S_mbolos"));
        actionAyuda = new QAction(Ventana_principal);
        actionAyuda->setObjectName(QStringLiteral("actionAyuda"));
        actionManual_Tecnico = new QAction(Ventana_principal);
        actionManual_Tecnico->setObjectName(QStringLiteral("actionManual_Tecnico"));
        actionAyuda_2 = new QAction(Ventana_principal);
        actionAyuda_2->setObjectName(QStringLiteral("actionAyuda_2"));
        centralWidget = new QWidget(Ventana_principal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gB1 = new QGroupBox(centralWidget);
        gB1->setObjectName(QStringLiteral("gB1"));
        gB1->setGeometry(QRect(10, 0, 921, 371));
        pTEentrada = new QPlainTextEdit(gB1);
        pTEentrada->setObjectName(QStringLiteral("pTEentrada"));
        pTEentrada->setGeometry(QRect(0, 20, 921, 361));
        gB2 = new QGroupBox(centralWidget);
        gB2->setObjectName(QStringLiteral("gB2"));
        gB2->setGeometry(QRect(10, 380, 921, 131));
        pTEconsola = new QPlainTextEdit(gB2);
        pTEconsola->setObjectName(QStringLiteral("pTEconsola"));
        pTEconsola->setGeometry(QRect(0, 20, 921, 111));
        pTEconsola->setReadOnly(true);
        Ventana_principal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Ventana_principal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 939, 20));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuEjecutar = new QMenu(menuBar);
        menuEjecutar->setObjectName(QStringLiteral("menuEjecutar"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        Ventana_principal->setMenuBar(menuBar);
        statusBar = new QStatusBar(Ventana_principal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Ventana_principal->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuEjecutar->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionNuevo);
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionGuardar_Como);
        menuArchivo->addAction(actionSalir);
        menuEjecutar->addAction(actionCompilar);
        menuEjecutar->addAction(actionEjecutar);
        menuEjecutar->addAction(actionErrores);
        menuEjecutar->addAction(actionTabla_de_S_mbolos);
        menuAyuda->addAction(actionAyuda);
        menuAyuda->addAction(actionManual_Tecnico);
        menuAyuda->addAction(actionAyuda_2);

        retranslateUi(Ventana_principal);

        QMetaObject::connectSlotsByName(Ventana_principal);
    } // setupUi

    void retranslateUi(QMainWindow *Ventana_principal)
    {
        Ventana_principal->setWindowTitle(QApplication::translate("Ventana_principal", "Proyecto2", 0));
        actionAbrir->setText(QApplication::translate("Ventana_principal", "Abrir", 0));
        actionNuevo->setText(QApplication::translate("Ventana_principal", "Nuevo", 0));
        actionGuardar->setText(QApplication::translate("Ventana_principal", "Guardar", 0));
        actionGuardar_Como->setText(QApplication::translate("Ventana_principal", "Guardar Como", 0));
        actionSalir->setText(QApplication::translate("Ventana_principal", "Salir", 0));
        actionCompilar->setText(QApplication::translate("Ventana_principal", "Compilar", 0));
        actionEjecutar->setText(QApplication::translate("Ventana_principal", "Exportar", 0));
        actionErrores->setText(QApplication::translate("Ventana_principal", "Errores", 0));
        actionTabla_de_S_mbolos->setText(QApplication::translate("Ventana_principal", "Tabla de S\303\255mbolos", 0));
        actionAyuda->setText(QApplication::translate("Ventana_principal", "Manual de Usuario", 0));
        actionManual_Tecnico->setText(QApplication::translate("Ventana_principal", "Manual T\303\251cnico", 0));
        actionAyuda_2->setText(QApplication::translate("Ventana_principal", "Temas de Ayuda", 0));
        gB1->setTitle(QApplication::translate("Ventana_principal", "\303\201rea de Trabajo", 0));
        gB2->setTitle(QApplication::translate("Ventana_principal", "Consola", 0));
        menuArchivo->setTitle(QApplication::translate("Ventana_principal", "Archivo", 0));
        menuEjecutar->setTitle(QApplication::translate("Ventana_principal", "Ejecutar", 0));
        menuAyuda->setTitle(QApplication::translate("Ventana_principal", "Ayuda", 0));
    } // retranslateUi

};

namespace Ui {
    class Ventana_principal: public Ui_Ventana_principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_PRINCIPAL_H
