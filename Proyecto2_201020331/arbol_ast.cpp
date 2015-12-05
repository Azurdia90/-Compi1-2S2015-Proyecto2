#include "arbol_ast.h"

extern QList<Errores> lista_errores;
extern QList<QString> lista_imprimir;
extern QHash<QString,Variable> lista_variables;
extern QHash<QString,Figura>	lista_figuras;

arbol_ast::arbol_ast(Nodo **raiz)
{
    this->root = *raiz;
}

arbol_ast::~arbol_ast()
{
    this->root = NULL;
}


/*****************************************METODOS PARA GRAFICAR ARBOL AST******************************************************/
void arbol_ast :: graficar(){
    if(root != NULL){
        archivo = fopen("/home/azurdia/Proyecto2/arbol_ast.dot","w");
        if(archivo != NULL){
            fprintf(archivo,"digraph ast {\n");
            graficar(&root);//enviar para poder graficar el arbol
            fprintf(archivo,"}");
            fclose(archivo);
            system("dot -Tjpg /home/azurdia/Proyecto2/arbol_ast.dot -o /home/azurdia/Proyecto2/arbol_ast.jpg");
        }//fin de comprobacion si el archivo fue abierto
    }//fin de comprobacion si esta vacia la raiz
}

void arbol_ast :: graficar(Nodo **raiz){
    if((*raiz)){
        graficar(&(*raiz)->sub_izq);
        graficar(&(*raiz)->sub_der);
        fprintf(archivo,"%i[shape=ellipse,label=\"%s\"];\n",(*raiz)->id,(*raiz)->valor.toStdString().c_str());
        if((*raiz)->lista_acciones[0] != NULL){
            int cont = 0;
            for(cont = 0; cont<256; cont++){
                if((*raiz)->lista_acciones[cont] != NULL){
                    fprintf(archivo," %i->%i;\n",(*raiz)->id,(*raiz)->lista_acciones[cont]->id);
                    graficar(&(*raiz)->lista_acciones[cont]);
                }else{
                    break;
                }
            }
        }
        if((*raiz)->sub_izq != NULL){//comprobacion si tiene hijos que enlazar
            fprintf(archivo,"%i->%i;\n",(*raiz)->id,(*raiz)->sub_izq->id);
        }
        if((*raiz)->sub_der != NULL){//comprobacion si tiene hijios que enlazar
            fprintf(archivo,"%i->%i;\n",(*raiz)->id,(*raiz)->sub_der->id);
        }
    }//fin de comprobacion si el nodo esta vacio
}

/**************************************METODOS PARA RECORRER ARBOL AST********************************************/
void arbol_ast::recorrer()
{
    if(root != NULL){
        recorrer(&root);
    }
}

void arbol_ast::recorrer(Nodo **raiz)
{
    if((*raiz)){
        recorrer(&(*raiz)->sub_izq);
        if((*raiz)->valor.compare("VARIABLE")==0){
            manejo_variables(&(*raiz));
        }
        if((*raiz)->valor.compare("MODIFICACION DE VARIABLE")==0){
            modificacion_variables(&(*raiz));
        }
        if((*raiz)->valor.compare("FIGURA")==0){
            manejo_figuras(&(*raiz));
        }
        if((*raiz)->valor.compare("GRAFICAR")==0){
            graficar_figuras(&(*raiz));
        }
        if((*raiz)->valor.compare("BORRAR")==0){
            borrar_figuras(&(*raiz));
        }
        if((*raiz)->valor.compare("ROTAR")==0){
            rotar_figuras(&(*raiz));
        }
        if((*raiz)->lista_acciones[0] != NULL){
            for(int cont = 0; cont<256;cont++){
                if((*raiz)->lista_acciones[cont] != NULL){
                    recorrer(&((*raiz)->lista_acciones[cont]));
                }else{
                    break;
                }
            }
        }
        recorrer(&(*raiz)->sub_der);
    }
}

