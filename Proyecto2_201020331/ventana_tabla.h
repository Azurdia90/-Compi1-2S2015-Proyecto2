#ifndef VENTANA_TABLA_H
#define VENTANA_TABLA_H

#include <QWidget>
#include <QHash>
#include "variable.h"

namespace Ui {
class Ventana_tabla;
}

class Ventana_tabla : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana_tabla(QWidget *parent = 0);
    ~Ventana_tabla();
    void setTabla();
private:
    Ui::Ventana_tabla *ui;
    QStringList titulos;
    int fila;
};

#endif // VENTANA_TABLA_H
