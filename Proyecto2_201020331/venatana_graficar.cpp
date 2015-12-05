#include "venatana_graficar.h"
#include "ui_venatana_graficar.h"

extern QList<QString> lista_imprimir;
extern QHash<QString,Figura> lista_figuras;

Venatana_graficar::Venatana_graficar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Venatana_graficar)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,0,500,500);
    ui->graphicsView->setScene(escena);
    this->pintar();
}

Venatana_graficar::~Venatana_graficar()
{
    delete ui;
}

void Venatana_graficar::pintar()
{
    for(int cont = 0; cont<lista_imprimir.count();cont++){
        if(lista_figuras.contains(lista_imprimir.value(cont)) == true){
            Figura f = lista_figuras.value(lista_imprimir.value(cont));
            if(f.getTipo().compare("Triangulo")==0){
                pintarTriangulo(f);
            }else if(f.getTipo().compare("Ovalo")==0){
                pintarOvalo(f);
            }else if(f.getTipo().compare("Poligono")==0){

            }else if(f.getTipo().compare("Circulo")==0){
                pintarCirculo(f);
            }else if(f.getTipo().compare("Rectangulo")==0){
                pintarRectangulo(f);
            }else if(f.getTipo().compare("Nube")==0){

            }else if(f.getTipo().compare("Punto")==0){
                pintarPunto(f);
            }else if(f.getTipo().compare("Texto")==0){

            }else if(f.getTipo().compare("Imagen")==0){

            }else if(f.getTipo().compare("Flecha")==0){

            }else if(f.getTipo().compare("Linea")==0){
                pintarLinea(f);
            }
        }
    }

}

void Venatana_graficar::pintarTriangulo(Figura f)
{
    QPen linea1(QPen(Qt::DashLine));
    QPen linea2(QPen(Qt::DotLine));
    QPen linea3(QPen(Qt::DashDotLine));
    int x,y,b,h;
    x=f.getPosx();
    y=f.getPosy();
    b=f.getBase();
    h=f.getAltura();
    QPolygon polygon;
    polygon.setPoints(3, x+(b/2),y,x,y+h,x+b,y+h);
    QGraphicsPolygonItem *poligono;
    if(f.getLinea().getLinea().compare("M-lineaguion")==0){
        poligono=escena->addPolygon(polygon,linea1);
    }else if(f.getLinea().getLinea().compare("M-lineapunto")==0){
        poligono=escena->addPolygon(polygon,linea2);
    }else if(f.getLinea().getLinea().compare("M-lineaguionpunto")==0){
        poligono=escena->addPolygon(polygon,linea3);
    }else{
        poligono = escena->addPolygon(polygon);
    }
}

void Venatana_graficar::pintarOvalo(Figura f)
{
    QGraphicsEllipseItem * ovalo = new QGraphicsEllipseItem(f.getPosx(),f.getPosy(),f.getRadiox(),f.getRadioy());
    QPen linea1(QPen(Qt::DashLine));
    QPen linea2(QPen(Qt::DotLine));
    QPen linea3(QPen(Qt::DashDotLine));
    if(f.getLinea().getLinea().compare("M-lineaguion")==0){
        linea1.setWidth(f.getLinea().getGrosor().toInt());
        ovalo->setPen(linea1);
    }else if(f.getLinea().getLinea().compare("M-lineapunto")==0){
        linea2.setWidth(f.getLinea().getGrosor().toInt());
        ovalo->setPen(linea2);
    }else if(f.getLinea().getLinea().compare("M-lineaguionpunto")==0){
        linea3.setWidth(f.getLinea().getGrosor().toInt());
        ovalo->setPen(linea3);
    }
    if(f.getLinea().getColor().compare("M-azul")==0){
        ovalo->setBrush(QBrush(QColor(Qt::blue)));
    }else if(f.getLinea().getColor().compare("M-rojo")==0){
        ovalo->setBrush(QBrush(QColor(Qt::red)));
    }else if(f.getLinea().getColor().compare("M-verde")==0){
        ovalo->setBrush(QBrush(QColor(Qt::green)));
    }else if(f.getLinea().getColor().compare("M-amarillo")==0){
        ovalo->setBrush(QBrush(QColor(Qt::yellow)));
    }else if(f.getLinea().getColor().compare("M-negro")==0){
        ovalo->setBrush(QBrush(QColor(Qt::black)));
    }else if(f.getLinea().getColor().compare("M-gris")==0){
        ovalo->setBrush(QBrush(QColor(Qt::lightGray)));
    }else if(f.getLinea().getColor().compare("M-cafe")==0){
        ovalo->setBrush(QBrush(QColor(Qt::gray)));
    }else if(f.getLinea().getColor().compare("M-blanco")==0){
        ovalo->setBrush(QBrush(QColor(Qt::white)));
    }
    if(f.getOpaco() != -1){
        ovalo->setOpacity(f.getOpaco());
    }
    escena->addItem(ovalo);
}