/*****************************************METODOS PARA EL MANEJO DE LAS VARIABLES**********************************************************/
void arbol_ast:: manejo_variables(Nodo **raiz){
   struct Nodo *aux = NULL;
    Variable var;
    int grosor = 0;
    var.setNombre((*raiz)->sub_izq->sub_izq->valor);
    var.setTipo((*raiz)->sub_der->sub_izq->sub_izq->valor);
    if(var.getTipo().compare("M-entero") ==0){
        var.setTipo("entero");
        var.setValor(valor_entero(&(*raiz)->sub_der->sub_der,var));
        var.setColor("N/A");
        var.setGrosor("N/A");
        var.setLinea("N/A");
    }else if(var.getTipo().compare("M-cadena")==0){
        var.setTipo("cadena");
        var.setValor(valor_cadena(&(*raiz)->sub_der->sub_der,var));
        var.setColor("N/A");
        var.setGrosor("N/A");
        var.setLinea("N/A");
    }else if(var.getTipo().compare("M-flotante")==0){
        var.setTipo("flotante");
        var.setValor(valor_flotante(&(*raiz)->sub_der->sub_der,var));
        var.setColor("N/A");
        var.setGrosor("N/A");
        var.setLinea("N/A");
    }else if(var.getTipo().compare("M-arreglo") == 0){
        var.setTipo("arreglo");
        var.setValor("N/A");
        var.setColor("N/A");
        var.setGrosor("N/A");
        var.setLinea("N/A");
    }else if(var.getTipo().compare("M-textura")==0){
        var.setTipo("textura");
        if((*raiz)->sub_der->sub_der->valor.compare("COLOR") == 0){
            var.setValor("N/A");
            var.setColor((*raiz)->sub_der->sub_der->sub_izq->valor);
        }else{
            var.setValor(valor_cadena(&(*raiz)->sub_der->sub_der,var));
            var.setColor("N/A");
        }
        var.setGrosor("N/A");
        var.setLinea("N/A");
    }else if(var.getTipo().compare("M-linea")==0){
        var.setTipo("linea");
        var.setValor("N/A");
        var.setColor((*raiz)->sub_der->lista_acciones[0]->sub_izq->valor);
        var.setLinea((*raiz)->sub_der->lista_acciones[1]->sub_izq->valor);
        aux = (*raiz)->sub_der->lista_acciones[2];
        var.setGrosor(valor_entero(&aux,var));
        grosor = var.getGrosor().toInt();
        if(grosor <1){
            var.setGrosor("1");
            Errores er("Semantico",var.getTipo(),"Valor fuera de limite",0,0);
            lista_errores.append(er);
        }else if(grosor>50){
            var.setGrosor("50");
            Errores er("Semantico",var.getTipo(),"Valor fuera de limite",0,0);
            lista_errores.append(er);
        }
    }
    lista_variables.insert(var.getNombre(),var);
}

