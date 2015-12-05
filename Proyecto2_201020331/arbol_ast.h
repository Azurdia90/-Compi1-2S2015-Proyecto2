#ifndef ARBOL_AST_H
#define ARBOL_AST_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QDebug>
#include <QMap>
#include <QList>
#include <QHash>

#include "nodo_arbol_ast.h"
#include "errores.h"
#include "variable.h"
#include "figura.h"

class arbol_ast
{


public:
    arbol_ast(struct Nodo **raiz);
    ~arbol_ast();
    struct Nodo *get_raiz();
    //metodos para graficar arbol ast
    void graficar();
    void graficar(struct Nodo **raiz);
    //metodos para recorrer y realizar las acciones
    void recorrer();
    void recorrer(struct Nodo **raiz);
    //metodo para la modificacion de variables
    void modificacion_variables(struct Nodo **raiz);
    //metodo para el manejo de las figuras
    void manejo_figuras(struct Nodo **raiz);
    //metodo para el manejo de las figuras a imprimir
    void graficar_figuras(struct Nodo **raiz);
    void rotar_figuras(struct Nodo **raiz);
    //metodo para borrar las figuras de la tabla
    void borrar_figuras(struct Nodo **raiz);
    //metodos para obtener los valores de las variables
    void manejo_variables(struct Nodo **raiz);
    QString valor_cadena(struct Nodo **raiz, Variable var);
    QString operacion_cadena(struct Nodo **raiz, Variable var, bool s);
    QString valor_entero(struct Nodo **raiz, Variable var);
    QString operacion_entero(struct Nodo **raiz, Variable var, bool s);
    QString valor_flotante(struct Nodo **raiz, Variable var);
    QString operacion_flotante(struct Nodo **raiz, Variable var, bool s);
    QList<Coordenadas> valor_arreglo(struct Nodo **raiz,Variable var);
    QList<Coordenadas> operacion_arreglo(struct Nodo **raiz, Variable var, bool s);
    /****************************************************/
    QString valor_cadena(struct Nodo **raiz, Figura f);
    QString operacion_cadena(struct Nodo **raiz, Figura f, bool s);
    QString valor_entero(struct Nodo **raiz, Figura f);
    QString operacion_entero(struct Nodo **raiz, Figura f, bool s);
    QString valor_flotante(struct Nodo **raiz, Figura f);
    QString operacion_flotante(struct Nodo **raiz, Figura f, bool s);
    QList<Coordenadas> valor_arreglo(struct Nodo **raiz,Figura f);
    QList<Coordenadas> operacion_arreglo(struct Nodo **raiz, Figura f, bool s);
    //metodos para crear las nuevas figuras
    Figura crear_triangulo(struct Nodo **raiz,Figura f);
    Figura crear_ovalo(struct Nodo **raiz,Figura f);
    Figura crear_poligono(Nodo **raiz, Figura f);
    Figura crear_circulo(Nodo **raiz, Figura f);
    Figura crear_rectangulo(Nodo **raiz,Figura f);
    Figura crear_nube(Nodo **raiz,Figura f);
    Figura crear_punto(Nodo **raiz,Figura f);
    Figura crear_texto(Nodo **raiz,Figura f);
    Figura crear_imagen(Nodo **raiz,Figura f);
    Figura crear_flecha(Nodo **raiz,Figura f);
    Figura crear_linea(Nodo **raiz,Figura f);
private:
    struct Nodo *root;
    FILE *archivo;
};

#endif // ARBOL_AST_H
