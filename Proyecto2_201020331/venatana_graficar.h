#ifndef VENATANA_GRAFICAR_H
#define VENATANA_GRAFICAR_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "QGraphicsItem" //DIBUJA RECTANGULOS
#include "QGraphicsLineItem" //DIBUJA LINEAS

#include "figura.h"

namespace Ui {
class Venatana_graficar;
}

class Venatana_graficar : public QDialog
{
    Q_OBJECT

public:
    explicit Venatana_graficar(QWidget *parent = 0);
    ~Venatana_graficar();

private:
    Ui::Venatana_graficar *ui;
    QGraphicsScene * escena;
    void pintar();
    void pintarTriangulo(Figura f);
    void pintarOvalo(Figura f);
    void pintarCirculo(Figura f);
    void pintarRectangulo(Figura f);
    void pintarPunto(Figura f);
    void pintarLinea(Figura f);




};

#endif // VENATANA_GRAFICAR_H
