#include "ventana_errores.h"
#include "ui_ventana_errores.h"

extern QList<Errores> lista_errores;

ventana_errores::ventana_errores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ventana_errores)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    titulos<<"Tipo"<<"Identificador"<<"Descripcion"<<"Posicion x"<<"Posicion y";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
    this->setTabla();
}

ventana_errores::~ventana_errores()
{
    delete ui;
}

void ventana_errores::setTabla()
{
    for(int cont = 0; cont<lista_errores.count();cont++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        fila = ui->tableWidget->rowCount() - 1;
        Errores aux;
        aux = lista_errores.value(cont);
        ui->tableWidget->setItem(fila,0,new QTableWidgetItem(aux.getTipo()));
        ui->tableWidget->setItem(fila,1,new QTableWidgetItem(aux.getIdentificador()));
        ui->tableWidget->setItem(fila,2,new QTableWidgetItem(aux.getDescripcion()));
        ui->tableWidget->setItem(fila,3,new QTableWidgetItem(QString::number(aux.getPosx())));
        ui->tableWidget->setItem(fila,4,new QTableWidgetItem(QString::number(aux.getPosy())));
    }
}