QString arbol_ast::valor_cadena(Nodo **raiz,Variable var)
{
    Variable aux;
    bool s =true;
    QString retorno  = "";
    if((*raiz)->valor.compare("CADENA")==0){
        return ((*raiz)->sub_izq->valor);
    }else if((*raiz)->valor.compare("NUMERO")==0){
        Errores er ("Semantico",var.getNombre(),"No es del tipo entero o flotante ",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("IDENTIFICADOR")==0){
        if(lista_variables.contains((*raiz)->sub_izq->valor) == true){
            aux = lista_variables.value((*raiz)->sub_izq->valor);
            if(aux.getTipo().compare("cadena")==0){
                retorno = aux.getValor();
                return retorno;
            }else{
                Errores er("Semantico",(*raiz)->sub_izq->valor,"Tipo de variable no compatible",0,0);
                lista_errores.append(er);
            }
        }else{
            Errores er("Semantico",(*raiz)->sub_izq->valor,"No existe la variable",0,0);
            lista_errores.append(er);
        }
    }else if((*raiz)->valor.compare("+")==0){
        return operacion_cadena(&(*raiz),var,&s);
    }else if((*raiz)->valor.compare("-")== 0||(*raiz)->valor.compare("*")==0||(*raiz)->valor.compare("/") == 0||(*raiz)->valor.compare("%")==0){
        Errores er("Semantico",var.getNombre(),"No es del tipo entero o flotante",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("ARREGLO")==0){
        Errores er("Semantico",var.getNombre(),"No es del tipo arreglo",0,0);
        lista_errores.append(er);
    }
    return retorno;
}

QString arbol_ast::operacion_cadena(Nodo **raiz,Variable var, bool s)
{
    QString x = "";
    QString y = "";
    QString result = "";
    QString operador = "";
    if((*raiz) && s == true){
        operador = (*raiz)->valor;
        if(operador.compare("NUMERO")==0){
            Errores er("Sintactico",var.getValor(),"Se esta intentado operar una variable no compatible",0,0);
            lista_errores.append(er);
            s = false;
        }else if(operador.compare("CADENA")==0){
            result = (*raiz)->sub_izq->valor;
            return result;
        }else if(operador.compare("VARIABLE")==0){
            Variable aux;
            if(lista_variables.contains((*raiz)->sub_izq->valor)==true){
                aux = lista_variables.value((*raiz)->sub_izq->valor);
                if(aux.getTipo().compare("cadena")==0){
                    result = aux.getValor();
                    return result;
                }else{
                    Errores er("Sintactico",var.getValor(),"Se esta intentado operar una variable no compatible",0,0);
                    lista_errores.append(er);
                    s = false;
                }
            }else{
                Errores er("Sintactico",var.getValor(),"Se esta intentado operar una variable no existente",0,0);
                lista_errores.append(er);
                s = false;
            }
        }else if(operador.compare("ARREGLO")==0){
            Errores er("Sintactico",var.getValor(),"Se esta intentado operar una variable no compatible",0,0);
            lista_errores.append(er);
            s = false;
        }
        x = operacion_cadena(&(*raiz)->sub_izq,var,&s);
        y = operacion_cadena(&(*raiz)->sub_der,var,&s);
        if(s == true){
            if(operador.compare("+")==0){
                result = x + y;
                return result;
            }else if(operador.compare("-")==0){
                Errores er("Sintactico",var.getValor(),"Se esta intentado hacer un division entre cero",0,0);
                lista_errores.append(er);
                s = false;
            }else if(operador.compare("*")==0){
                Errores er("Sintactico",var.getValor(),"Se esta intentado hacer un division entre cero",0,0);
                lista_errores.append(er);
                s = false;
            }else if(operador.compare("%") == 0){
                Errores er("Sintactico",var.getValor(),"Se esta intentado hacer un division entre cero",0,0);
                lista_errores.append(er);
                s = false;
            }else if(operador.compare("/")== 0){
                Errores er("Sintactico",var.getValor(),"Se esta intentado hacer un division entre cero",0,0);
                lista_errores.append(er);
                s = false;
            }
        }
    }
    return result;
}

QString arbol_ast::valor_entero(Nodo **raiz, Variable var)
{
    QString retorno ="";
    Variable aux;
    bool s =true;
    if((*raiz)->valor.compare("CADENA")==0){
        Errores er("Semantico",var.getNombre(),"No es del tipo cadena",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("NUMERO")==0){
        return (*raiz)->sub_izq->valor;
    }else if((*raiz)->valor.compare("IDENTIFICADOR")==0){
        if(lista_variables.contains((*raiz)->sub_izq->valor) == true){
            aux = lista_variables.value((*raiz)->sub_izq->valor);
            retorno = aux.getValor();
            return retorno;
        }else{
            Errores er("Semantico",(*raiz)->sub_izq->valor,"No existe la variable",0,0);
            lista_errores.append(er);
        }
    }else if((*raiz)->valor.compare("+")==0||(*raiz)->valor.compare("-")== 0||(*raiz)->valor.compare("*")==0||(*raiz)->valor.compare("/") == 0||(*raiz)->valor.compare("%")==0){
        return operacion_entero(&(*raiz),var,&s);
    }else if((*raiz)->valor.compare("ARREGLO")==0){
        Errores er("Semantico",var.getNombre(),"No es del tipo arreglo",0,0);
        lista_errores.append(er);
    }
    return retorno;
}

QString arbol_ast::operacion_entero(Nodo **raiz,Variable var,bool s)
{
    int x = 0;
    int y = 0;
    int result = 0;
    QString operador = "";
    if((*raiz) && s == true){
        operador = (*raiz)->valor;
        if(operador.compare("NUMERO")==0){
            result = (*raiz)->sub_izq->valor.toInt();
            return QString::number(result);
        }else if(operador.compare("CADENA")==0){
            Errores er("Sintactico",var.getValor(),"Se esta intentado opera una variable no compatible",0,0);
            lista_errores.append(er);
            s = false;
        }else if(operador.compare("VARIABLE")==0){
            Variable aux;
            if(lista_variables.contains((*raiz)->sub_izq->valor)==true){
                aux = lista_variables.value((*raiz)->sub_izq->valor);
                if(aux.getTipo().compare("entero")==0){
                    result = aux.getValor().toInt();
                    return QString::number(result);
                }else{
                    Errores er("Sintactico",var.getValor(),"Se esta intentado operar una variable no compatible",0,0);
                    lista_errores.append(er);
                    s = false;
                }
            }else{
                Errores er("Sintactico",var.getValor(),"Se esta intentado operar una variable no existente",0,0);
                lista_errores.append(er);
                s = false;
            }
        }else if(operador.compare("ARREGLO")==0){
            Errores er("Sintactico",var.getValor(),"Se esta intentado operar una variable no compatible",0,0);
            lista_errores.append(er);
            s = false;
        }
        x = operacion_entero(&(*raiz)->sub_izq,var,&s).toInt();
        y = operacion_entero(&(*raiz)->sub_der,var,&s).toInt();
        if(s == true){
            if(operador.compare("+")==0){
                result = x + y;
                return QString::number(result);
            }else if(operador.compare("-")==0){
                result = x - y;
                return QString::number(result);
            }else if(operador.compare("*")==0){
                result = x * y;
                return QString::number(result);
            }else if(operador.compare("%") == 0){
                result = x % y;
                return QString::number(result);
            }else if(operador.compare("/")== 0){
                if(y != 0){
                    result = x / y;
                    return QString::number(result);
                }else{
                    Errores er("Sintactico",var.getValor(),"Se esta intentado hacer un division entre cero",0,0);
                    lista_errores.append(er);
                    s = false;
                }
            }
        }
    }
    return QString::number(result);
}

QString arbol_ast::valor_flotante(Nodo **raiz, Variable var)
{
    QString retorno = "";
    Variable aux;
    bool s =true;
    if((*raiz)->valor.compare("CADENA")==0){
        Errores er("Semantico",var.getNombre(),"No es del tipo cadena",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("NUMERO")==0){
        return (*raiz)->sub_izq->valor;
    }else if((*raiz)->valor.compare("IDENTIFICADOR")==0){
        if(lista_variables.contains((*raiz)->sub_izq->valor) == true){
            aux = lista_variables.value((*raiz)->sub_izq->valor);
            retorno = aux.getValor();
            return retorno;
        }else{
            Errores er("Semantico",(*raiz)->sub_izq->valor,"No existe la variable",0,0);
            lista_errores.append(er);
        }
    }else if((*raiz)->valor.compare("+")==0||(*raiz)->valor.compare("-")== 0||(*raiz)->valor.compare("*")==0||(*raiz)->valor.compare("/") == 0||(*raiz)->valor.compare("%")==0){
        return operacion_flotante(&(*raiz),var,&s);
    }else if((*raiz)->valor.compare("ARREGLO")==0){
        Errores er("Semantico",var.getNombre(),"No es del tipo arreglo",0,0);
        lista_errores.append(er);
    }
    return retorno;
}

QString arbol_ast::operacion_flotante(Nodo **raiz,Variable var,bool s)
{
    float x = 0.0;
    float y = 0.0;
    float result = 0.0;
    QString operador = "";
    if((*raiz) && s == true){
        operador = (*raiz)->valor;
        if(operador.compare("NUMERO")==0){
            result = (*raiz)->sub_izq->valor.toFloat();
            return QString::number(result);
        }else if(operador.compare("CADENA")==0){
            Errores er("Sintactico",var.getValor(),"Se esta intentado opera una variable no compatible",0,0);
            lista_errores.append(er);
            s = false;
        }else if(operador.compare("VARIABLE")==0){
            Variable aux;
            if(lista_variables.contains((*raiz)->sub_izq->valor)==true){
                aux = lista_variables.value((*raiz)->sub_izq->valor);
                if(aux.getTipo().compare("flotante")==0){
                    result = aux.getValor().toFloat();
                    return QString::number(result);
                }else{
                    Errores er("Sintactico",var.getValor(),"Se esta intentado operar una variable no compatible",0,0);
                    lista_errores.append(er);
                    s = false;
                }
            }else{
                Errores er("Sintactico",var.getValor(),"Se esta intentado operar una variable no existente",0,0);
                lista_errores.append(er);
                s = false;
            }
        }else if(operador.compare("ARREGLO")==0){
            Errores er("Sintactico",var.getValor(),"Se esta intentado operar una variable no compatible",0,0);
            lista_errores.append(er);
            s = false;
        }
        x = operacion_flotante(&(*raiz)->sub_izq,var,&s).toFloat();
        y = operacion_flotante(&(*raiz)->sub_der,var,&s).toFloat();
        if(s == true){
            if(operador.compare("+")==0){
                result = x + y;
                return QString::number(result);
            }else if(operador.compare("-")==0){
                result = x - y;
                return QString::number(result);
            }else if(operador.compare("*")==0){
                result = x * y;
                return QString::number(result);
            }else if(operador.compare("/") == 0){
                if(y != 0){
                    result = x / y;
                    return QString::number(result);
                }else{
                    Errores er("Sintactico",var.getValor(),"Se esta intentado hacer un division entre cero",0,0);
                    lista_errores.append(er);
                    s = false;
                }
            }else if(operador.compare("%")== 0){
                Errores er("Sintactico",var.getValor(),"Se esta intentado obtener modulo con flotantes",0,0);
                lista_errores.append(er);
                s = false;
            }
        }
    }
    return QString::number(result);
}

QList<Coordenadas> arbol_ast::valor_arreglo(Nodo **raiz, Variable var)
{
    QList<Coordenadas> retorno;
    Variable aux;
    if((*raiz)->valor.compare("CADENA")==0){
        Errores er("Semantico",var.getNombre(),"No es del tipo cadena",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("NUMERO")==0){
        Errores er("Semantico",var.getNombre(),"No es del tipo entero o flotante",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("IDENTIFICADOR")==0){
        if(lista_variables.contains((*raiz)->sub_izq->valor) == true){
            aux = lista_variables.value((*raiz)->sub_izq->valor);
            retorno = aux.getArreglo();
            return retorno;
        }else{
            Errores er("Semantico",(*raiz)->sub_izq->valor,"No existe la variable",0,0);
            lista_errores.append(er);
        }
    }else if((*raiz)->valor.compare("+")==0||(*raiz)->valor.compare("-")== 0||(*raiz)->valor.compare("*")==0||(*raiz)->valor.compare("/") == 0||(*raiz)->valor.compare("%")==0){
        Errores er("Semantico",var.getNombre(),"No es del tipo entero o flotante",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("ARREGLO")==0){
        return retorno;
    }
    return retorno;
}

QList<Coordenadas> arbol_ast::operacion_arreglo(Nodo **raiz, Variable var, bool s)
{

}

/***************************************************/
QString arbol_ast::valor_cadena(Nodo **raiz,Figura f)
{
    Variable aux;
    bool s =true;
    QString retorno  = "";
    if((*raiz)->valor.compare("CADENA")==0){
        return ((*raiz)->sub_izq->valor);
    }else if((*raiz)->valor.compare("NUMERO")==0){
        Errores er ("Semantico",f.getNombre(),"Atributo no es del tipo entero o flotante ",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("IDENTIFICADOR")==0){
        if(lista_variables.contains((*raiz)->sub_izq->valor) == true){
            aux = lista_variables.value((*raiz)->sub_izq->valor);
            if(aux.getTipo().compare("cadena")==0){
                retorno = aux.getValor();
                return retorno;
            }else{
                Errores er("Semantico",(*raiz)->sub_izq->valor,"Tipo de variable no compatible",0,0);
                lista_errores.append(er);
            }
        }else{
            Errores er("Semantico",(*raiz)->sub_izq->valor,"No existe la variable",0,0);
            lista_errores.append(er);
        }
    }else if((*raiz)->valor.compare("+")==0){
        return operacion_cadena(&(*raiz),f,&s);
    }else if((*raiz)->valor.compare("-")== 0||(*raiz)->valor.compare("*")==0||(*raiz)->valor.compare("/") == 0||(*raiz)->valor.compare("%")==0){
        Errores er("Semantico",f.getNombre(),"Atributo no es del tipo entero o flotante",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("ARREGLO")==0){
        Errores er("Semantico",f.getNombre(),"Atributo No es del tipo arreglo",0,0);
        lista_errores.append(er);
    }
    return retorno;
}

QString arbol_ast::operacion_cadena(Nodo **raiz,Figura f, bool s)
{
    QString x = "";
    QString y = "";
    QString result = "";
    QString operador = "";
    if((*raiz) && s == true){
        operador = (*raiz)->valor;
        if(operador.compare("NUMERO")==0){
            Errores er("Sintactico",f.getNombre(),"Se esta intentado operar una variable no compatible",0,0);
            lista_errores.append(er);
            s = false;
        }else if(operador.compare("CADENA")==0){
            result = (*raiz)->sub_izq->valor;
            return result;
        }else if(operador.compare("VARIABLE")==0){
            Variable aux;
            if(lista_variables.contains((*raiz)->sub_izq->valor)==true){
                aux = lista_variables.value((*raiz)->sub_izq->valor);
                if(aux.getTipo().compare("cadena")==0){
                    result = aux.getValor();
                    return result;
                }else{
                    Errores er("Sintactico",aux.getNombre(),"Variable no existente",0,0);
                    lista_errores.append(er);
                    s = false;
                }
            }else{
                Errores er("Sintactico",f.getNombre(),"Se esta intentado operar una variable no existente",0,0);
                lista_errores.append(er);
                s = false;
            }
        }else if(operador.compare("ARREGLO")==0){
            Errores er("Sintactico",f.getNombre(),"Se esta intentado operar una variable no compatible",0,0);
            lista_errores.append(er);
            s = false;
        }
        x = operacion_cadena(&(*raiz)->sub_izq,f,&s);
        y = operacion_cadena(&(*raiz)->sub_der,f,&s);
        if(s == true){
            if(operador.compare("+")==0){
                result = x + y;
                return result;
            }else if(operador.compare("-")==0){
                Errores er("Sintactico",f.getNombre(),"Se esta intentado hacer un division entre cero",0,0);
                lista_errores.append(er);
                s = false;
            }else if(operador.compare("*")==0){
                Errores er("Sintactico",f.getNombre(),"Se esta intentado hacer un division entre cero",0,0);
                lista_errores.append(er);
                s = false;
            }else if(operador.compare("%") == 0){
                Errores er("Sintactico",f.getNombre(),"Se esta intentado hacer un division entre cero",0,0);
                lista_errores.append(er);
                s = false;
            }else if(operador.compare("/")== 0){
                Errores er("Sintactico",f.getNombre(),"Se esta intentado hacer un division entre cero",0,0);
                lista_errores.append(er);
                s = false;
            }
        }
    }
    return result;
}

QString arbol_ast::valor_flotante(Nodo **raiz, Figura f)
{
    QString retorno = "";
    Variable aux;
    bool s =true;
    if((*raiz)->valor.compare("CADENA")==0){
        Errores er("Semantico",f.getNombre(),"Atributo no es del tipo cadena",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("NUMERO")==0){
        return (*raiz)->sub_izq->valor;
    }else if((*raiz)->valor.compare("IDENTIFICADOR")==0){
        if(lista_variables.contains((*raiz)->sub_izq->valor) == true){
            aux = lista_variables.value((*raiz)->sub_izq->valor);
            retorno = aux.getValor();
            return retorno;
        }else{
            Errores er("Semantico",(*raiz)->sub_izq->valor,"No existe la variable",0,0);
            lista_errores.append(er);
        }
    }else if((*raiz)->valor.compare("+")==0||(*raiz)->valor.compare("-")== 0||(*raiz)->valor.compare("*")==0||(*raiz)->valor.compare("/") == 0||(*raiz)->valor.compare("%")==0){
        return operacion_flotante(&(*raiz),f,&s);
    }else if((*raiz)->valor.compare("ARREGLO")==0){
        Errores er("Semantico",f.getNombre(),"Atributo no es del tipo arreglo",0,0);
        lista_errores.append(er);
    }
    return retorno;
}

QString arbol_ast::operacion_flotante(Nodo **raiz,Figura f,bool s)
{
    float x = 0.0;
    float y = 0.0;
    float result = 0.0;
    QString operador = "";
    if((*raiz) && s == true){
        operador = (*raiz)->valor;
        if(operador.compare("NUMERO")==0){
            result = (*raiz)->sub_izq->valor.toFloat();
            return QString::number(result);
        }else if(operador.compare("CADENA")==0){
            Errores er("Sintactico",f.getNombre(),"Se esta intentado opera una variable no compatible",0,0);
            lista_errores.append(er);
            s = false;
        }else if(operador.compare("VARIABLE")==0){
            Variable aux;
            if(lista_variables.contains((*raiz)->sub_izq->valor)==true){
                aux = lista_variables.value((*raiz)->sub_izq->valor);
                if(aux.getTipo().compare("flotante")==0 || aux.getTipo().compare("entero")==0){
                    result = aux.getValor().toFloat();
                    return QString::number(result);
                }else{
                    Errores er("Sintactico",f.getNombre(),"Se esta intentado operar una variable no compatible",0,0);
                    lista_errores.append(er);
                    s = false;
                }
            }else{
                Errores er("Sintactico",f.getNombre(),"Se esta intentado operar una variable no existente",0,0);
                lista_errores.append(er);
                s = false;
            }
        }else if(operador.compare("ARREGLO")==0){
            Errores er("Sintactico",f.getNombre(),"Se esta intentado operar una variable no compatible",0,0);
            lista_errores.append(er);
            s = false;
        }
        x = operacion_flotante(&(*raiz)->sub_izq,f,&s).toFloat();
        y = operacion_flotante(&(*raiz)->sub_der,f,&s).toFloat();
        if(s == true){
            if(operador.compare("+")==0){
                result = x + y;
                return QString::number(result);
            }else if(operador.compare("-")==0){
                result = x - y;
                return QString::number(result);
            }else if(operador.compare("*")==0){
                result = x * y;
                return QString::number(result);
            }else if(operador.compare("/") == 0){
                if(y != 0){
                    result = x / y;
                    return QString::number(result);
                }else{
                    Errores er("Sintactico",f.getNombre(),"Se esta intentado hacer un division entre cero",0,0);
                    lista_errores.append(er);
                    s = false;
                }
            }else if(operador.compare("%")== 0){
                Errores er("Sintactico",f.getNombre(),"Se esta intentado obtener modulo con flotantes",0,0);
                lista_errores.append(er);
                s = false;
            }
        }
    }
    return QString::number(result);
}

QList<Coordenadas> arbol_ast::valor_arreglo(Nodo **raiz, Figura f)
{
    QList<Coordenadas> retorno;
    Variable aux;
    if((*raiz)->valor.compare("CADENA")==0){
        Errores er("Semantico",f.getNombre(),"No es del tipo cadena",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("NUMERO")==0){
        Errores er("Semantico",f.getNombre(),"No es del tipo entero o flotante",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("IDENTIFICADOR")==0){
        if(lista_variables.contains((*raiz)->sub_izq->valor) == true){
            aux = lista_variables.value((*raiz)->sub_izq->valor);
            retorno = aux.getArreglo();
            return retorno;
        }else{
            Errores er("Semantico",(*raiz)->sub_izq->valor,"No existe la variable",0,0);
            lista_errores.append(er);
        }
    }else if((*raiz)->valor.compare("+")==0||(*raiz)->valor.compare("-")== 0||(*raiz)->valor.compare("*")==0||(*raiz)->valor.compare("/") == 0||(*raiz)->valor.compare("%")==0){
        Errores er("Semantico",f.getNombre(),"No es del tipo entero o flotante",0,0);
        lista_errores.append(er);
    }else if((*raiz)->valor.compare("ARREGLO")==0){
        return retorno;
    }
    return retorno;
}

QList<Coordenadas> arbol_ast::operacion_arreglo(Nodo **raiz, Figura f, bool s)
{

}

/*******************************************METODOS PARA LA MODIFICACION DE VARIABLES**************************************************/
void arbol_ast:: modificacion_variables(Nodo **raiz){
    Variable aux;
    if(lista_variables.contains((*raiz)->sub_izq->sub_izq->valor)==true){
        aux = lista_variables.value((*raiz)->sub_izq->sub_izq->valor);
        if(aux.getTipo().compare("entero")==0){
            aux.setValor(valor_entero(&(*raiz)->lista_acciones[0],aux));
        }else if(aux.getTipo().compare("flotante")==0){
            aux.setValor(valor_flotante(&(*raiz)->lista_acciones[0],aux));
        }else if(aux.getTipo().compare("cadena")==0){
            aux.setValor(valor_cadena(&(*raiz)->lista_acciones[0],aux));
        }else if(aux.getTipo().compare("arreglo")==0){
            aux.setArreglo(valor_arreglo(&(*raiz)->lista_acciones[0],aux));
        }else if(aux.getTipo().compare("linea")==0){
            for(int cont = 0; cont<3;cont++){
                if((*raiz)->lista_acciones[cont] != NULL){
                    if((*raiz)->lista_acciones[cont]->valor.compare("COLOR")==0){
                        aux.setColor((*raiz)->lista_acciones[0]->sub_izq->valor);
                    }else if((*raiz)->lista_acciones[cont]->valor.compare("TIPO LINEA")==0){
                        aux.setLinea((*raiz)->lista_acciones[0]->sub_izq->valor);
                    }else{
                        aux.setGrosor(valor_flotante(&(*raiz)->lista_acciones[0],aux));
                    }
                }
            }

        }else if(aux.getTipo().compare("textura")==0){
            if((*raiz)->lista_acciones[0]->valor.compare("COLOR")==0){
                aux.setColor((*raiz)->lista_acciones[0]->sub_izq->valor);
            }else{
                Errores er("Semantico",aux.getNombre(),"Variable no es tipo color",0,0);
                lista_errores.append(er);
            }
        }
    }else{
        Errores er("Semantico",(*raiz)->sub_izq->sub_izq->valor,"Variable no existente",0,0);
        lista_errores.append(er);
    }
}
/*******************************************METODOS PARA LA MODIFICACION DE FIGURAS**************************************************/
void arbol_ast::manejo_figuras(Nodo **raiz){
    Figura aux;
    aux.setNombre((*raiz)->sub_izq->sub_izq->valor);
    aux.setTipo((*raiz)->sub_der->sub_izq->valor);
    if(aux.getTipo().compare("M-triangulo")==0){
        aux.setTipo("Triangulo");
        aux = crear_triangulo(&(*raiz)->sub_der,aux);
    }else if(aux.getTipo().compare("M-ovalo")==0){
        aux.setTipo("Ovalo");
        aux = crear_ovalo(&(*raiz)->sub_der,aux);
    }else if(aux.getTipo().compare("M-poligono")==0){
        aux.setTipo("Poligono");
        aux = crear_poligono(&(*raiz)->sub_der,aux);
    }else if(aux.getTipo().compare("M-circulo")==0){
        aux.setTipo("Circulo");
        aux = crear_circulo(&(*raiz)->sub_der,aux);
    }else if(aux.getTipo().compare("M-rectangulo")==0){
        aux.setTipo("Rectangulo");
        aux = crear_rectangulo(&(*raiz)->sub_der,aux);
    }else if(aux.getTipo().compare("M-nube")==0){
        aux.setTipo("Nube");
        aux = crear_nube(&(*raiz)->sub_der,aux);
    }else if(aux.getTipo().compare("M-punto")==0){
        aux.setTipo("Punto");
        aux = crear_punto(&(*raiz)->sub_der,aux);
    }else if(aux.getTipo().compare("M-texto")==0){
        aux.setTipo("Texto");
        aux = crear_texto(&(*raiz)->sub_der,aux);
    }else if(aux.getTipo().compare("M-imagen")==0){
        aux.setTipo("Imagen");
        aux = crear_imagen(&(*raiz)->sub_der,aux);
    }else if(aux.getTipo().compare("M-flecha")==0){
        aux.setTipo("Flecha");
        aux = crear_flecha(&(*raiz)->sub_der,aux);
    }else if(aux.getTipo().compare("M-linea")==0){
        aux.setTipo("Linea");
        aux = crear_linea(&(*raiz)->sub_der,aux);
    }
    lista_figuras.insert(aux.getNombre(),aux);
}

void arbol_ast::graficar_figuras(Nodo **raiz)
{
    lista_imprimir.append((*raiz)->sub_izq->sub_izq->valor);
}

void arbol_ast::rotar_figuras(Nodo **raiz)
{
    Figura f;
    if(lista_figuras.contains((*raiz)->sub_izq->sub_izq->valor)==true){
        f = lista_figuras.value((*raiz)->sub_izq->sub_izq->valor);
    }else{
        Errores er("Semantico",(*raiz)->sub_izq->sub_izq->valor,"figura no existente",0,0);
        lista_errores.append(er);
    }
}

void arbol_ast::borrar_figuras(Nodo **raiz)
{
    lista_figuras.remove((*raiz)->sub_izq->sub_izq->valor);
}

Figura arbol_ast::crear_triangulo(Nodo **raiz, Figura f)
{
    for(int cont = 0; cont<256; cont++){
        if((*raiz)->lista_acciones[cont] != NULL){
            if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posx")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosx(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posy")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosy(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radiox")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radiox no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radioy")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radio")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radio no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-base")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setBase(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-altura")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setAltura(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-textura")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setTextura(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro textura no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-linea")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setLinea(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro linea corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-color")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro color no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-tamaño")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-opaco")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setOpaco(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-arreglo")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro arreglo no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else{
                break;
            }
        }
    }
    return f;
}

Figura arbol_ast::crear_ovalo(Nodo **raiz, Figura f)
{
    for(int cont = 0; cont<256; cont++){
        if((*raiz)->lista_acciones[cont] != NULL){
            if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posx")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosx(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posy")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosy(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radiox")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setRadiox(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radioy")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setRadioy(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radio")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radio no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-base")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro base no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-altura")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro altura no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-textura")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setTextura(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-linea")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setLinea(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-color")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro color no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-tamaño")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-opaco")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setOpaco(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-arreglo")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro arreglo no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else{
                break;
            }
        }
    }
    return f;
}

Figura arbol_ast::crear_poligono(Nodo **raiz, Figura f)
{
    for(int cont = 0; cont<256; cont++){
        if((*raiz)->lista_acciones[cont] != NULL){
            if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posx")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro posx no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posy")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro posx no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radiox")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radiox no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radioy")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radio")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radio no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-base")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro base no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-altura")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro altura no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-textura")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setTextura(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-linea")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setLinea(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-color")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro color no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-tamaño")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-opaco")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setOpaco(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-arreglo")==0){
                QList<Coordenadas> aux = valor_arreglo(&(*raiz)->lista_acciones[cont]->sub_der,f);
                f.setLista_coordenadas(aux);
            }else{
                break;
            }
        }
    }
    return f;
}

Figura arbol_ast::crear_circulo(Nodo **raiz, Figura f)
{
    for(int cont = 0; cont<256; cont++){
        if((*raiz)->lista_acciones[cont] != NULL){
            if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posx")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosx(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posy")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosy(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radiox")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radiox no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radioy")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radio")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setRadio(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-base")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro base no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-altura")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro altura no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-textura")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setTextura(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-linea")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setLinea(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-color")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro color no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-tamaño")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-opaco")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setOpaco(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-arreglo")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro arreglo no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else{
                break;
            }
        }
    }
    return f;
}

