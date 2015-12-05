#include "errores.h"

Errores::Errores(QString t, QString i, QString d, int x, int y)
{
    this->tipo = t;
    this->identificador = i;
    this->descripcion = d;
    this->posx = x;
    this->posy = y;
}

Errores::Errores()
{
    this->tipo = "";
    this->identificador = "";
    this->descripcion = "";
    this->posx = 0;
    this->posy = 0;
}

Errores::~Errores()
{
    this->tipo.clear();
    this->identificador.clear();
    this->descripcion.clear();
    this->posx = 0;
    this->posy = 0;
}

QString Errores::getTipo()
{
    return this->tipo;
}

QString Errores::getIdentificador()
{
    return this->identificador;
}

QString Errores::getDescripcion()
{
    return this->descripcion;
}

int Errores::getPosx()
{
    return this->posx;
}

int Errores::getPosy()
{
    return this->posy;
}

void Errores::setTipo(QString t)
{
    this->tipo = t;
}

void Errores::setIdentificador(QString i)
{
    this->identificador = i;
}

void Errores::setDescripcion(QString d)
{
    this->descripcion = d;
}

void Errores::setPosx(int x)
{
    this->posx = x;
}

void Errores::setPosy(int y)
{
    this->posy = y;
}

