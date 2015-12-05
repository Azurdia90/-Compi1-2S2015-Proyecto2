
%{

#include "scanner.h"		//se importa el header del analisis lexico
#include "nodo_arbol_ast.h" //importar para dar tipo a los terminales
#include "arbol_ast.h"
#include "errores.h"

#include <iostream> 		//imprimir en cosola de C	
#include <QString> 			//manejo de STRINGS de QT
#include <QPlainTextEdit> 		//libreria QTextEdit de QT para poder mostrar el resultado en pantalla


extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int linea;	//linea actual donde se encuentra el parser
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
extern QList<Errores> lista_errores;

struct Nodo *root; 
int cont = 1;
int cont_atri = 0;
int cont_acciones = 0;
int cont_array = 0;
int cont_var = 0;
int cont_opa = 0;
int cont_par = 0;
int cont_fig = 0;

//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
//%error-verbose

//metodo que se llama al haber un error sintactico
int yyerror(const char* mens){
//SE IMPRIME EN CONSOLA EL ERROR
//std::cout <<mens<<" "<<yytext<< std::endl;
Errores er("Sintactico",yytext,"Error de sintaxis",columna,linea);
lista_errores.append(er);

return 0;
}

QPlainTextEdit* salida; //puntero al QTextEdit de salida
void setSalida(QPlainTextEdit* sal){
//metodo que asigna el valor al QTextEdit de salida
salida=sal;
}

/*ESTRUCTURA LA CUAL CONTENDRA LOS TIPOS DE LOS NO TERMINALES PARA HEREDAR VALORES
struct Nodo{
	QString  valor;
	int id;

	struct Nodo *sub_izq;
	struct Nodo *sub_der;
};*/

%}

//se especifican los tipo de valores para los no terminales y lo terminales
%union{

	char TEXT [256];
	int entero;

	struct Nodo *nodo;
}

//TERMINALES DE TIPO TEXTO, SON QSTRING
%token<TEXT> r_and r_agregar_figura r_altura r_amarillo r_anaranjado r_arreglo r_azul r_base r_borrar r_blanco r_cadena
%token<TEXT> r_cafe r_case r_celeste r_color r_circulo r_eleccion r_elegante r_entero r_expresion r_flotante r_fin
%token<TEXT> r_flecha r_formal r_gotica r_grados r_gris r_grosor r_inicial r_imagen r_letra r_linea r_lineaguion r_lineapunto 
%token<TEXT> r_lineasolida r_lineaguionpunto r_medida r_while r_moderna r_modificar r_morado r_mover r_negro r_nube r_nombre 
%token<TEXT> r_opaco r_ovalo r_for r_parametro r_path r_poligono r_posx r_posy r_punto r_radio r_radiox r_radioy r_redimensionar
%token<TEXT> r_rectangulo r_rojo r_rotar r_if r_else r_tipo_propiedad r_tipo r_texto r_textura r_triangulo r_valor r_verde 
%token<TEXT> r_not r_or etiqueta_programa etiqueta_variables etiqueta_figura etiqueta_diseno r_break s_mayor_que s_menor_que
%token<TEXT> s_comparacion s_desigualdad s_igual s_suma s_resta s_multiplicacion s_division s_porcentaje s_par_a s_par_c 
%token<TEXT> s_llave_abrir s_llave_cerrar s_tag_abrir s_tag_cerrar s_coma s_punto_coma s_numeral cadena numero nombre

//NO TERMINALES DE TIPO VAL, POSEEN ATRIBUTOS INT VALOR, Y QSTRING TEXTO
%type<nodo> INICIO ARCHIVO_ENTRADA LISTA_ATRIBUTOS ATRIBUTOS ATRIBUTO_VARIABLES ATRIBUTO_FIGURAS  IDENTIFICADOR

%type<nodo> LISTA_ATRIBUTO_VARIABLES ATRIBUTO_V VARIABLES MODIFICAR_VARIABLES TIPO_VARIABLE OPERACION_ARITMETICA OPERACION_ARITMETICA1 
%type<nodo>	OPERACION_ARITMETICA2 OPERACION_ARITMETICA3 ARREGLO LISTA_VALORES_ARREGLO VALORES_ARREGLO COLOR TIPO_LINEA

%type<nodo> LISTA_FIGURAS ELEMENTOS_FIGURAS FIGURAS TIPO_FIGURA  DEFINICION_PARAMETROS LISTA_PARAMETROS PARAMETROS TIPO_PROPIEDAD TIPO_LETRA