Figura arbol_ast::crear_rectangulo(Nodo **raiz, Figura f)
{
    for(int cont = 0; cont<256; cont++){
        if((*raiz)->lista_acciones[cont] != NULL){
            if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posx")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosx(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posy")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosy(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radiox")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radiox no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radioy")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radio")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radio no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-base")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setBase(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-altura")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setAltura(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-textura")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setTextura(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-linea")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setLinea(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-color")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro color no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-tamaño")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-opaco")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setOpaco(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-arreglo")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro arreglo no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else{
                break;
            }
        }
    }
    return f;
}

Figura arbol_ast::crear_nube(Nodo **raiz, Figura f)
{
    for(int cont = 0; cont<256; cont++){
        if((*raiz)->lista_acciones[cont] != NULL){
            if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posx")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosx(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posy")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosy(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radiox")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radiox no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radioy")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radio")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radio no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-base")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setBase(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-altura")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setAltura(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-textura")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setTextura(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-linea")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setLinea(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-color")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro color no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-tamaño")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-opaco")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setOpaco(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-arreglo")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro arreglo no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else{
                break;
            }
        }
    }
    return f;
}

Figura arbol_ast::crear_punto(Nodo **raiz, Figura f)
{
    for(int cont = 0; cont<256; cont++){
        if((*raiz)->lista_acciones[cont] != NULL){
            if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posx")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosx(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posy")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosy(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radiox")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radiox no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radioy")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radio")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radio no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-base")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro base no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-altura")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro altura no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-textura")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro textura no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-linea")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setLinea(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-color")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro color no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-texto")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro texto no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-tamaño")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-opaco")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setOpaco(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-arreglo")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro arreglo no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else{
                break;
            }
        }
    }
    return f;
}

