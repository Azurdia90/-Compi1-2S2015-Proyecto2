#ifndef VENTANA_PRINCIPAL_H
#define VENTANA_PRINCIPAL_H

#include <stdio.h>
#include <stdlib.h>

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QFile>
#include <QHash>
#include <QList>

#include "variable.h"
#include "figura.h"
#include "parser.h"
#include "ventana_errores.h"
#include "ventana_tabla.h"
#include "ventana_figuras.h"
#include "venatana_graficar.h"
#include "acerca_de.h"

extern int yyrestart( FILE* archivo);
extern void setSalida(QPlainTextEdit* sal);
extern int yyparse();

namespace Ui {
class Ventana_principal;
}

class Ventana_principal : public QMainWindow
{
    Q_OBJECT
    //ui->pTEentrada->appendPlainText("hola");
    //ui->pTEentrada->setPlainText("hola");

public:
    explicit Ventana_principal(QWidget *parent = 0);
    ~Ventana_principal();
private slots:
    void on_actionAbrir_triggered();
    void on_actionNuevo_triggered();
    void on_actionGuardar_Como_triggered();
    void on_actionGuardar_triggered();
    void on_actionSalir_triggered();
    void abrir();
    void guardar();
    void guardar_como();
    void nuevo();
    void salir();
    void compilar();
    void on_actionCompilar_triggered();
    void on_actionErrores_triggered();
    void on_actionTabla_de_S_mbolos_triggered();
    void abrir_errores();
    void abrir_simbolos();
    void on_actionAyuda_2_triggered();

    void on_actionAyuda_triggered();

private:
    Ui::Ventana_principal *ui;
    QFile archivo;
    QString path_archivo;
};

#endif // VENTANA_PRINCIPAL_H