%type<nodo> ATRIBUTO_DISENIO LISTA_DISENIO DISENIO CICLOS CONDICIONALES GRAFICAR ACCIONES_ASOCIADAS FOR WHILE IF IF_ELSE CASE 
%type<nodo>	LISTA_CASOS CASO REDIMENSIONAR ROTAR MOVER MODIFICAR_PROPIEDADES BORRAR PROPIEDAD2 LISTA_SENTENCIAS SENTENCIAS
%type<nodo> EXPRESION_CONDICIONAL EXPRESION_CONDICIONAL2 EXPRESION_CONDICIONAL3 S_RELACIONAL S_LOGICO


%start INICIO

%%

INICIO:	ARCHIVO_ENTRADA
		{
			salida->setPlainText("ARCHIVO DE ENTRADA CORRECTO");
			root = new Nodo();
			root->id = 0;
			root->valor = "ROOT";
			root->sub_izq = $1;
			arbol_ast arbol(&root);
			arbol.graficar();
			arbol.recorrer();
		};

ARCHIVO_ENTRADA: 	etiqueta_programa s_llave_abrir LISTA_ATRIBUTOS s_llave_cerrar
					{
						$$ = new Nodo();
						$$->id = cont++;
						$$->valor = "ARCHIVO_ENTRADA";
						$$->sub_izq = $3;
						cont_atri = 0;
					};

LISTA_ATRIBUTOS: 	LISTA_ATRIBUTOS ATRIBUTOS
					{
						$1->lista_acciones[cont_atri] = $2;
						cont_atri = cont_atri + 1;
						$$ = $1;
					}
					|ATRIBUTOS
					{
						$$ = new Nodo();
						$$->id = cont++;
						$$->valor = "ATRIBUDOS ARCHIVO ENTRADA";
						$$->lista_acciones[0] = $1;
						cont_atri = cont_atri + 1;
					};

ATRIBUTOS:	ATRIBUTO_VARIABLES
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "VARIABLES";
				$$->sub_izq = $1;
			}
			|ATRIBUTO_FIGURAS
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "FIGURAS";
				$$->sub_izq = $1;
			}
			|ATRIBUTO_DISENIO{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "DISEÑO";
				$$->sub_izq = $1;
			};

ATRIBUTO_VARIABLES: etiqueta_variables s_llave_abrir LISTA_ATRIBUTO_VARIABLES s_llave_cerrar
					{
						$$ = $3;
						cont_var = 0;
					};

LISTA_ATRIBUTO_VARIABLES: 	LISTA_ATRIBUTO_VARIABLES ATRIBUTO_V
							{
								$1->lista_acciones[cont_var] = $2;
								cont_var = cont_var +1;
								$$ = $1;
							}
							|ATRIBUTO_V
							{
								$$ = new Nodo();
								$$->id = cont++;
								$$->valor = "LISTA DE VARIABLES Y MODIFICACION DE VARIABLES";
								$$->lista_acciones[0] = $1;
								cont_var = cont_var + 1;
							};

ATRIBUTO_V:		VARIABLES
				{
					$$ = $1;
				}
				|MODIFICAR_VARIABLES
				{
					$$ = $1;
				};