void Venatana_graficar::pintarCirculo(Figura f)
{

    QGraphicsEllipseItem * circulo = new QGraphicsEllipseItem(f.getPosx(),f.getPosy(),f.getRadio(),f.getRadio());
    QPen linea1(QPen(Qt::DashLine));
    QPen linea2(QPen(Qt::DotLine));
    QPen linea3(QPen(Qt::DashDotLine));
    if(f.getLinea().getLinea().compare("M-lineaguion")==0){
        linea1.setWidth(f.getLinea().getGrosor().toInt());
        circulo->setPen(linea1);
    }else if(f.getLinea().getLinea().compare("M-lineapunto")==0){
        linea2.setWidth(f.getLinea().getGrosor().toInt());
        circulo->setPen(linea2);
    }else if(f.getLinea().getLinea().compare("M-lineaguionpunto")==0){
        linea3.setWidth(f.getLinea().getGrosor().toInt());
        circulo->setPen(linea3);
    }
    if(f.getLinea().getColor().compare("M-azul")==0){
        circulo->setBrush(QBrush(QColor(Qt::blue)));
    }else if(f.getLinea().getColor().compare("M-rojo")==0){
        circulo->setBrush(QBrush(QColor(Qt::red)));
    }else if(f.getLinea().getColor().compare("M-verde")==0){
        circulo->setBrush(QBrush(QColor(Qt::green)));
    }else if(f.getLinea().getColor().compare("M-amarillo")==0){
        circulo->setBrush(QBrush(QColor(Qt::yellow)));
    }else if(f.getLinea().getColor().compare("M-negro")==0){
        circulo->setBrush(QBrush(QColor(Qt::black)));
    }else if(f.getLinea().getColor().compare("M-gris")==0){
        circulo->setBrush(QBrush(QColor(Qt::lightGray)));
    }else if(f.getLinea().getColor().compare("M-cafe")==0){
        circulo->setBrush(QBrush(QColor(Qt::gray)));
    }else if(f.getLinea().getColor().compare("M-blanco")==0){
        circulo->setBrush(QBrush(QColor(Qt::white)));
    }
    if(f.getOpaco() != -1){
        circulo->setOpacity(f.getOpaco());
    }
    escena->addItem(circulo);

}

void Venatana_graficar::pintarRectangulo(Figura f)
{
    QGraphicsRectItem * cuadrado = new QGraphicsRectItem(f.getPosx(),f.getPosy(),f.getBase(),f.getAltura());
    QPen linea1(QPen(Qt::DashLine));
    QPen linea2(QPen(Qt::DotLine));
    QPen linea3(QPen(Qt::DashDotLine));
    if(f.getLinea().getLinea().compare("M-lineaguion")==0){
        linea1.setWidth(f.getLinea().getGrosor().toInt());
        cuadrado->setPen(linea1);
    }else if(f.getLinea().getLinea().compare("M-lineapunto")==0){
        linea2.setWidth(f.getLinea().getGrosor().toInt());
        cuadrado->setPen(linea2);
    }else if(f.getLinea().getLinea().compare("M-lineaguionpunto")==0){
        linea3.setWidth(f.getLinea().getGrosor().toInt());
        cuadrado->setPen(linea3);
    }
    if(f.getLinea().getColor().compare("M-azul")==0){
        cuadrado->setBrush(QBrush(QColor(Qt::blue)));
    }else if(f.getLinea().getColor().compare("M-rojo")==0){
        cuadrado->setBrush(QBrush(QColor(Qt::red)));
    }else if(f.getLinea().getColor().compare("M-verde")==0){
        cuadrado->setBrush(QBrush(QColor(Qt::green)));
    }else if(f.getLinea().getColor().compare("M-amarillo")==0){
        cuadrado->setBrush(QBrush(QColor(Qt::yellow)));
    }else if(f.getLinea().getColor().compare("M-negro")==0){
        cuadrado->setBrush(QBrush(QColor(Qt::black)));
    }else if(f.getLinea().getColor().compare("M-gris")==0){
        cuadrado->setBrush(QBrush(QColor(Qt::lightGray)));
    }else if(f.getLinea().getColor().compare("M-cafe")==0){
        cuadrado->setBrush(QBrush(QColor(Qt::gray)));
    }else if(f.getLinea().getColor().compare("M-blanco")==0){
        cuadrado->setBrush(QBrush(QColor(Qt::white)));
    }
    if(f.getOpaco() != -1){
        cuadrado->setOpacity(f.getOpaco());
    }
    escena->addItem(cuadrado);
}

