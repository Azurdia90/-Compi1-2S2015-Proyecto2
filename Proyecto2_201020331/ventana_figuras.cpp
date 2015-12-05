#include "ventana_figuras.h"
#include "ui_ventana_figuras.h"

extern QHash<QString,Figura>	lista_figuras;

Ventana_figuras::Ventana_figuras(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana_figuras)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(15);
    titulos<<"Tipo"<<"Nombre"<<"Posicion x"<<"Posicion y"<<"Base"<<"Altura"<<"Radio x"<<"Radio y"<<"Radio"<<"Textura"<<"Tipo de Linea"<<"Color"<<"Texto"<<"Tamaño Letra"<<"Opaco";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
    this->setTabla();
}

Ventana_figuras::~Ventana_figuras()
{
    delete ui;
}

void Ventana_figuras::setTabla()
{
    QHash<QString,Figura>:: iterator iter;

    for(iter = lista_figuras.begin(); iter != lista_figuras.end(); iter++){
         ui->tableWidget->insertRow(ui->tableWidget->rowCount());
         fila = ui->tableWidget->rowCount() - 1;
         Figura aux;
         aux = iter.value();
         ui->tableWidget->setItem(fila,0,new QTableWidgetItem(aux.getTipo()));
         ui->tableWidget->setItem(fila,1,new QTableWidgetItem(aux.getNombre()));
         ui->tableWidget->setItem(fila,2,new QTableWidgetItem(QString::number(aux.getPosx())));
         ui->tableWidget->setItem(fila,3,new QTableWidgetItem(QString::number(aux.getPosy())));
         ui->tableWidget->setItem(fila,4,new QTableWidgetItem(QString::number(aux.getBase())));
         ui->tableWidget->setItem(fila,5,new QTableWidgetItem(QString::number(aux.getAltura())));
         ui->tableWidget->setItem(fila,6,new QTableWidgetItem(QString::number(aux.getRadiox())));
         ui->tableWidget->setItem(fila,7,new QTableWidgetItem(QString::number(aux.getRadioy())));
         ui->tableWidget->setItem(fila,8,new QTableWidgetItem(QString::number(aux.getRadio())));
         ui->tableWidget->setItem(fila,9,new QTableWidgetItem(aux.getTextura().getNombre()));
         ui->tableWidget->setItem(fila,10,new QTableWidgetItem(aux.getLinea().getNombre()));
         ui->tableWidget->setItem(fila,11,new QTableWidgetItem(aux.getColor()));
         ui->tableWidget->setItem(fila,12,new QTableWidgetItem(aux.getTexto()));
         ui->tableWidget->setItem(fila,13,new QTableWidgetItem(QString::number(aux.getTamano())));
         ui->tableWidget->setItem(fila,14,new QTableWidgetItem(QString::number(aux.getOpaco())));
         //qDebug() << iter.key() << " : " << iter.value();
     }
}