VARIABLES:	s_tag_abrir TIPO_VARIABLE IDENTIFICADOR s_punto_coma r_valor s_igual OPERACION_ARITMETICA s_punto_coma s_numeral s_tag_cerrar
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "VARIABLE";
				struct Nodo *propiedades = new Nodo();
				propiedades->id = cont++;
				propiedades->valor = "PROPIEDADES";
				propiedades->sub_der = $7;
				propiedades->sub_izq = $2;
				$$->sub_izq = $3;
				$$->sub_der = propiedades;
			}
			|s_tag_abrir r_textura IDENTIFICADOR s_punto_coma r_color s_igual COLOR s_punto_coma s_numeral s_tag_cerrar
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "VARIABLE";
				struct Nodo *tipo = new Nodo();
				tipo->id = cont++;
				tipo->valor = "TIPO";
				struct Nodo *linea = new Nodo();
				linea->id = cont++;
				linea->valor = $2;
				tipo->sub_izq = linea;
				struct Nodo *propiedades = new Nodo();
				propiedades->id = cont++;
				propiedades->valor = "PROPIEDADES";
				propiedades->sub_der = $7;
				propiedades->sub_izq = tipo;
				$$->sub_izq = $3;
				$$->sub_der = propiedades;

			}
			|s_tag_abrir r_textura IDENTIFICADOR s_punto_coma r_path s_igual OPERACION_ARITMETICA s_punto_coma s_numeral s_tag_cerrar	
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "VARIABLE";
				struct Nodo *tipo = new Nodo();
				tipo->id = cont++;
				tipo->valor = "TIPO";
				struct Nodo *linea = new Nodo();
				linea->id = cont++;
				linea->valor = $2;
				tipo->sub_izq = linea;
				struct Nodo *propiedades = new Nodo();
				propiedades->id = cont++;
				propiedades->valor = "PROPIEDADES";
				propiedades->sub_der = $7;
				propiedades->sub_izq = tipo;
				$$->sub_izq = $3;
				$$->sub_der = propiedades;

			}
			|s_tag_abrir r_linea IDENTIFICADOR s_punto_coma r_color s_igual COLOR s_punto_coma r_tipo s_igual TIPO_LINEA s_punto_coma r_grosor s_igual OPERACION_ARITMETICA s_punto_coma s_numeral s_tag_cerrar
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "VARIABLE";
				struct Nodo *tipo = new Nodo();
				tipo->id = cont++;
				tipo->valor = "TIPO";
				struct Nodo *linea = new Nodo();
				linea->id = cont++;
				linea->valor = $2;
				tipo->sub_izq = linea;
				struct Nodo *propiedades = new Nodo();
				propiedades->id = cont++;
				propiedades->valor = "PROPIEDADES";
				propiedades->lista_acciones[0] = $7;
				propiedades->lista_acciones[1] = $11;
				propiedades->lista_acciones[2] = $15;
				propiedades->sub_izq = tipo;
				$$->sub_izq = $3;
				$$->sub_der = propiedades;
			};

MODIFICAR_VARIABLES:	s_tag_abrir r_modificar IDENTIFICADOR s_punto_coma r_valor s_igual OPERACION_ARITMETICA s_punto_coma s_numeral s_tag_cerrar
						{
							/*PRODUCCION PARA PODER MODIFICAR LAS VARIABLES NORMALES*/
							$$ = new Nodo();
							$$->id = cont++;
							$$->valor = "MODIFICACION DE VARIABLE";
							$$->sub_izq = $3;
							$$->lista_acciones[0] = $7;
						}
						|s_tag_abrir r_modificar IDENTIFICADOR s_punto_coma r_color s_igual COLOR s_punto_coma r_tipo s_igual TIPO_LINEA s_punto_coma r_grosor s_igual OPERACION_ARITMETICA s_punto_coma s_numeral s_tag_cerrar
						{
							$$ = new Nodo();
							$$->id = cont++;
							$$->valor = "MODIFICACION DE VARIABLE";
							$$->sub_izq = $3;
							$$->lista_acciones[0] = $7;
							$$->lista_acciones[1] = $11;
							$$->lista_acciones[2] = $15;
						}	
						|s_tag_abrir r_modificar IDENTIFICADOR s_punto_coma r_color s_igual COLOR s_punto_coma r_grosor s_igual OPERACION_ARITMETICA s_punto_coma s_numeral s_tag_cerrar
						{
							$$ = new Nodo();
							$$->id = cont++;
							$$->valor= "MODIFICACION DE VARIABLE";
							$$->sub_izq = $3;
							$$->lista_acciones[0] = $7;
							$$->lista_acciones[1] = $11;
						}
						|s_tag_abrir r_modificar IDENTIFICADOR s_punto_coma r_tipo s_igual TIPO_LINEA s_punto_coma r_grosor s_igual OPERACION_ARITMETICA s_punto_coma s_numeral s_tag_cerrar
						{
							$$ = new Nodo();
							$$->id = cont++;
							$$->valor= "MODIFICACION DE VARIABLE";
							$$->sub_izq = $3;
							$$->lista_acciones[0] = $7;
							$$->lista_acciones[1] = $11;
						}
						|s_tag_abrir r_modificar IDENTIFICADOR s_punto_coma r_color s_igual COLOR s_punto_coma r_tipo s_igual TIPO_LINEA s_punto_coma s_numeral s_tag_cerrar
						{
							$$ = new Nodo();
							$$->id = cont++;
							$$->valor = "MODIFICACION DE VARIABLE";
							$$->sub_izq = $3;
							$$->lista_acciones[0] = $7;
							$$->lista_acciones[1] = $11;
						}
						|s_tag_abrir r_modificar IDENTIFICADOR s_punto_coma r_tipo s_igual TIPO_LINEA s_punto_coma s_numeral s_tag_cerrar
						{
							$$ = new Nodo();
							$$->id = cont++;
							$$->valor = "MODIFICACION DE VARIABLE";
							$$->sub_izq = $3;
							$$->lista_acciones[0] = $7;

						}
						|s_tag_abrir r_modificar IDENTIFICADOR s_punto_coma r_color s_igual COLOR s_punto_coma s_numeral s_tag_cerrar
						{
							/*ESTA PRODUCCION ES UTILIZADA TANTO POR LAS VARIABLES TIPO LINEA COMO TEXTURA*/
							$$ = new Nodo();
							$$->id = cont++;
							$$->valor = "MODIFICACION DE VARIABLE";
							$$->sub_izq = $3;
							$$->lista_acciones[0] = $7;
						};

