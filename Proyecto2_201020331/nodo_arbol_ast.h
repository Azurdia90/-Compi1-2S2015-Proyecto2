#ifndef NODO_ARBOL_AST
#define NODO_ARBOL_AST

#include <QString>


struct Nodo{

    int id;

    QString valor;

    struct Nodo *sub_izq;
    struct Nodo *sub_der;
    struct Nodo *lista_acciones[256];
};

#endif // NODO_ARBOL_AST

