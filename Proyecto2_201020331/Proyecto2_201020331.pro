#-------------------------------------------------
#
# Project created by QtCreator 2015-11-03T15:37:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto2_201020331
TEMPLATE = app


SOURCES += main.cpp\
        ventana_principal.cpp \
    arbol_ast.cpp \
    parser.cpp \
    scanner.cpp \
    errores.cpp \
    variable.cpp \
    figura.cpp \
    ventana_errores.cpp \
    ventana_tabla.cpp \
    ventana_figuras.cpp \
    coordenadas.cpp \
    venatana_graficar.cpp \
    acerca_de.cpp

HEADERS  += ventana_principal.h \
    nodo_arbol_ast.h \
    arbol_ast.h \
    parser.h \
    scanner.h \
    errores.h \
    variable.h \
    figura.h \
    ventana_errores.h \
    ventana_tabla.h \
    ventana_figuras.h \
    coordenadas.h \
    venatana_graficar.h \
    acerca_de.h

FORMS    += ventana_principal.ui \
    ventana_errores.ui \
    ventana_tabla.ui \
    ventana_figuras.ui \
    ventana_graficar.ui \
    venatana_graficar.ui \
    acerca_de.ui