TIPO_VARIABLE: 	r_entero
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = $1;
					$$->sub_izq = hijo;
				}
				|r_cadena
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = $1;
					$$->sub_izq = hijo;
				}
				|r_flotante
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = $1;
					$$->sub_izq = hijo;
				}
				|r_arreglo
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = $1;
					$$->sub_izq = hijo;
				};

OPERACION_ARITMETICA:	OPERACION_ARITMETICA s_suma OPERACION_ARITMETICA1
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = $2;
				$$->sub_izq = $1;
				$$->sub_der = $3;
			}
			|OPERACION_ARITMETICA s_resta OPERACION_ARITMETICA1
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = $2;
				$$->sub_izq = $1;
				$$->sub_der = $3;
			}
			|OPERACION_ARITMETICA1
			{
				$$ = $1;
			};

OPERACION_ARITMETICA1: 	OPERACION_ARITMETICA1 s_multiplicacion OPERACION_ARITMETICA2
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $2;
					$$->sub_izq = $1;
					$$->sub_der = $3;
				}
				|OPERACION_ARITMETICA1 s_division OPERACION_ARITMETICA2
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $2;
					$$->sub_izq = $1;
					$$->sub_der = $3;
				}
				|OPERACION_ARITMETICA1 s_porcentaje OPERACION_ARITMETICA2
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $2;
					$$->sub_izq = $1;
					$$->sub_der = $3;
				}
				|OPERACION_ARITMETICA2	
				{
					$$ = $1;
				};

OPERACION_ARITMETICA2:	s_par_a OPERACION_ARITMETICA s_par_c
				{
					$$ = $2;
				}	
				|OPERACION_ARITMETICA3
				{
					$$ = $1;
				};

OPERACION_ARITMETICA3:	numero
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "NUMERO";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = $1;
					$$->sub_izq = hijo;
				}
				|nombre
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "IDENTIFICADOR";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = $1;
					$$->sub_izq = hijo;
				}
				|cadena
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "CADENA";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = $1;
					$$->sub_izq = hijo;
				}
				|ARREGLO
				{
					$$ = $1;
				};

ARREGLO:	s_llave_abrir LISTA_VALORES_ARREGLO s_llave_cerrar
			{
				$$ = $2;
				cont_array = 0;
			};

LISTA_VALORES_ARREGLO:	LISTA_VALORES_ARREGLO s_coma VALORES_ARREGLO
						{
							$1->lista_acciones[cont_array] = $3;
							cont_array = cont_array + 1;
							$$ = $1;
						}
						|VALORES_ARREGLO
						{
							$$ = new Nodo();
							$$->id = cont++;
							$$->valor = "ARREGLO";
							$$->lista_acciones[0] = $1;
							cont_array = cont_array + 1;
						};

VALORES_ARREGLO:	s_par_a OPERACION_ARITMETICA s_coma OPERACION_ARITMETICA s_par_c
					{
						$$ = new Nodo();
						$$->id = cont++;
						$$->valor = "POSICION ARREGLO";
						$$->sub_izq = $2;
						$$->sub_der = $4;
					};

