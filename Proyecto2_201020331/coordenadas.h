#ifndef COORDENADAS_H
#define COORDENADAS_H

#include <QString>

class Coordenadas
{
public:
    Coordenadas(QString x, QString y);
    Coordenadas();
    ~Coordenadas();
    void setPosx(QString x);
    void setPosy(QString y);
    QString getPosx();
    QString getPosy();
private:
    QString posx;
    QString posy;
};

#endif // COORDENADAS_H
