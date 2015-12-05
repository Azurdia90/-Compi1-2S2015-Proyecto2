/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    r_and = 258,
    r_agregar_figura = 259,
    r_altura = 260,
    r_amarillo = 261,
    r_anaranjado = 262,
    r_arreglo = 263,
    r_azul = 264,
    r_base = 265,
    r_borrar = 266,
    r_blanco = 267,
    r_cadena = 268,
    r_cafe = 269,
    r_case = 270,
    r_celeste = 271,
    r_color = 272,
    r_circulo = 273,
    r_eleccion = 274,
    r_elegante = 275,
    r_entero = 276,
    r_expresion = 277,
    r_flotante = 278,
    r_fin = 279,
    r_flecha = 280,
    r_formal = 281,
    r_gotica = 282,
    r_grados = 283,
    r_gris = 284,
    r_grosor = 285,
    r_inicial = 286,
    r_imagen = 287,
    r_letra = 288,
    r_linea = 289,
    r_lineaguion = 290,
    r_lineapunto = 291,
    r_lineasolida = 292,
    r_lineaguionpunto = 293,
    r_medida = 294,
    r_while = 295,
    r_moderna = 296,
    r_modificar = 297,
    r_morado = 298,
    r_mover = 299,
    r_negro = 300,
    r_nube = 301,
    r_nombre = 302,
    r_opaco = 303,
    r_ovalo = 304,
    r_for = 305,
    r_parametro = 306,
    r_path = 307,
    r_poligono = 308,
    r_posx = 309,
    r_posy = 310,
    r_punto = 311,
    r_radio = 312,
    r_radiox = 313,
    r_radioy = 314,
    r_redimensionar = 315,
    r_rectangulo = 316,
    r_rojo = 317,
    r_rotar = 318,
    r_if = 319,
    r_else = 320,
    r_tipo_propiedad = 321,
    r_tipo = 322,
    r_texto = 323,
    r_textura = 324,
    r_triangulo = 325,
    r_valor = 326,
    r_verde = 327,
    r_not = 328,
    r_or = 329,
    etiqueta_programa = 330,
    etiqueta_variables = 331,
    etiqueta_figura = 332,
    etiqueta_diseno = 333,
    r_break = 334,
    s_mayor_que = 335,
    s_menor_que = 336,
    s_comparacion = 337,
    s_desigualdad = 338,
    s_igual = 339,
    s_suma = 340,
    s_resta = 341,
    s_multiplicacion = 342,
    s_division = 343,
    s_porcentaje = 344,
    s_par_a = 345,
    s_par_c = 346,
    s_llave_abrir = 347,
    s_llave_cerrar = 348,
    s_tag_abrir = 349,
    s_tag_cerrar = 350,
    s_coma = 351,
    s_punto_coma = 352,
    s_numeral = 353,
    cadena = 354,
    numero = 355,
    nombre = 356
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 61 "sintactico.y" /* yacc.c:1909  */


	char TEXT [256];
	int entero;

	struct Nodo *nodo;

#line 164 "parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