void Venatana_graficar::pintarPunto(Figura f)
{
    QGraphicsLineItem * punto = new QGraphicsLineItem(f.getPosx(),f.getPosy(),f.getPosx(),f.getPosy());
    QPen linea1(QPen(Qt::DashLine));
    QPen linea2(QPen(Qt::DotLine));
    QPen linea3(QPen(Qt::DashDotLine));
    if(f.getLinea().getLinea().compare("M-lineaguion")==0){
        linea1.setWidth(f.getLinea().getGrosor().toInt());
        if(f.getLinea().getColor().compare("M-azul")==0){
            linea1.setColor(Qt::blue);
        }else if(f.getLinea().getColor().compare("M-rojo")==0){
            linea1.setColor(Qt::red);
        }else if(f.getLinea().getColor().compare("M-verde")==0){
            linea1.setColor(Qt::green);
        }else if(f.getLinea().getColor().compare("M-amarillo")==0){
            linea1.setColor(Qt::yellow);
        }else if(f.getLinea().getColor().compare("M-negro")==0){
            linea1.setColor(Qt::black);
        }else if(f.getLinea().getColor().compare("M-gris")==0){
            linea1.setColor(Qt::lightGray);
        }else if(f.getLinea().getColor().compare("M-cafe")==0){
            linea1.setColor(Qt::gray);
        }else if(f.getLinea().getColor().compare("M-blanco")==0){
            linea1.setColor(Qt::white);
        }
        punto->setPen(linea1);
    }else if(f.getLinea().getLinea().compare("M-lineapunto")==0){
        linea2.setWidth(f.getLinea().getGrosor().toInt());
        if(f.getLinea().getColor().compare("M-azul")==0){
            linea2.setColor(Qt::blue);
        }else if(f.getLinea().getColor().compare("M-rojo")==0){
            linea2.setColor(Qt::red);
        }else if(f.getLinea().getColor().compare("M-verde")==0){
            linea2.setColor(Qt::green);
        }else if(f.getLinea().getColor().compare("M-amarillo")==0){
            linea2.setColor(Qt::yellow);
        }else if(f.getLinea().getColor().compare("M-negro")==0){
            linea2.setColor(Qt::black);
        }else if(f.getLinea().getColor().compare("M-gris")==0){
            linea2.setColor(Qt::lightGray);
        }else if(f.getLinea().getColor().compare("M-cafe")==0){
            linea2.setColor(Qt::gray);
        }else if(f.getLinea().getColor().compare("M-blanco")==0){
            linea2.setColor(Qt::white);
        }
        punto->setPen(linea2);
    }else if(f.getLinea().getLinea().compare("M-lineaguionpunto")==0){
        linea3.setWidth(f.getLinea().getGrosor().toInt());
        if(f.getLinea().getColor().compare("M-azul")==0){
            linea3.setColor(Qt::blue);
        }else if(f.getLinea().getColor().compare("M-rojo")==0){
            linea3.setColor(Qt::red);
        }else if(f.getLinea().getColor().compare("M-verde")==0){
            linea3.setColor(Qt::green);
        }else if(f.getLinea().getColor().compare("M-amarillo")==0){
            linea3.setColor(Qt::yellow);
        }else if(f.getLinea().getColor().compare("M-negro")==0){
            linea3.setColor(Qt::black);
        }else if(f.getLinea().getColor().compare("M-gris")==0){
            linea3.setColor(Qt::lightGray);
        }else if(f.getLinea().getColor().compare("M-cafe")==0){
            linea3.setColor(Qt::gray);
        }else if(f.getLinea().getColor().compare("M-blanco")==0){
            linea3.setColor(Qt::white);
        }
        punto->setPen(linea3);
    }

    if(f.getOpaco() != -1){
        punto->setOpacity(f.getOpaco());
    }
    escena->addItem(punto);
}

