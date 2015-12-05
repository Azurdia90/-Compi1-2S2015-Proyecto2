#ifndef ERRORES_H
#define ERRORES_H

#include <QString>

class Errores
{
public:
    Errores(QString t, QString i, QString d, int x, int y);
    Errores();
    ~Errores();
    QString getTipo();
    QString getIdentificador();
    QString getDescripcion();
    int getPosx();
    int getPosy();
    void setTipo(QString t);
    void setIdentificador(QString i);
    void setDescripcion(QString d);
    void setPosx(int x);
    void setPosy(int y);
private:
    QString tipo;
    QString identificador;
    QString descripcion;
    int posx;
    int posy;
};

#endif // ERRORES_H
