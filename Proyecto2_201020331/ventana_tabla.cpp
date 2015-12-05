#include "ventana_tabla.h"
#include "ui_ventana_tabla.h"

extern QHash<QString,Variable> lista_variables;

Ventana_tabla::Ventana_tabla(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana_tabla)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    titulos<<"Tipo"<<"Nombre"<<"Valor"<<"Color"<<"Linea"<<"Grosor";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
    this->setTabla();
}

Ventana_tabla::~Ventana_tabla()
{
    delete ui;
}

void Ventana_tabla::setTabla()
{
   QHash<QString,Variable>:: iterator iter;

   for(iter = lista_variables.begin(); iter != lista_variables.end(); iter++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        fila = ui->tableWidget->rowCount() - 1;
        Variable aux;
        aux = iter.value();
        ui->tableWidget->setItem(fila,0,new QTableWidgetItem(aux.getTipo()));
        ui->tableWidget->setItem(fila,1,new QTableWidgetItem(aux.getNombre()));
        ui->tableWidget->setItem(fila,2,new QTableWidgetItem(aux.getValor()));
        ui->tableWidget->setItem(fila,3,new QTableWidgetItem(aux.getColor()));
        ui->tableWidget->setItem(fila,4,new QTableWidgetItem(aux.getLinea()));
        ui->tableWidget->setItem(fila,5,new QTableWidgetItem(aux.getGrosor()));
        //qDebug() << iter.key() << " : " << iter.value();
    }

}
