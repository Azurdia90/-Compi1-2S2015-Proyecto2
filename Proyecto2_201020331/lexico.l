%option noyywrap
%{

#include <QList>	

#include "parser.h"
#include "errores.h"

#include <iostream>

using namespace std;
int columna =0;
int linea = 1;
extern QList<Errores> lista_errores;
%}

letra  [a-zñA-ZÑ]
digito  [0-9]
numero  {digito}+("."{digito}+)?
nombre  ({letra}|[_]{letra})({letra}|{digito}|[_])*
cadena 	[\"][^\"\n]+[\"]
comentario_multi "/*"[^'*']*"*/"
comentario "//"[^\n]*
%%

"<M-programa>"          { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return etiqueta_programa; }
"<M-variables>"         { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return etiqueta_variables; }
"<M-figura>"            { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return etiqueta_figura; }
"<M-diseño>"            { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return etiqueta_diseno; }	
"<M-parametro>"         { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_parametro; }
"AND"         			{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_and; }
"M-agregar-figura"      { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_agregar_figura; }
"M-altura"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_altura; }
"M-amarillo"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_amarillo; }
"M-anaranjado"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_anaranjado; }
"M-arreglo"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_arreglo; }
"M-azul"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_azul; }
"M-base"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_base; }
"M-borrar"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_borrar; }
"M-blanco"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_blanco; }
"M-cadena"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_cadena; }
"M-cafe"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_cafe; }
"M-caso"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_case; }
"M-celeste"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_celeste; }
"M-color"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_color; }
"M-circulo"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_circulo; }
"M-eleccion"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_eleccion; }
"M-elegante"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_elegante; }
"M-entero"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_entero; }
"M-expresion"      		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_expresion; }
"M-flotante"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_flotante; }
"M-fin"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_fin; }
"M-flecha"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_flecha; }
"M-formal"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_formal; }
"M-gotica"       	  	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_gotica; }
"M-grados"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_grados; }
"M-gris"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_gris; }
"M-grosor"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_grosor; }
"M-inicial"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_inicial; }
"M-imagen"	         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_imagen; }
"M-letra"	         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_letra; }
"M-linea"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_linea; }
"M-lineaguion"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_lineaguion; }
"M-lineapunto"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_lineapunto; }
"M-lineasolida"         { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_lineasolida; }
"M-lineaguionpunto"     { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_lineaguionpunto; }
"M-medida"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_medida; }
"M-mientras"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_while; }
"M-moderna"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_moderna; }
"M-modificar"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_modificar; }
"M-morado"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_morado; }
"M-mover"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_mover; }
"M-negro"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_negro; }
"M-nube"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_nube; }
"M-nombre"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_nombre; }
"M-opaco"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_opaco; }
"M-ovalo"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_ovalo; }
"M-para"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_for; }
"M-path"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_path; }
"M-poligono"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_poligono; }
"M-posx"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_posx; }
"M-posy"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_posy; }
"M-punto"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_punto; }
"M-radio"         	    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_radio; }
"M-radiox"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_radiox; }
"M-radioy"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_radioy; }
"M-redimensionar"       { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_redimensionar; }
"M-rectangulo"       	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_rectangulo; }
"M-rojo"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_rojo; }
"M-rotar"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_rotar; }
"M-si"         			{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_if; }
"M-sino"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_else; }
"M-tipo"			    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_tipo; }
"M-tipo_propiedad"      { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_tipo_propiedad; }
"M-texto" 	        	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_texto; }
"M-textura"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_textura; }
"M-triangulo"         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_triangulo; }
"M-valor"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_valor; }
"M-verde"         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_verde; }
"NOT"         			{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_not; }
"OR"         			{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_or; }
"<M-interrumpir#>"      { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return r_break; }
"<"		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_tag_abrir; }
","		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_coma; }
"=="		         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_comparacion; }
"!="		         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_desigualdad; }
"/"		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_division; }
"<="		         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_menor_que; }
">="		         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_mayor_que; }
"="		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_igual; }
"+"		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_suma; }
"-"		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_resta; }
"*"		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_multiplicacion; }
"%"		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_porcentaje; }
"("		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_par_a; }
")"			         	{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_par_c; }
"{"		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_llave_abrir; }
"}"		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_llave_cerrar; }
">"		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_tag_cerrar; }
";"		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_punto_coma; }
"#"		         		{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return s_numeral; }
{cadena}				{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return cadena; }
{numero}				{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return numero; }				
{nombre}				{ columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return nombre; }

{comentario_multi}		{/*SE IGNORAN LOS COMENTARIOS*/}
{comentario}			{/*SE IGNORAN LOS COMENTARIOS*/}
[ \t]+        		{/*SE IGNORAN LOS ESPACIOS EN BLANCO Y TABULADORES*/}
"\n"				{linea++; columna = 0;}
.                  	{ //std::cout <<"Error Lexico: "<<yytext<<" columna: "<<columna<< std::endl;
					  Errores er("Lexico",yytext, "Identificador desconocido en el lenguaje", columna, linea);
					  lista_errores.append(er);}

%%