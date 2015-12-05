#include "ventana_principal.h"
#include "ui_ventana_principal.h"

QList<Errores> lista_errores;
QList<QString> lista_imprimir;
QHash<QString,Variable> lista_variables;
QHash<QString,Figura>	lista_figuras;



Ventana_principal::Ventana_principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_principal)
{
    ui->setupUi(this);
}

//METODO DESTRUCTOR DE LA CLASE
Ventana_principal::~Ventana_principal()
{
    delete ui;
}

/**************************************************MENU ARCHIVOS*************************************************************************/

//METODOS DE LOS SLOTS DEL MENU ARCHIVOS
void Ventana_principal::on_actionAbrir_triggered()
{
    this->abrir();
}

void Ventana_principal::on_actionGuardar_triggered()
{
    this->guardar();
}

void Ventana_principal::on_actionGuardar_Como_triggered()
{
       this->guardar_como();

}

void Ventana_principal::on_actionNuevo_triggered()
{
    this->nuevo();
}

void Ventana_principal::on_actionSalir_triggered()
{
    this->salir();
}

//METODOS DEL MENU ARCHIVOS
void Ventana_principal::abrir(){
    this->path_archivo = QFileDialog::getOpenFileName(this,"Seleccione el archivo","/home","Archivos(*.txt)");
    if(path_archivo != NULL){
        QFile archivo_aux(path_archivo);
        if(archivo_aux.open(QIODevice::ReadOnly|QIODevice::Text)){
            ui->pTEentrada->QPlainTextEdit::setPlainText(QString::fromUtf8(archivo_aux.readAll()));
        }
    }
}

void Ventana_principal::guardar(){
    if(!this->path_archivo.isEmpty()){
        QFile archivo(this->path_archivo);
        if (archivo.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            archivo.write(ui->pTEentrada->toPlainText().toUtf8());
        }
    }
}

void Ventana_principal::guardar_como(){
    this->path_archivo = QFileDialog::getSaveFileName(this, ("Guardar archivo"), "/home", ("txt(*.txt);"));
    if(!this->path_archivo.isEmpty()){
        QFile archivo(this->path_archivo);
        if (archivo.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            archivo.write(ui->pTEentrada->toPlainText().toUtf8());
        }
    }
}

void Ventana_principal::nuevo(){
    ui->pTEentrada->clear();
    this->path_archivo.clear();
}

void Ventana_principal::salir(){
    this->close();
}

/***************************************************MENU EJECUCTAR*************************************************************************************/
//SLOTS DEL MENU EJECUTAR
void Ventana_principal::on_actionCompilar_triggered()
{
    compilar();
}

void Ventana_principal::on_actionErrores_triggered()
{
    abrir_errores();
}

void Ventana_principal::on_actionTabla_de_S_mbolos_triggered()
{
    abrir_simbolos();
}

//METODOS DEL MENU EJECUTAR
void Ventana_principal::compilar(){
    ui->pTEconsola->clear();
    lista_errores.clear();
    lista_variables.clear();
    lista_figuras.clear();
    QFile file("/home/azurdia/Proyecto2/temp.txt");
    if ( file.open( file.WriteOnly ) ) {
        QTextStream stream1( &file );
        stream1 << ui->pTEentrada->toPlainText().toUtf8();
    }
    FILE* input = fopen("/home/azurdia/Proyecto2/temp.txt" , "r" );
    setSalida(ui->pTEconsola);
    yyrestart(input);
    yyparse();
    Venatana_graficar *sg = new Venatana_graficar;
    if(!lista_imprimir.isEmpty()){
        sg->show();
    }
}

void Ventana_principal::abrir_errores()
{
    ventana_errores *er = new ventana_errores;
    er->show();
}

void Ventana_principal::abrir_simbolos()
{
    Ventana_tabla *st = new Ventana_tabla;
    st->show();
    Ventana_figuras *sf = new Ventana_figuras;
    sf->show();
}

/***************************************************MENU AYUDA************************************************************************/

void Ventana_principal::on_actionAyuda_2_triggered()
{
    Acerca_de *e = new Acerca_de();
    e->show();
}

void Ventana_principal::on_actionAyuda_triggered()
{
    system("run-mailcap /home/azurdia/Proyecto2/MANUAL_USUARIO.pdf");
}