COLOR:	r_anaranjado
		{
			$$ = new Nodo();
			$$->id = cont++;
			QString temp = "COLOR";
			$$->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = $1;
			nodo_hijo->valor = temp2;
			$$->sub_izq = nodo_hijo;
		}
		|r_azul
		{
			$$ = new Nodo();
			$$->id = cont++;
			QString temp = "COLOR";
			$$->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = $1;
			nodo_hijo->valor = temp2;
			$$->sub_izq = nodo_hijo;
		}
		|r_celeste
		{
			$$ = new Nodo();
			$$->id = cont++;
			QString temp = "COLOR";
			$$->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = $1;
			nodo_hijo->valor = temp2;
			$$->sub_izq = nodo_hijo;
		}
		|r_rojo
		{
			$$ = new Nodo();
			$$->id = cont++;
			QString temp = "COLOR";
			$$->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = $1;
			nodo_hijo->valor = temp2;
			$$->sub_izq = nodo_hijo;
		}
		|r_verde
		{
			$$ = new Nodo();
			$$->id = cont++;
			QString temp = "COLOR";
			$$->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = $1;
			nodo_hijo->valor = temp2;
			$$->sub_izq = nodo_hijo;
		}
		|r_amarillo
		{
			$$ = new Nodo();
			$$->id = cont++;
			QString temp = "COLOR";
			$$->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = $1;
			nodo_hijo->valor = temp2;
			$$->sub_izq = nodo_hijo;
		}
		|r_morado
		{
			$$ = new Nodo();
			$$->id = cont++;
			QString temp = "COLOR";
			$$->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = $1;
			nodo_hijo->valor = temp2;
			$$->sub_izq = nodo_hijo;
		}
		|r_negro
		{
			$$ = new Nodo();
			$$->id = cont++;
			QString temp = "COLOR";
			$$->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = $1;
			nodo_hijo->valor = temp2;
			$$->sub_izq = nodo_hijo;
		}
		|r_gris
		{
			$$ = new Nodo();
			$$->id = cont++;
			QString temp = "COLOR";
			$$->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = $1;
			nodo_hijo->valor = temp2;
			$$->sub_izq = nodo_hijo;
		}
		|r_cafe
		{
			$$ = new Nodo();
			$$->id = cont++;
			QString temp = "COLOR";
			$$->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = $1;
			nodo_hijo->valor = temp2;
			$$->sub_izq = nodo_hijo;
		}
		|r_blanco 
		{
			$$ = new Nodo();
			$$->id = cont++;
			QString temp = "COLOR";
			$$->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = $1;
			nodo_hijo->valor = temp2;
			$$->sub_izq = nodo_hijo;
		};


TIPO_LINEA:	r_lineasolida
			{
				$$ = new Nodo();
				$$->id = cont++;
				QString temp = "TIPO DE LINEA";
				$$->valor = temp;
				struct Nodo *nodo_hijo = new Nodo();
				nodo_hijo->id = cont++;
				QString temp2 = $1;
				nodo_hijo->valor = temp2;
				$$->sub_izq = nodo_hijo;
			}
			|r_lineaguion
			{
				$$ = new Nodo();
				$$->id = cont++;
				QString temp = "TIPO DE LINEA";
				$$->valor = temp;
				struct Nodo *nodo_hijo = new Nodo();
				nodo_hijo->id = cont++;
				QString temp2 = $1;
				nodo_hijo->valor = temp2;
				$$->sub_izq = nodo_hijo;
			}
			|r_lineapunto
			{
				$$ = new Nodo();
				$$->id = cont++;
				QString temp = "TIPO DE LINEA";
				$$->valor = temp;
				struct Nodo *nodo_hijo = new Nodo();
				nodo_hijo->id = cont++;
				QString temp2 = $1;
				nodo_hijo->valor = temp2;
				$$->sub_izq = nodo_hijo;
			}
			|r_lineaguionpunto
			{
				$$ = new Nodo();
				$$->id = cont++;
				QString temp = "TIPO DE LINEA";
				$$->valor = temp;
				struct Nodo *nodo_hijo = new Nodo();
				nodo_hijo->id = cont++;
				QString temp2 = $1;
				nodo_hijo->valor = temp2;
				$$->sub_izq = nodo_hijo;
			};


ATRIBUTO_FIGURAS: 	etiqueta_figura s_llave_abrir LISTA_FIGURAS s_llave_cerrar
					{
						$$ = $3;
						cont_fig = 0;
					};