Figura arbol_ast::crear_texto(Nodo **raiz, Figura f)
{
    for(int cont = 0; cont<256; cont++){
        if((*raiz)->lista_acciones[cont] != NULL){
            if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posx")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosx(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posy")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosy(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radiox")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radiox no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radioy")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radio")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radio no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-base")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro base no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-altura")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro altura no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-textura")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro textura no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-linea")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro linea no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-color")==0){
                 f.setColor((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-texto")==0){
                QString aux = valor_cadena(&(*raiz)->lista_acciones[cont]->sub_der,f);
                f.setTexto(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-tamaño")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setTamano(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-opaco")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setOpaco(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-arreglo")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro arreglo no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else{
                break;
            }
        }
    }
    return f;
}

Figura arbol_ast::crear_imagen(Nodo **raiz, Figura f)
{
    for(int cont = 0; cont<256; cont++){
        if((*raiz)->lista_acciones[cont] != NULL){
            if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posx")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosx(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posy")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosy(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radiox")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radiox no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radioy")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radio")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radio no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-base")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setBase(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-altura")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setAltura(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-textura")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro textura no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-linea")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro linea no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-color")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro color no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-texto")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro texto no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-tamaño")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-opaco")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setOpaco(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-arreglo")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro arreglo no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else{
                break;
            }
        }
    }
    return f;
}

