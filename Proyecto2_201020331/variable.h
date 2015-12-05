#ifndef VARIABLE_H
#define VARIABLE_H

#include <QString>
#include <QList>
#include "coordenadas.h"

class Variable
{
public:
    Variable(QString n, QString t, QString v, QString c,QString l, QString g);
    Variable();
    ~Variable();
    void setNombre(QString n);
    void setTipo(QString t);
    void setValor(QString v);
    void setColor(QString c);
    void setLinea(QString l);
    void setGrosor(QString g);
    void setArreglo(QList<Coordenadas> a);
    QString getNombre();
    QString getTipo();
    QString getValor();
    QString getColor();
    QString getLinea();
    QString getGrosor();
    QList<Coordenadas> getArreglo();
private:
    QString nombre;
    QString tipo;
    QString valor;
    QString color;
    QString linea;
    QString grosor;
    QList<Coordenadas> lista_coordenas;
};

#endif // VARIABLE_H