LISTA_FIGURAS:	LISTA_FIGURAS ELEMENTOS_FIGURAS
				{
					$1->lista_acciones[cont_fig] = $2;
					cont_fig = cont_fig + 1;
					$$ = $1;
				}
				|ELEMENTOS_FIGURAS
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "LISTA FIGURAS";
					$$->lista_acciones[0] = $1;
					cont_fig = cont_fig + 1;
				};

ELEMENTOS_FIGURAS: 	FIGURAS
					{
						$$ =$1;
					}
					|MODIFICAR_VARIABLES
					{
						$$ = $1;
					};

FIGURAS: 	s_tag_abrir TIPO_FIGURA IDENTIFICADOR s_tag_cerrar s_llave_abrir DEFINICION_PARAMETROS s_llave_cerrar
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "FIGURA";
				$$->sub_izq = $3;
				$6->sub_izq = $2;
				$$->sub_der = $6; 

			};


TIPO_FIGURA: 	r_triangulo
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|r_ovalo				
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|r_poligono
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|r_circulo
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|r_rectangulo
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|r_nube
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|r_punto
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|r_texto
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|r_imagen
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|r_flecha
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|r_linea
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				};

DEFINICION_PARAMETROS: 	r_parametro s_llave_abrir LISTA_PARAMETROS s_llave_cerrar
						{
							$$ = $3;  
							cont_par = 0;
						};

LISTA_PARAMETROS:	LISTA_PARAMETROS PARAMETROS
					{
						$1->lista_acciones[cont_par] = $2;
						cont_par = cont_par + 1;
					}
					|PARAMETROS
					{
						$$ = new Nodo();
						$$->id = cont++;
						$$->valor = "LISTA PARAMETROS";
						$$->lista_acciones[0] = $1;
						cont_par = cont_par + 1;
					};

PARAMETROS: TIPO_PROPIEDAD s_igual OPERACION_ARITMETICA s_punto_coma
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "PARAMETRO";
				$$->sub_izq = $1;
				$$->sub_der = $3;
			}
			|r_letra s_igual TIPO_LETRA s_punto_coma
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "PARAMETRO";
				struct Nodo *propiedad = new Nodo();
				propiedad->id = cont++;
				propiedad->valor = "TIPO PROPIEDAD";
				struct Nodo *letra = new Nodo();
				letra->id = cont++;
				letra->valor = $1;
				propiedad->sub_izq = letra;
				$$->sub_izq = propiedad;
				$$->sub_der = $3;
			}
			|r_color s_igual COLOR s_punto_coma
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "PARAMETRO";
				struct Nodo *propiedad = new Nodo();
				propiedad->id = cont++;
				propiedad->valor = "TIPO PROPIEDAD";
				struct Nodo *color = new Nodo();
				color->id = cont++;
				color->valor = $1;
				propiedad->sub_izq = color;
				$$->sub_izq = propiedad;
				$$->sub_der = $3;
			};

TIPO_PROPIEDAD: r_posx
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_posy
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_base
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_altura
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_textura
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_linea
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_opaco
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_radiox
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_radioy
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_arreglo
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_radio
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_texto
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				}
				|r_medida
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = $1;
					$$->sub_izq = letra;
				};

TIPO_LETRA:	r_elegante
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "TIPO LETRA";
				struct Nodo *letra = new Nodo();
				letra->id = cont++;
				letra->valor = $1;
				$$->sub_izq = letra;
			}
			|r_gotica
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "TIPO LETRA";
				struct Nodo *letra = new Nodo();
				letra->id = cont++;
				letra->valor = $1;
				$$->sub_izq = letra;
			}
			|r_moderna
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "TIPO LETRA";
				struct Nodo *letra = new Nodo();
				letra->id = cont++;
				letra->valor = $1;
				$$->sub_izq = letra;
			}
			|r_formal
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "TIPO LETRA";
				struct Nodo *letra = new Nodo();
				letra->id = cont++;
				letra->valor = $1;
				$$->sub_izq = letra;
			};

IDENTIFICADOR: 	r_nombre s_igual nombre
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "IDENTIFICADOR";
					struct Nodo *nombre = new Nodo();
					nombre->id = cont++;
					nombre->valor = $3;
					$$->sub_izq = nombre;
				};

ATRIBUTO_DISENIO:	etiqueta_diseno s_llave_abrir LISTA_DISENIO s_llave_cerrar
					{
						$$ = $3;
						cont_acciones = 0;
					};