Figura arbol_ast::crear_flecha(Nodo **raiz, Figura f)
{
    for(int cont = 0; cont<256; cont++){
        if((*raiz)->lista_acciones[cont] != NULL){
            if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posx")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosx(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posy")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosy(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radiox")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radiox no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radioy")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radio")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radio no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-base")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setBase(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-altura")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setAltura(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-textura")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setTextura(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-linea")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setLinea(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-color")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro color no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-texto")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro texto no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-tamaño")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-opaco")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setOpaco(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-arreglo")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro arreglo no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else{
                break;
            }
        }
    }
    return f;
}

Figura arbol_ast::crear_linea(Nodo **raiz, Figura f)
{
    for(int cont = 0; cont<256; cont++){
        if((*raiz)->lista_acciones[cont] != NULL){
            if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posx")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosx(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-posy")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setPosy(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radiox")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radiox no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radioy")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-radio")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radio no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-base")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setBase(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-altura")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setAltura(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-textura")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setTextura(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-linea")==0){
                if((*raiz)->lista_acciones[cont]->sub_der->valor.compare("IDENTIFICADOR")==0){
                   if(lista_variables.contains((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor) == true){
                       Variable aux2 = lista_variables.value((*raiz)->lista_acciones[cont]->sub_der->sub_izq->valor);
                       f.setLinea(aux2);
                   }else{
                       Errores er("Sintactico",f.getNombre(),"Variable no existente",0,0);
                       lista_errores.append(er);
                   }
                }else{
                    Errores er("Sintactico",f.getNombre(),"Parametro no corresponde a este tipo de figura",0,0);
                    lista_errores.append(er);
                }
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-color")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro color no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-texto")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro texto no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-tamaño")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro radioy no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-opaco")==0){
                float aux = valor_flotante(&(*raiz)->lista_acciones[cont]->sub_der,f).toFloat();
                f.setOpaco(aux);
            }else if((*raiz)->lista_acciones[cont]->sub_izq->sub_izq->valor.compare("M-arreglo")==0){
                Errores er("Sintactico",f.getNombre(),"Parametro arreglo no corresponde a este tipo de figura",0,0);
                lista_errores.append(er);
            }else{
                break;
            }
        }
    }
    return f;
}



