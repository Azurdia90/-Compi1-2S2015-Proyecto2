#ifndef VENTANA_FIGURAS_H
#define VENTANA_FIGURAS_H

#include <QWidget>

#include <QHash>

#include "figura.h"

namespace Ui {
class Ventana_figuras;
}

class Ventana_figuras : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana_figuras(QWidget *parent = 0);
    ~Ventana_figuras();
    void setTabla();
private:
    Ui::Ventana_figuras *ui;
    QStringList titulos;
    int fila;
};

#endif // VENTANA_FIGURAS_H