LISTA_DISENIO:	LISTA_DISENIO DISENIO
				{
					$1->lista_acciones[cont_acciones] = $2;
					cont_acciones = cont_acciones + 1;
					$$ = $1;
				}
				|DISENIO
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "LISTA DE DISEÑO";
					$$->lista_acciones[0] = $1;
					cont_acciones = cont_acciones + 1;
				};

DISENIO: 	CICLOS
			{
				$$ = $1;
			}
			|CONDICIONALES
			{
				$$ = $1;
			}
			|GRAFICAR
			{
				$$ = $1;
			}
			|ACCIONES_ASOCIADAS
			{
				$$ = $1;
			};

CICLOS: FOR
		{
			$$ = $1;
		}
		|WHILE
		{
			$$ = $1;
		};

FOR: 	s_tag_abrir r_for r_inicial s_igual OPERACION_ARITMETICA r_fin s_igual OPERACION_ARITMETICA s_tag_cerrar s_llave_abrir LISTA_SENTENCIAS s_llave_cerrar
		{
			$$ = new Nodo();
			$$->id = cont++;
			$$->valor = "FOR";
			struct Nodo *con = new Nodo();
			con->id = cont++;
			con->valor = "CONDICIONES";
			con->sub_izq = $5;
			con->sub_der = $8;
			$$->sub_izq = con;
			$$->sub_der = $11;
		};

WHILE: 	s_tag_abrir r_while r_expresion s_igual EXPRESION_CONDICIONAL s_tag_cerrar s_llave_abrir LISTA_SENTENCIAS s_llave_cerrar
		{
			$$ = new Nodo();
			$$->id = cont++;
			$$->valor = "WHILE";
			$$->sub_izq = $5;
			$$->sub_der = $8;
		};

CONDICIONALES:	IF
				{
					$$ = $1;
				}
				|IF_ELSE
				{
					$$ = $1;
				}
				|CASE
				{
					$$ = $1; 
				};

IF:	s_tag_abrir r_if r_expresion s_igual EXPRESION_CONDICIONAL s_tag_cerrar s_llave_abrir LISTA_SENTENCIAS s_llave_cerrar
	{
		$$ = new Nodo();
		$$->id = cont++;
		$$->valor = "IF";
		$$->sub_izq = $5;
		$$->sub_der = $8;		
	};

IF_ELSE:	s_tag_abrir r_if r_expresion s_igual EXPRESION_CONDICIONAL s_tag_cerrar s_llave_abrir LISTA_SENTENCIAS s_llave_cerrar
			r_else s_llave_abrir LISTA_SENTENCIAS s_llave_cerrar
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "IF";
				$$->sub_izq = $5;
				$$->sub_der = $8;
				struct Nodo *hijo = new Nodo();
				hijo->id = cont++;
				hijo->valor = "ELSE";
				hijo->sub_izq = $12;
				$$->lista_acciones[0] = hijo;
			};

CASE:	s_tag_abrir r_eleccion r_expresion s_igual OPERACION_ARITMETICA s_tag_cerrar s_llave_abrir LISTA_CASOS s_llave_cerrar
		{
			$$ = new Nodo();
			$$->id = cont++;
			$$->valor = "CASE";
			$$->sub_izq = $5;
			$$->sub_der = $8;
			cont_acciones = 0;
		};

LISTA_CASOS: 	LISTA_CASOS CASO
				{
					$1->lista_acciones[cont_acciones] = $2;
					cont_acciones = cont_acciones + 1;
					$$ = $1;
				}
				|CASO
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "LISTA DE CASOS";
					$$->lista_acciones[0] = $1;
					cont_acciones = cont_acciones + 1;
				};

CASO:	s_tag_abrir r_case OPERACION_ARITMETICA s_tag_cerrar s_llave_abrir LISTA_SENTENCIAS s_llave_cerrar
		{
			$$ = new Nodo();
			$$->id = cont++;
			$$->valor = "CASO";
			$$->sub_izq = $3;
			$$->sub_der = $6;
		};

GRAFICAR: 	s_tag_abrir r_agregar_figura IDENTIFICADOR s_numeral s_tag_cerrar
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "GRAFICAR";
				$$->sub_izq = $3;
			};

ACCIONES_ASOCIADAS: REDIMENSIONAR
					{
						$$ = $1;
					}
					|ROTAR
					{
						$$ = $1;
					}
					|MOVER
					{
						$$ = $1;
					}
					|MODIFICAR_PROPIEDADES
					{
						$$ = $1;
					}
					|BORRAR
					{
						$$ = $1;
					};

