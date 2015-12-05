#ifndef VENTANA_ERRORES_H
#define VENTANA_ERRORES_H

#include <QWidget>
#include <QList>
#include "errores.h"

namespace Ui {
class ventana_errores;
}

class ventana_errores : public QWidget
{
    Q_OBJECT

public:
    explicit ventana_errores(QWidget *parent = 0);
    ~ventana_errores();
    void setTabla();
private:
    Ui::ventana_errores *ui;
    QStringList titulos;
    int fila;
};

#endif // VENTANA_ERRORES_H
