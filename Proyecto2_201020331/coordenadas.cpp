#include "coordenadas.h"

Coordenadas::Coordenadas(QString x, QString y)
{
    this->posx = x;
    this->posy = x;
}

Coordenadas::Coordenadas()
{

}

Coordenadas::~Coordenadas()
{
    this->posx = -1;
    this->posy = -1;
}

void Coordenadas::setPosx(QString x)
{
    this->posx = x;
}

void Coordenadas::setPosy(QString y)
{
    this->posy = y;
}

QString Coordenadas::getPosx()
{
    return posx;
}

QString Coordenadas::getPosy()
{
    return posy;
}

