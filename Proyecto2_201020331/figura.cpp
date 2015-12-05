#include "figura.h"

Figura::Figura()
{
    this->base = -1;
    this->altura = -1;
    this->color = "N/A";
    this->letra = "N/A";
    this->linea.setNombre("N/A");
    this->opaco = -1;
    this->posx = -1;
    this->posy = -1;
    this->radio = -1;
    this->radiox = -1;
    this->radioy = -1;
    this->tamano = -1;
    this->texto = "N/A";
    this->textura.setNombre("N/A");
}

QString Figura::getNombre()
{
    return nombre;
}

QString Figura::getTipo()
{
    return tipo;
}

float Figura::getBase()
{
    return base;
}

float Figura::getAltura()
{
    return altura;
}

float Figura::getOpaco()
{
    return opaco;
}

float Figura::getRadiox()
{
    return radiox;
}

float Figura::getRadioy()
{
    return radioy;
}

float Figura::getRadio()
{
    return radio;
}

float Figura::getPosx()
{
    return posx;
}

float Figura::getPosy()
{
    return posy;
}

float Figura::getTamano()
{
    return tamano;
}

Variable Figura::getTextura()
{
    return textura;
}

Variable Figura::getLinea()
{
     return linea;
}


QString Figura::getColor()
{
    return color;
}

QString Figura::getLetra()
{
    return letra;
}

QString Figura::getTexto()
{
    return texto;
}

QList<Coordenadas> Figura::getLista_coordenadas()
{
    return lista_coordenadas;
}

void Figura::setNombre(QString n)
{
    this->nombre = n;
}

void Figura::setTipo(QString t)
{
    this->tipo = t;
}

void Figura::setBase(float b)
{
    this->base = b;
}

void Figura::setAltura(float a)
{
    this->altura = a;
}

void Figura::setOpaco(float o)
{
    this->opaco = o;
}

void Figura::setRadiox(float x)
{
    this->radiox = x;
}

void Figura::setRadioy(float y)
{
    this->radioy = y;
}

void Figura::setRadio(float r)
{
    this->radio = r;
}

void Figura::setPosx(float x)
{
    this->posx = x;
}

void Figura::setPosy(float y)
{
    this->posy = y;
}

void Figura::setTamano(float t)
{
    this->tamano = t;
}

void Figura::setTextura(Variable t)
{
    this->textura = t;
}

void Figura::setLinea(Variable l)
{
    this->linea = l;
}

void Figura::setColor(QString c)
{
    this->color = c;
}

void Figura::setLetra(QString l)
{
    this->letra = l;
}

void Figura::setTexto(QString t)
{
    this->texto = t;
}

void Figura::setLista_coordenadas(QList<Coordenadas> l)
{
    this->lista_coordenadas = l;
}