void Venatana_graficar::pintarLinea(Figura f)
{
    QGraphicsLineItem * linea = new QGraphicsLineItem(f.getPosx(),f.getAltura(),f.getBase(),f.getPosy());
    QPen linea1(QPen(Qt::DashLine));
    QPen linea2(QPen(Qt::DotLine));
    QPen linea3(QPen(Qt::DashDotLine));
    if(f.getLinea().getLinea().compare("M-lineaguion")==0){
        linea1.setWidth(f.getLinea().getGrosor().toInt());
        if(f.getLinea().getColor().compare("M-azul")==0){
            linea1.setColor(Qt::blue);
        }else if(f.getLinea().getColor().compare("M-rojo")==0){
            linea1.setColor(Qt::red);
        }else if(f.getLinea().getColor().compare("M-verde")==0){
            linea1.setColor(Qt::green);
        }else if(f.getLinea().getColor().compare("M-amarillo")==0){
            linea1.setColor(Qt::yellow);
        }else if(f.getLinea().getColor().compare("M-negro")==0){
            linea1.setColor(Qt::black);
        }else if(f.getLinea().getColor().compare("M-gris")==0){
            linea1.setColor(Qt::lightGray);
        }else if(f.getLinea().getColor().compare("M-cafe")==0){
            linea1.setColor(Qt::gray);
        }else if(f.getLinea().getColor().compare("M-blanco")==0){
            linea1.setColor(Qt::white);
        }
        linea->setPen(linea1);
    }else if(f.getLinea().getLinea().compare("M-lineapunto")==0){
        linea2.setWidth(f.getLinea().getGrosor().toInt());
        if(f.getLinea().getColor().compare("M-azul")==0){
            linea2.setColor(Qt::blue);
        }else if(f.getLinea().getColor().compare("M-rojo")==0){
            linea2.setColor(Qt::red);
        }else if(f.getLinea().getColor().compare("M-verde")==0){
            linea2.setColor(Qt::green);
        }else if(f.getLinea().getColor().compare("M-amarillo")==0){
            linea2.setColor(Qt::yellow);
        }else if(f.getLinea().getColor().compare("M-negro")==0){
            linea2.setColor(Qt::black);
        }else if(f.getLinea().getColor().compare("M-gris")==0){
            linea2.setColor(Qt::lightGray);
        }else if(f.getLinea().getColor().compare("M-cafe")==0){
            linea2.setColor(Qt::gray);
        }else if(f.getLinea().getColor().compare("M-blanco")==0){
            linea2.setColor(Qt::white);
        }
        linea->setPen(linea2);
    }else if(f.getLinea().getLinea().compare("M-lineaguionpunto")==0){
        linea3.setWidth(f.getLinea().getGrosor().toInt());
        if(f.getLinea().getColor().compare("M-azul")==0){
            linea3.setColor(Qt::blue);
        }else if(f.getLinea().getColor().compare("M-rojo")==0){
            linea3.setColor(Qt::red);
        }else if(f.getLinea().getColor().compare("M-verde")==0){
            linea3.setColor(Qt::green);
        }else if(f.getLinea().getColor().compare("M-amarillo")==0){
            linea3.setColor(Qt::yellow);
        }else if(f.getLinea().getColor().compare("M-negro")==0){
            linea3.setColor(Qt::black);
        }else if(f.getLinea().getColor().compare("M-gris")==0){
            linea3.setColor(Qt::lightGray);
        }else if(f.getLinea().getColor().compare("M-cafe")==0){
            linea3.setColor(Qt::gray);
        }else if(f.getLinea().getColor().compare("M-blanco")==0){
            linea3.setColor(Qt::white);
        }
        linea->setPen(linea3);
    }

    if(f.getOpaco() != -1){
        linea->setOpacity(f.getOpaco());
    }
    escena->addItem(linea);
}

