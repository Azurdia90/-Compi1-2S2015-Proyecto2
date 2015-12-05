#ifndef FIGURA_H
#define FIGURA_H

#include <QString>
#include <QList>

#include "coordenadas.h"
#include "variable.h"

class Figura
{
public:
    Figura();
    QString getNombre();
    QString getTipo();
    float getBase();
    float getAltura();
    float getOpaco();
    float getRadiox();
    float getRadioy();
    float getRadio();
    float getPosx();
    float getPosy();
    float getTamano();
    Variable getTextura();
    Variable getLinea();
    QString getColor();
    QString getLetra();
    QString getTexto();
    QList<Coordenadas> getLista_coordenadas();
    void setNombre(QString n);
    void setTipo(QString t);
    void setBase(float b);
    void setAltura(float a);
    void setOpaco(float o);
    void setRadiox(float x);
    void setRadioy(float y);
    void setRadio(float r);
    void setPosx(float x);
    void setPosy(float y);
    void setTamano(float t);
    void setTextura(Variable t);
    void setLinea(Variable l);
    void setColor(QString c);
    void setLetra(QString l);
    void setTexto(QString t);
    void setLista_coordenadas(QList<Coordenadas> l);
private:
    QString nombre;
    QString tipo;
    float base;
    float altura;
    float opaco;
    float radiox;
    float radioy;
    float radio;
    float posx;
    float posy;
    float tamano;
    Variable textura;
    Variable linea;
    QString color;
    QString letra;
    QString texto;
    QList<Coordenadas> lista_coordenadas;
};

#endif // FIGURA_H