REDIMENSIONAR: s_tag_abrir r_redimensionar IDENTIFICADOR s_tag_cerrar s_llave_abrir r_parametro s_llave_abrir r_base  s_igual OPERACION_ARITMETICA s_punto_coma r_altura s_igual OPERACION_ARITMETICA s_punto_coma s_llave_cerrar s_llave_cerrar
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = "REDIMENSIONAR";
					$$->sub_izq = $3;
					$$->sub_der->lista_acciones[0] = $10;
					$$->sub_der->lista_acciones[1] = $14;				
				};

ROTAR: 	s_tag_abrir r_rotar IDENTIFICADOR s_punto_coma r_grados s_igual OPERACION_ARITMETICA s_punto_coma s_numeral s_tag_cerrar
		{
			$$ = new Nodo();
			$$->id = cont++;
			$$->valor = "ROTAR";
			$$->sub_izq = $3;
			$$->sub_der = $7;
		};

MOVER: s_tag_abrir r_mover IDENTIFICADOR s_tag_cerrar s_llave_abrir r_parametro s_llave_abrir r_posx  s_igual OPERACION_ARITMETICA s_punto_coma r_posy s_igual OPERACION_ARITMETICA s_punto_coma s_llave_cerrar s_llave_cerrar
		{
			$$ = new Nodo();
			$$->id = cont++;
			$$->valor = "MOVER";
			$$->sub_izq = $3;
			$$->sub_der->lista_acciones[0] = $10;
			$$->sub_der->lista_acciones[1] = $14;				
		};

MODIFICAR_PROPIEDADES: s_tag_abrir r_tipo_propiedad IDENTIFICADOR s_tag_cerrar s_llave_abrir PROPIEDAD2 s_llave_cerrar
						{
							$$ = new Nodo();
							$$->id = cont++;
							$$->valor = "MODIFICAR PROPIEDAD";
							$$->sub_izq = $3;
							$$->sub_der = $6;
						};

BORRAR: s_tag_abrir r_borrar IDENTIFICADOR s_numeral s_tag_cerrar
		{
			$$ = new Nodo();
			$$->id = cont++;
			$$->valor = "BORRAR";
			$$->sub_izq = $3;
		};

PROPIEDAD2: r_parametro s_llave_abrir r_tipo_propiedad s_igual TIPO_PROPIEDAD r_valor s_igual OPERACION_ARITMETICA s_llave_cerrar
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = "PROPIEDAD";
				$$->sub_izq = $5;
				$$->sub_der = $8;
			};

EXPRESION_CONDICIONAL:	EXPRESION_CONDICIONAL S_RELACIONAL EXPRESION_CONDICIONAL2
						{
							$2->sub_izq = $1;
							$2->sub_der = $3;
							$$ = $2;
						}
						|EXPRESION_CONDICIONAL2
						{
							$$ = $1;
						};

EXPRESION_CONDICIONAL2:	EXPRESION_CONDICIONAL2 S_LOGICO EXPRESION_CONDICIONAL3
						{
							$2->sub_izq = $1;
							$2->sub_der = $3;
							$$ = $2;
						}
						|r_not EXPRESION_CONDICIONAL3
						{
							$$ = new Nodo();
							$$->id = cont++;
							$$->valor = $1;
							$$->sub_izq = $2;
						}
						|EXPRESION_CONDICIONAL3
						{
							$$ = $1;	
						};

EXPRESION_CONDICIONAL3:	s_par_a EXPRESION_CONDICIONAL s_par_c
						{
							$$ = $2;
						}
						|OPERACION_ARITMETICA
						{
							$$ = $1;
						};

S_RELACIONAL:	s_mayor_que
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|s_menor_que
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|s_tag_abrir
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|s_tag_cerrar
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|s_comparacion
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				}
				|s_desigualdad
				{
					$$ = new Nodo();
					$$->id = cont++;
					$$->valor = $1;
				};

S_LOGICO:	r_or
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = $1;
			}
			|r_and
			{
				$$ = new Nodo();
				$$->id = cont++;
				$$->valor = $1;
			};

LISTA_SENTENCIAS: 	LISTA_SENTENCIAS SENTENCIAS
					|SENTENCIAS;

SENTENCIAS:	MODIFICAR_VARIABLES
			|FIGURAS	
			|DISENIO;

%%