#include "variable.h"

Variable::Variable(QString n, QString t, QString v, QString c, QString l, QString g)
{
    this->nombre = n;
    this->tipo = t;
    this->valor = v;
    this->color = c;
    this->linea = l;
    this->grosor = g;
}

Variable::Variable()
{
    this->nombre = "";
    this->tipo = "";
    this->valor = "";
    this->color = "";
    this->linea = "";
    this->grosor = "";
}

Variable::~Variable()
{
    this->nombre.clear();
    this->tipo.clear();
    this->valor.clear();
    this->color.clear();
    this->linea.clear();
    this->grosor.clear();
}

void Variable::setNombre(QString n)
{
    this->nombre = n;
}

void Variable::setTipo(QString t)
{
    this->tipo = t;
}

void Variable::setValor(QString v)
{
    this->valor = v;
}

void Variable::setColor(QString c)
{
    this->color = c;
}

void Variable::setLinea(QString l)
{
    this->linea = l;
}

void Variable::setGrosor(QString g)
{
    this->grosor = g;
}

void Variable::setArreglo(QList<Coordenadas> a){
    this->lista_coordenas = a;
}

QString Variable::getNombre()
{
    return nombre;
}

QString Variable::getTipo()
{
    return tipo;
}

QString Variable::getValor()
{
    return valor;
}

QString Variable::getColor()
{
    return color;
}

QString Variable::getLinea()
{
    return linea;
}

QString Variable::getGrosor()
{
    return grosor;
}

QList<Coordenadas> Variable::getArreglo()
{
    return lista_coordenas;
}


