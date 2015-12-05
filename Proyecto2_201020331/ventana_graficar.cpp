#include "ventana_graficar.h"
#include "ui_ventana_graficar.h"

extern QList<QString> lista_imprimir;
extern QHash<QString,Figura> lista_figuras;

Ventana_graficar::Ventana_graficar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana_graficar)
{
    ui->setupUi();
    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,0,500,500);
    ui->graphicsView->setScene(escena);
    this->pintar();
}

Ventana_graficar::~Ventana_graficar()
{
    delete ui;
}


void Ventana_graficar::pintar()
{
    for(int cont = 0; cont<lista_imprimir.count();cont++){
        if(lista_figuras.contains(lista_imprimir.value(cont)) == true){
            Figura f = lista_figuras.value(lista_imprimir.value(cont));
            if(f.getTipo().compare("Triangulo")){

            }else if(f.getTipo().compare("Ovalo")){

            }else if(f.getTipo().compare("Poligono")){

            }else if(f.getTipo().compare("Circulo")){

            }else if(f.getTipo().compare("Rectangulo")){

            }else if(f.getTipo().compare("Nube")){

            }else if(f.getTipo().compare("punto")){

            }else if(f.getTipo().compare("Texto")){

            }else if(f.getTipo().compare("Imagen")){

            }else if(f.getTipo().compare("Flecha")){

            }else if(f.getTipo().compare("Linea")){
                pintarLinea(f);
            }
        }
    }

}

void Ventana_graficar::pintarLinea(Figura f)
{
    QGraphicsLineItem * linea = new QGraphicsLineItem(f.getPosx(),f.getPosy(),f.getPosx()+f.getAltura(),f.getPosy()+f.getAltura());
    escena->addItem(linea);
}
