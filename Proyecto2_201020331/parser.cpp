/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "sintactico.y" /* yacc.c:339  */


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


#line 124 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
#line 61 "sintactico.y" /* yacc.c:355  */


	char TEXT [256];
	int entero;

	struct Nodo *nodo;

#line 274 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 289 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   530

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  382

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   356

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   109,   118,   124,   133,   140,   147,   154,
     160,   166,   175,   179,   184,   197,   218,   239,   262,   271,
     281,   290,   299,   308,   317,   327,   337,   347,   357,   368,
     376,   384,   389,   397,   405,   413,   418,   422,   427,   437,
     447,   457,   462,   468,   474,   483,   492,   504,   516,   528,
     540,   552,   564,   576,   588,   600,   612,   626,   638,   650,
     662,   676,   682,   688,   697,   701,   706,   718,   724,   730,
     736,   742,   748,   754,   760,   766,   772,   778,   785,   791,
     796,   805,   813,   828,   844,   854,   864,   874,   884,   894,
     904,   914,   924,   934,   944,   954,   964,   975,   985,   995,
    1005,  1016,  1027,  1034,  1040,  1049,  1053,  1057,  1061,  1066,
    1070,  1075,  1089,  1098,  1102,  1106,  1111,  1120,  1135,  1145,
    1151,  1160,  1169,  1177,  1181,  1185,  1189,  1193,  1198,  1208,
    1217,  1227,  1236,  1244,  1253,  1259,  1264,  1270,  1277,  1282,
    1286,  1291,  1297,  1303,  1309,  1315,  1321,  1328,  1334,  1341,
    1342,  1344,  1345,  1346
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "r_and", "r_agregar_figura", "r_altura",
  "r_amarillo", "r_anaranjado", "r_arreglo", "r_azul", "r_base",
  "r_borrar", "r_blanco", "r_cadena", "r_cafe", "r_case", "r_celeste",
  "r_color", "r_circulo", "r_eleccion", "r_elegante", "r_entero",
  "r_expresion", "r_flotante", "r_fin", "r_flecha", "r_formal", "r_gotica",
  "r_grados", "r_gris", "r_grosor", "r_inicial", "r_imagen", "r_letra",
  "r_linea", "r_lineaguion", "r_lineapunto", "r_lineasolida",
  "r_lineaguionpunto", "r_medida", "r_while", "r_moderna", "r_modificar",
  "r_morado", "r_mover", "r_negro", "r_nube", "r_nombre", "r_opaco",
  "r_ovalo", "r_for", "r_parametro", "r_path", "r_poligono", "r_posx",
  "r_posy", "r_punto", "r_radio", "r_radiox", "r_radioy",
  "r_redimensionar", "r_rectangulo", "r_rojo", "r_rotar", "r_if", "r_else",
  "r_tipo_propiedad", "r_tipo", "r_texto", "r_textura", "r_triangulo",
  "r_valor", "r_verde", "r_not", "r_or", "etiqueta_programa",
  "etiqueta_variables", "etiqueta_figura", "etiqueta_diseno", "r_break",
  "s_mayor_que", "s_menor_que", "s_comparacion", "s_desigualdad",
  "s_igual", "s_suma", "s_resta", "s_multiplicacion", "s_division",
  "s_porcentaje", "s_par_a", "s_par_c", "s_llave_abrir", "s_llave_cerrar",
  "s_tag_abrir", "s_tag_cerrar", "s_coma", "s_punto_coma", "s_numeral",
  "cadena", "numero", "nombre", "$accept", "INICIO", "ARCHIVO_ENTRADA",
  "LISTA_ATRIBUTOS", "ATRIBUTOS", "ATRIBUTO_VARIABLES",
  "LISTA_ATRIBUTO_VARIABLES", "ATRIBUTO_V", "VARIABLES",
  "MODIFICAR_VARIABLES", "TIPO_VARIABLE", "OPERACION_ARITMETICA",
  "OPERACION_ARITMETICA1", "OPERACION_ARITMETICA2",
  "OPERACION_ARITMETICA3", "ARREGLO", "LISTA_VALORES_ARREGLO",
  "VALORES_ARREGLO", "COLOR", "TIPO_LINEA", "ATRIBUTO_FIGURAS",
  "LISTA_FIGURAS", "ELEMENTOS_FIGURAS", "FIGURAS", "TIPO_FIGURA",
  "DEFINICION_PARAMETROS", "LISTA_PARAMETROS", "PARAMETROS",
  "TIPO_PROPIEDAD", "TIPO_LETRA", "IDENTIFICADOR", "ATRIBUTO_DISENIO",
  "LISTA_DISENIO", "DISENIO", "CICLOS", "FOR", "WHILE", "CONDICIONALES",
  "IF", "IF_ELSE", "CASE", "LISTA_CASOS", "CASO", "GRAFICAR",
  "ACCIONES_ASOCIADAS", "REDIMENSIONAR", "ROTAR", "MOVER",
  "MODIFICAR_PROPIEDADES", "BORRAR", "PROPIEDAD2", "EXPRESION_CONDICIONAL",
  "EXPRESION_CONDICIONAL2", "EXPRESION_CONDICIONAL3", "S_RELACIONAL",
  "S_LOGICO", "LISTA_SENTENCIAS", "SENTENCIAS", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356
};
# endif

#define YYPACT_NINF -278

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-278)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -59,   -42,    56,  -278,   279,  -278,   -32,   -30,   -28,   -41,
    -278,  -278,  -278,  -278,   -24,    -8,    -2,  -278,  -278,    83,
      -5,  -278,  -278,  -278,   240,  -278,    52,  -278,  -278,    21,
      55,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
      48,    48,    48,    48,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,    48,  -278,  -278,
      48,    48,    77,    87,    48,   111,    48,    48,   131,    48,
    -278,  -278,    72,    62,    64,    66,    70,    79,    74,    97,
     113,   119,   124,   144,   146,   150,   180,   164,   172,   275,
      -4,     1,   204,   193,   199,   205,   229,   162,   223,   229,
     235,   281,   162,   250,  -278,   261,   263,   280,   282,   283,
     284,   285,   312,  -278,  -278,   229,   286,  -278,  -278,  -278,
     251,   -15,  -278,  -278,  -278,   234,   162,    91,   130,     3,
    -278,   314,    -3,   319,   287,   196,   321,   159,   159,   316,
     229,   159,   229,   229,   288,   289,   154,   229,   -51,  -278,
     229,   229,   291,   229,   229,   229,  -278,   154,    20,  -278,
    -278,  -278,  -278,  -278,   292,   162,  -278,  -278,   234,   293,
     290,   294,   229,   295,   296,   297,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,   276,   278,  -278,
    -278,  -278,  -278,   298,    38,   299,    44,    84,   175,  -278,
    -278,    22,  -278,   286,   -15,   -15,   300,  -278,  -278,  -278,
    -278,  -278,   303,     3,  -278,   323,   229,   368,    93,   303,
     313,  -278,   322,   -18,   -23,   301,   302,   304,   305,  -278,
    -278,  -278,   307,   308,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,     0,  -278,   309,   229,  -278,   366,
     122,  -278,    94,  -278,  -278,  -278,   194,  -278,   317,   253,
     320,   310,   211,   325,   326,   327,   328,   311,   329,   324,
     330,   331,   332,   333,   159,     2,  -278,  -278,   229,   258,
     229,  -278,  -278,  -278,  -278,   229,   306,   229,   334,   340,
     212,   316,   229,   316,  -278,   229,  -278,  -278,  -278,  -278,
    -278,   318,  -278,  -278,  -278,  -278,   335,   101,  -278,   255,
     108,   303,   121,  -278,   315,   343,   336,   141,   337,   151,
    -278,  -278,  -278,   338,   361,   218,   412,   303,   339,   388,
     341,   -19,   342,   303,   347,  -278,   351,   238,   229,   352,
     346,   353,   348,   349,   268,   229,   229,  -278,    46,   229,
    -278,   229,  -278,  -278,  -278,   171,   198,  -278,   217,   221,
     345,   354,   344,   350,   356,   357,   358,   359,  -278,  -278,
    -278,  -278
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       5,     6,     7,     8,     0,     0,     0,     3,     4,     0,
       0,    11,    12,    13,     0,    65,     0,    63,    64,     0,
       0,   104,   105,   109,   110,   106,   113,   114,   115,   107,
     108,   123,   124,   125,   126,   127,    28,    26,    25,    27,
       0,     0,     0,     0,     9,    10,    70,    76,    75,    77,
      72,    68,    69,    73,    71,    74,    67,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,     0,   122,   132,     0,     0,    40,    38,    39,
       0,    31,    35,    37,    41,     0,     0,   140,     0,   135,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,   137,   140,     0,   141,
     142,   145,   146,   143,   144,     0,   148,   147,     0,     0,
       0,     0,     0,   144,     0,     0,    51,    46,    47,    56,
      55,    48,    54,    52,    53,    49,    50,     0,     0,    58,
      59,    57,    60,     0,     0,     0,     0,     0,     0,    66,
      36,     0,    42,     0,    29,    30,     0,    32,    33,    34,
     139,   144,     0,   134,   136,     0,     0,     0,     0,     0,
       0,   131,     0,     0,     0,     0,     0,     0,     0,    87,
      93,    86,     0,     0,    89,    96,    90,    84,    85,    94,
      91,    92,    95,    88,     0,    80,     0,     0,    43,     0,
       0,   120,     0,   151,   152,   153,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    79,     0,     0,
       0,   118,   119,   112,   149,     0,     0,     0,     0,   116,
       0,     0,     0,     0,    24,     0,    23,    18,    15,    16,
      14,     0,    97,   100,    98,    99,     0,     0,    45,     0,
       0,     0,     0,   129,     0,     0,     0,     0,     0,     0,
      83,    82,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,     0,     0,
      20,     0,    22,    21,   121,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   128,
      17,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -278,  -278,  -278,  -278,   411,  -278,  -278,   401,  -278,   107,
    -278,  -106,    40,   195,  -278,  -278,  -278,   209,  -147,  -277,
    -278,  -278,   398,     5,  -278,  -278,  -278,   191,   152,  -278,
     246,  -278,  -278,    11,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,   186,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,   -98,   355,  -112,  -278,  -278,  -227,  -257
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    20,    21,    22,   263,
      53,   137,   131,   132,   133,   134,   158,   159,   197,   203,
      12,    26,    27,   264,    67,   155,   254,   255,   256,   316,
      83,    13,    30,   265,    32,    33,    34,    35,    36,    37,
      38,   260,   261,    39,    40,    41,    42,    43,    44,    45,
     185,   138,   139,   140,   175,   178,   266,   267
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     130,   198,   272,   142,   205,   239,   176,   278,   240,   294,
     241,   351,   275,   116,   145,   294,     1,   242,   119,   156,
      28,   180,   312,   166,   326,    70,   328,    31,   313,   314,
     167,    28,    71,   243,   244,     6,     7,     8,   168,   245,
      72,    81,   212,   315,   204,   213,   206,   207,   246,   276,
       4,   211,    17,   120,   247,   248,     5,   249,   250,   251,
      14,    73,    15,   117,    16,    74,   224,   118,   252,   253,
      19,    75,   163,   164,   165,   279,   228,   177,   294,   352,
     277,    76,   160,   161,    77,    78,    24,    79,    54,    19,
     294,    46,    29,   286,   335,    82,    47,   294,    70,    90,
     169,   170,   171,   172,    48,    71,    49,   160,   161,    91,
     347,   220,    56,    72,   173,   221,   354,    50,   257,    57,
     269,    23,    25,   160,   161,    51,    58,    23,    59,   160,
     161,   160,   161,    25,    73,   235,    51,   311,    74,   367,
      60,   237,    93,    61,    75,    68,    24,    62,    80,    29,
      63,   289,    52,    96,    76,    64,    98,    77,    78,    99,
      79,   100,    65,   101,    66,   186,   187,   102,   188,   160,
     161,   189,   104,   190,   103,   191,   160,   161,   160,   161,
     239,   238,   317,   240,   319,   241,   160,   161,   192,   320,
     271,   322,   242,   160,   161,   105,   327,   106,   332,   329,
     214,   215,   193,   107,   194,   334,   160,   161,   243,   244,
     169,   170,   171,   172,   245,   291,   259,   239,   336,   108,
     240,   195,   241,   246,   173,   174,   160,   161,   109,   247,
     248,   196,   249,   250,   251,   135,   160,   161,   340,   160,
     161,   110,   358,   252,   253,   210,   244,   111,   342,   365,
     366,   245,   136,   368,   126,   369,   160,   161,    56,   113,
     246,   127,   128,   129,   112,    57,   247,   248,   370,   249,
     250,   251,    58,   114,    59,   121,   169,   170,   171,   172,
     252,   253,    51,   160,   161,   122,    60,   293,   262,    61,
     173,   183,   115,    62,   123,   371,    63,    84,    85,    86,
     124,    64,   160,   161,   299,   262,   160,   161,    65,   144,
      66,   345,   262,    87,   372,   141,    88,    89,   373,   125,
      92,   126,    94,    95,   136,    97,   126,   143,   127,   128,
     129,   357,   262,   127,   128,   129,   160,   161,   160,   161,
     160,   161,   146,   160,   161,   147,   162,   148,   296,   318,
     333,   199,   200,   201,   202,     6,     7,     8,   217,   218,
     219,   364,   262,   154,   149,   179,   150,   151,   152,   153,
     181,   182,   184,   232,   226,   233,   157,   268,   270,   273,
     208,   290,   209,   216,   222,   225,   227,   229,   230,   274,
     231,   284,   285,   288,   259,   234,   236,   262,   321,   280,
     281,   295,   282,   283,   297,   324,   304,   337,   298,   300,
     301,   302,   303,   305,   338,   330,   344,   346,   349,   306,
      18,    55,   258,   348,    69,   307,   308,   309,   310,   323,
     343,   355,   331,   339,   341,   356,   359,   361,   374,   350,
     353,   360,   376,   362,   363,   287,   292,   375,   377,   378,
     379,     0,   325,   380,   381,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     223
};

static const yytype_int16 yycheck[] =
{
     106,   148,   229,   109,   151,     5,     3,    30,     8,   266,
      10,    30,    30,    17,   112,   272,    75,    17,    17,   125,
      15,    24,    20,   135,   301,     4,   303,    16,    26,    27,
     136,    26,    11,    33,    34,    76,    77,    78,   136,    39,
      19,    30,    93,    41,   150,    96,   152,   153,    48,    67,
      92,   157,    93,    52,    54,    55,     0,    57,    58,    59,
      92,    40,    92,    67,    92,    44,   178,    71,    68,    69,
      94,    50,    87,    88,    89,    98,   182,    74,   335,    98,
      98,    60,    85,    86,    63,    64,    94,    66,    93,    94,
     347,     8,    94,    93,   321,    47,    13,   354,     4,    22,
      80,    81,    82,    83,    21,    11,    23,    85,    86,    22,
     337,    91,    18,    19,    94,    95,   343,    34,    96,    25,
     226,    14,    15,    85,    86,    42,    32,    20,    34,    85,
      86,    85,    86,    26,    40,    97,    42,   284,    44,    93,
      46,    97,    31,    49,    50,    93,    94,    53,    93,    94,
      56,   257,    69,    22,    60,    61,    84,    63,    64,    97,
      66,    97,    68,    97,    70,     6,     7,    97,     9,    85,
      86,    12,    98,    14,    95,    16,    85,    86,    85,    86,
       5,    97,   288,     8,   290,    10,    85,    86,    29,   295,
      97,   297,    17,    85,    86,    98,   302,    84,    97,   305,
     160,   161,    43,    84,    45,    97,    85,    86,    33,    34,
      80,    81,    82,    83,    39,    93,    94,     5,    97,    95,
       8,    62,    10,    48,    94,    95,    85,    86,    84,    54,
      55,    72,    57,    58,    59,    73,    85,    86,    97,    85,
      86,    95,   348,    68,    69,    91,    34,    97,    97,   355,
     356,    39,    90,   359,    92,   361,    85,    86,    18,    95,
      48,    99,   100,   101,    84,    25,    54,    55,    97,    57,
      58,    59,    32,   101,    34,    71,    80,    81,    82,    83,
      68,    69,    42,    85,    86,    92,    46,    93,    94,    49,
      94,    95,    17,    53,    95,    97,    56,    51,    52,    53,
      95,    61,    85,    86,    93,    94,    85,    86,    68,    28,
      70,    93,    94,    67,    97,    92,    70,    71,    97,    90,
      74,    92,    76,    77,    90,    79,    92,    92,    99,   100,
     101,    93,    94,    99,   100,   101,    85,    86,    85,    86,
      85,    86,    92,    85,    86,    84,    95,    84,    95,    91,
      95,    35,    36,    37,    38,    76,    77,    78,   163,   164,
     165,    93,    94,    51,    84,    51,    84,    84,    84,    84,
      51,    84,    51,    97,    84,    97,    90,    54,    10,    66,
      92,    15,    93,    92,    92,    92,    92,    92,    92,    67,
      93,    84,    84,    84,    94,    97,    97,    94,    92,    98,
      98,    84,    98,    98,    84,    65,    95,    92,    98,    84,
      84,    84,    84,    84,    71,    97,    55,     5,    30,    95,
       9,    20,   213,    84,    26,    95,    95,    95,    95,    95,
      92,    84,    97,    97,    97,    84,    84,    84,    93,    98,
      98,    95,    98,    95,    95,   254,   260,    93,    98,    93,
      93,    -1,   300,    95,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,   103,   104,    92,     0,    76,    77,    78,   105,
     106,   107,   122,   133,    92,    92,    92,    93,   106,    94,
     108,   109,   110,   111,    94,   111,   123,   124,   125,    94,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   145,
     146,   147,   148,   149,   150,   151,     8,    13,    21,    23,
      34,    42,    69,   112,    93,   109,    18,    25,    32,    34,
      46,    49,    53,    56,    61,    68,    70,   126,    93,   124,
       4,    11,    19,    40,    44,    50,    60,    63,    64,    66,
      93,   135,    47,   132,   132,   132,   132,   132,   132,   132,
      22,    22,   132,    31,   132,   132,    22,   132,    84,    97,
      97,    97,    97,    95,    98,    98,    84,    84,    95,    84,
      95,    97,    84,    95,   101,    17,    17,    67,    71,    17,
      52,    71,    92,    95,    95,    90,    92,    99,   100,   101,
     113,   114,   115,   116,   117,    73,    90,   113,   153,   154,
     155,    92,   113,    92,    28,   153,    92,    84,    84,    84,
      84,    84,    84,    84,    51,   127,   113,    90,   118,   119,
      85,    86,    95,    87,    88,    89,   155,   113,   153,    80,
      81,    82,    83,    94,    95,   156,     3,    74,   157,    51,
      24,    51,    84,    95,    51,   152,     6,     7,     9,    12,
      14,    16,    29,    43,    45,    62,    72,   120,   120,    35,
      36,    37,    38,   121,   113,   120,   113,   113,    92,    93,
      91,   113,    93,    96,   114,   114,    92,   115,   115,   115,
      91,    95,    92,   154,   155,    92,    84,    92,   113,    92,
      92,    93,    97,    97,    97,    97,    97,    97,    97,     5,
       8,    10,    17,    33,    34,    39,    48,    54,    55,    57,
      58,    59,    68,    69,   128,   129,   130,    96,   119,    94,
     143,   144,    94,   111,   125,   135,   158,   159,    54,   113,
      10,    97,   158,    66,    67,    30,    67,    98,    30,    98,
      98,    98,    98,    98,    84,    84,    93,   129,    84,   113,
      15,    93,   144,    93,   159,    84,    95,    84,    98,    93,
      84,    84,    84,    84,    95,    84,    95,    95,    95,    95,
      95,   120,    20,    26,    27,    41,   131,   113,    91,   113,
     113,    92,   113,    95,    65,   130,   121,   113,   121,   113,
      97,    97,    97,    95,    97,   158,    97,    92,    71,    97,
      97,    97,    97,    92,    55,    93,     5,   158,    84,    30,
      98,    30,    98,    98,   158,    84,    84,    93,   113,    84,
      95,    84,    95,    95,    93,   113,   113,    93,   113,   113,
      97,    97,    97,    97,    93,    93,    98,    98,    93,    93,
      95,    95
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   104,   105,   105,   106,   106,   106,   107,
     108,   108,   109,   109,   110,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   112,   112,   113,
     113,   113,   114,   114,   114,   114,   115,   115,   116,   116,
     116,   116,   117,   118,   118,   119,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   122,   123,   123,   124,   124,   125,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   128,
     128,   129,   129,   129,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   131,   131,   131,
     131,   132,   133,   134,   134,   135,   135,   135,   135,   136,
     136,   137,   138,   139,   139,   139,   140,   141,   142,   143,
     143,   144,   145,   146,   146,   146,   146,   146,   147,   148,
     149,   150,   151,   152,   153,   153,   154,   154,   154,   155,
     155,   156,   156,   156,   156,   156,   156,   157,   157,   158,
     158,   159,   159,   159
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     2,     1,     1,     1,     1,     4,
       2,     1,     1,     1,    10,    10,    10,    18,    10,    18,
      14,    14,    14,    10,    10,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     1,     1,     1,     7,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     2,
       1,     4,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     2,     1,     1,     1,     1,     1,     1,
       1,    12,     9,     1,     1,     1,     9,    13,     9,     2,
       1,     7,     5,     1,     1,     1,     1,     1,    17,    10,
      17,     7,     5,     9,     3,     1,     3,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 98 "sintactico.y" /* yacc.c:1646  */
    {
			salida->setPlainText("ARCHIVO DE ENTRADA CORRECTO");
			root = new Nodo();
			root->id = 0;
			root->valor = "ROOT";
			root->sub_izq = (yyvsp[0].nodo);
			arbol_ast arbol(&root);
			arbol.graficar();
			arbol.recorrer();
		}
#line 1691 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = new Nodo();
						(yyval.nodo)->id = cont++;
						(yyval.nodo)->valor = "ARCHIVO_ENTRADA";
						(yyval.nodo)->sub_izq = (yyvsp[-1].nodo);
						cont_atri = 0;
					}
#line 1703 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 119 "sintactico.y" /* yacc.c:1646  */
    {
						(yyvsp[-1].nodo)->lista_acciones[cont_atri] = (yyvsp[0].nodo);
						cont_atri = cont_atri + 1;
						(yyval.nodo) = (yyvsp[-1].nodo);
					}
#line 1713 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 125 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = new Nodo();
						(yyval.nodo)->id = cont++;
						(yyval.nodo)->valor = "ATRIBUDOS ARCHIVO ENTRADA";
						(yyval.nodo)->lista_acciones[0] = (yyvsp[0].nodo);
						cont_atri = cont_atri + 1;
					}
#line 1725 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 134 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "VARIABLES";
				(yyval.nodo)->sub_izq = (yyvsp[0].nodo);
			}
#line 1736 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 141 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "FIGURAS";
				(yyval.nodo)->sub_izq = (yyvsp[0].nodo);
			}
#line 1747 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 147 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "DISEÑO";
				(yyval.nodo)->sub_izq = (yyvsp[0].nodo);
			}
#line 1758 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 155 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = (yyvsp[-1].nodo);
						cont_var = 0;
					}
#line 1767 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 161 "sintactico.y" /* yacc.c:1646  */
    {
								(yyvsp[-1].nodo)->lista_acciones[cont_var] = (yyvsp[0].nodo);
								cont_var = cont_var +1;
								(yyval.nodo) = (yyvsp[-1].nodo);
							}
#line 1777 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 167 "sintactico.y" /* yacc.c:1646  */
    {
								(yyval.nodo) = new Nodo();
								(yyval.nodo)->id = cont++;
								(yyval.nodo)->valor = "LISTA DE VARIABLES Y MODIFICACION DE VARIABLES";
								(yyval.nodo)->lista_acciones[0] = (yyvsp[0].nodo);
								cont_var = cont_var + 1;
							}
#line 1789 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 176 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = (yyvsp[0].nodo);
				}
#line 1797 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 180 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = (yyvsp[0].nodo);
				}
#line 1805 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 185 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "VARIABLE";
				struct Nodo *propiedades = new Nodo();
				propiedades->id = cont++;
				propiedades->valor = "PROPIEDADES";
				propiedades->sub_der = (yyvsp[-3].nodo);
				propiedades->sub_izq = (yyvsp[-8].nodo);
				(yyval.nodo)->sub_izq = (yyvsp[-7].nodo);
				(yyval.nodo)->sub_der = propiedades;
			}
#line 1822 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 198 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "VARIABLE";
				struct Nodo *tipo = new Nodo();
				tipo->id = cont++;
				tipo->valor = "TIPO";
				struct Nodo *linea = new Nodo();
				linea->id = cont++;
				linea->valor = (yyvsp[-8].TEXT);
				tipo->sub_izq = linea;
				struct Nodo *propiedades = new Nodo();
				propiedades->id = cont++;
				propiedades->valor = "PROPIEDADES";
				propiedades->sub_der = (yyvsp[-3].nodo);
				propiedades->sub_izq = tipo;
				(yyval.nodo)->sub_izq = (yyvsp[-7].nodo);
				(yyval.nodo)->sub_der = propiedades;

			}
#line 1847 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 219 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "VARIABLE";
				struct Nodo *tipo = new Nodo();
				tipo->id = cont++;
				tipo->valor = "TIPO";
				struct Nodo *linea = new Nodo();
				linea->id = cont++;
				linea->valor = (yyvsp[-8].TEXT);
				tipo->sub_izq = linea;
				struct Nodo *propiedades = new Nodo();
				propiedades->id = cont++;
				propiedades->valor = "PROPIEDADES";
				propiedades->sub_der = (yyvsp[-3].nodo);
				propiedades->sub_izq = tipo;
				(yyval.nodo)->sub_izq = (yyvsp[-7].nodo);
				(yyval.nodo)->sub_der = propiedades;

			}
#line 1872 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 240 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "VARIABLE";
				struct Nodo *tipo = new Nodo();
				tipo->id = cont++;
				tipo->valor = "TIPO";
				struct Nodo *linea = new Nodo();
				linea->id = cont++;
				linea->valor = (yyvsp[-16].TEXT);
				tipo->sub_izq = linea;
				struct Nodo *propiedades = new Nodo();
				propiedades->id = cont++;
				propiedades->valor = "PROPIEDADES";
				propiedades->lista_acciones[0] = (yyvsp[-11].nodo);
				propiedades->lista_acciones[1] = (yyvsp[-7].nodo);
				propiedades->lista_acciones[2] = (yyvsp[-3].nodo);
				propiedades->sub_izq = tipo;
				(yyval.nodo)->sub_izq = (yyvsp[-15].nodo);
				(yyval.nodo)->sub_der = propiedades;
			}
#line 1898 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 263 "sintactico.y" /* yacc.c:1646  */
    {
							/*PRODUCCION PARA PODER MODIFICAR LAS VARIABLES NORMALES*/
							(yyval.nodo) = new Nodo();
							(yyval.nodo)->id = cont++;
							(yyval.nodo)->valor = "MODIFICACION DE VARIABLE";
							(yyval.nodo)->sub_izq = (yyvsp[-7].nodo);
							(yyval.nodo)->lista_acciones[0] = (yyvsp[-3].nodo);
						}
#line 1911 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 272 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = new Nodo();
							(yyval.nodo)->id = cont++;
							(yyval.nodo)->valor = "MODIFICACION DE VARIABLE";
							(yyval.nodo)->sub_izq = (yyvsp[-15].nodo);
							(yyval.nodo)->lista_acciones[0] = (yyvsp[-11].nodo);
							(yyval.nodo)->lista_acciones[1] = (yyvsp[-7].nodo);
							(yyval.nodo)->lista_acciones[2] = (yyvsp[-3].nodo);
						}
#line 1925 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 282 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = new Nodo();
							(yyval.nodo)->id = cont++;
							(yyval.nodo)->valor= "MODIFICACION DE VARIABLE";
							(yyval.nodo)->sub_izq = (yyvsp[-11].nodo);
							(yyval.nodo)->lista_acciones[0] = (yyvsp[-7].nodo);
							(yyval.nodo)->lista_acciones[1] = (yyvsp[-3].nodo);
						}
#line 1938 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 291 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = new Nodo();
							(yyval.nodo)->id = cont++;
							(yyval.nodo)->valor= "MODIFICACION DE VARIABLE";
							(yyval.nodo)->sub_izq = (yyvsp[-11].nodo);
							(yyval.nodo)->lista_acciones[0] = (yyvsp[-7].nodo);
							(yyval.nodo)->lista_acciones[1] = (yyvsp[-3].nodo);
						}
#line 1951 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 300 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = new Nodo();
							(yyval.nodo)->id = cont++;
							(yyval.nodo)->valor = "MODIFICACION DE VARIABLE";
							(yyval.nodo)->sub_izq = (yyvsp[-11].nodo);
							(yyval.nodo)->lista_acciones[0] = (yyvsp[-7].nodo);
							(yyval.nodo)->lista_acciones[1] = (yyvsp[-3].nodo);
						}
#line 1964 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 309 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = new Nodo();
							(yyval.nodo)->id = cont++;
							(yyval.nodo)->valor = "MODIFICACION DE VARIABLE";
							(yyval.nodo)->sub_izq = (yyvsp[-7].nodo);
							(yyval.nodo)->lista_acciones[0] = (yyvsp[-3].nodo);

						}
#line 1977 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 318 "sintactico.y" /* yacc.c:1646  */
    {
							/*ESTA PRODUCCION ES UTILIZADA TANTO POR LAS VARIABLES TIPO LINEA COMO TEXTURA*/
							(yyval.nodo) = new Nodo();
							(yyval.nodo)->id = cont++;
							(yyval.nodo)->valor = "MODIFICACION DE VARIABLE";
							(yyval.nodo)->sub_izq = (yyvsp[-7].nodo);
							(yyval.nodo)->lista_acciones[0] = (yyvsp[-3].nodo);
						}
#line 1990 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 328 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = hijo;
				}
#line 2004 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 338 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = hijo;
				}
#line 2018 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 348 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = hijo;
				}
#line 2032 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 358 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = hijo;
				}
#line 2046 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 369 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = (yyvsp[-1].TEXT);
				(yyval.nodo)->sub_izq = (yyvsp[-2].nodo);
				(yyval.nodo)->sub_der = (yyvsp[0].nodo);
			}
#line 2058 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 377 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = (yyvsp[-1].TEXT);
				(yyval.nodo)->sub_izq = (yyvsp[-2].nodo);
				(yyval.nodo)->sub_der = (yyvsp[0].nodo);
			}
#line 2070 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 385 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = (yyvsp[0].nodo);
			}
#line 2078 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 390 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[-1].TEXT);
					(yyval.nodo)->sub_izq = (yyvsp[-2].nodo);
					(yyval.nodo)->sub_der = (yyvsp[0].nodo);
				}
#line 2090 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 398 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[-1].TEXT);
					(yyval.nodo)->sub_izq = (yyvsp[-2].nodo);
					(yyval.nodo)->sub_der = (yyvsp[0].nodo);
				}
#line 2102 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 406 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[-1].TEXT);
					(yyval.nodo)->sub_izq = (yyvsp[-2].nodo);
					(yyval.nodo)->sub_der = (yyvsp[0].nodo);
				}
#line 2114 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 414 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = (yyvsp[0].nodo);
				}
#line 2122 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = (yyvsp[-1].nodo);
				}
#line 2130 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 423 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = (yyvsp[0].nodo);
				}
#line 2138 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 428 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "NUMERO";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = hijo;
				}
#line 2152 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 438 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "IDENTIFICADOR";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = hijo;
				}
#line 2166 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 448 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "CADENA";
					struct Nodo *hijo = new Nodo();
					hijo->id = cont++;
					hijo->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = hijo;
				}
#line 2180 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 458 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = (yyvsp[0].nodo);
				}
#line 2188 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 463 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = (yyvsp[-1].nodo);
				cont_array = 0;
			}
#line 2197 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 469 "sintactico.y" /* yacc.c:1646  */
    {
							(yyvsp[-2].nodo)->lista_acciones[cont_array] = (yyvsp[0].nodo);
							cont_array = cont_array + 1;
							(yyval.nodo) = (yyvsp[-2].nodo);
						}
#line 2207 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 475 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = new Nodo();
							(yyval.nodo)->id = cont++;
							(yyval.nodo)->valor = "ARREGLO";
							(yyval.nodo)->lista_acciones[0] = (yyvsp[0].nodo);
							cont_array = cont_array + 1;
						}
#line 2219 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 484 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = new Nodo();
						(yyval.nodo)->id = cont++;
						(yyval.nodo)->valor = "POSICION ARREGLO";
						(yyval.nodo)->sub_izq = (yyvsp[-3].nodo);
						(yyval.nodo)->sub_der = (yyvsp[-1].nodo);
					}
#line 2231 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 493 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			QString temp = "COLOR";
			(yyval.nodo)->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = (yyvsp[0].TEXT);
			nodo_hijo->valor = temp2;
			(yyval.nodo)->sub_izq = nodo_hijo;
		}
#line 2247 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 505 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			QString temp = "COLOR";
			(yyval.nodo)->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = (yyvsp[0].TEXT);
			nodo_hijo->valor = temp2;
			(yyval.nodo)->sub_izq = nodo_hijo;
		}
#line 2263 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 517 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			QString temp = "COLOR";
			(yyval.nodo)->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = (yyvsp[0].TEXT);
			nodo_hijo->valor = temp2;
			(yyval.nodo)->sub_izq = nodo_hijo;
		}
#line 2279 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 529 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			QString temp = "COLOR";
			(yyval.nodo)->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = (yyvsp[0].TEXT);
			nodo_hijo->valor = temp2;
			(yyval.nodo)->sub_izq = nodo_hijo;
		}
#line 2295 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 541 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			QString temp = "COLOR";
			(yyval.nodo)->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = (yyvsp[0].TEXT);
			nodo_hijo->valor = temp2;
			(yyval.nodo)->sub_izq = nodo_hijo;
		}
#line 2311 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 553 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			QString temp = "COLOR";
			(yyval.nodo)->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = (yyvsp[0].TEXT);
			nodo_hijo->valor = temp2;
			(yyval.nodo)->sub_izq = nodo_hijo;
		}
#line 2327 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 565 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			QString temp = "COLOR";
			(yyval.nodo)->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = (yyvsp[0].TEXT);
			nodo_hijo->valor = temp2;
			(yyval.nodo)->sub_izq = nodo_hijo;
		}
#line 2343 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 577 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			QString temp = "COLOR";
			(yyval.nodo)->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = (yyvsp[0].TEXT);
			nodo_hijo->valor = temp2;
			(yyval.nodo)->sub_izq = nodo_hijo;
		}
#line 2359 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 589 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			QString temp = "COLOR";
			(yyval.nodo)->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = (yyvsp[0].TEXT);
			nodo_hijo->valor = temp2;
			(yyval.nodo)->sub_izq = nodo_hijo;
		}
#line 2375 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 601 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			QString temp = "COLOR";
			(yyval.nodo)->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = (yyvsp[0].TEXT);
			nodo_hijo->valor = temp2;
			(yyval.nodo)->sub_izq = nodo_hijo;
		}
#line 2391 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 613 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			QString temp = "COLOR";
			(yyval.nodo)->valor = temp;
			struct Nodo *nodo_hijo = new Nodo();
			nodo_hijo->id = cont++; 
			QString temp2 = (yyvsp[0].TEXT);
			nodo_hijo->valor = temp2;
			(yyval.nodo)->sub_izq = nodo_hijo;
		}
#line 2407 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 627 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				QString temp = "TIPO DE LINEA";
				(yyval.nodo)->valor = temp;
				struct Nodo *nodo_hijo = new Nodo();
				nodo_hijo->id = cont++;
				QString temp2 = (yyvsp[0].TEXT);
				nodo_hijo->valor = temp2;
				(yyval.nodo)->sub_izq = nodo_hijo;
			}
#line 2423 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 639 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				QString temp = "TIPO DE LINEA";
				(yyval.nodo)->valor = temp;
				struct Nodo *nodo_hijo = new Nodo();
				nodo_hijo->id = cont++;
				QString temp2 = (yyvsp[0].TEXT);
				nodo_hijo->valor = temp2;
				(yyval.nodo)->sub_izq = nodo_hijo;
			}
#line 2439 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 651 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				QString temp = "TIPO DE LINEA";
				(yyval.nodo)->valor = temp;
				struct Nodo *nodo_hijo = new Nodo();
				nodo_hijo->id = cont++;
				QString temp2 = (yyvsp[0].TEXT);
				nodo_hijo->valor = temp2;
				(yyval.nodo)->sub_izq = nodo_hijo;
			}
#line 2455 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 663 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				QString temp = "TIPO DE LINEA";
				(yyval.nodo)->valor = temp;
				struct Nodo *nodo_hijo = new Nodo();
				nodo_hijo->id = cont++;
				QString temp2 = (yyvsp[0].TEXT);
				nodo_hijo->valor = temp2;
				(yyval.nodo)->sub_izq = nodo_hijo;
			}
#line 2471 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 677 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = (yyvsp[-1].nodo);
						cont_fig = 0;
					}
#line 2480 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 683 "sintactico.y" /* yacc.c:1646  */
    {
					(yyvsp[-1].nodo)->lista_acciones[cont_fig] = (yyvsp[0].nodo);
					cont_fig = cont_fig + 1;
					(yyval.nodo) = (yyvsp[-1].nodo);
				}
#line 2490 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 689 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "LISTA FIGURAS";
					(yyval.nodo)->lista_acciones[0] = (yyvsp[0].nodo);
					cont_fig = cont_fig + 1;
				}
#line 2502 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 698 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) =(yyvsp[0].nodo);
					}
#line 2510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 702 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = (yyvsp[0].nodo);
					}
#line 2518 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 707 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "FIGURA";
				(yyval.nodo)->sub_izq = (yyvsp[-4].nodo);
				(yyvsp[-1].nodo)->sub_izq = (yyvsp[-5].nodo);
				(yyval.nodo)->sub_der = (yyvsp[-1].nodo); 

			}
#line 2532 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 719 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 2542 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 725 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 2552 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 731 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 2562 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 737 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 2572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 743 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 2582 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 749 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 2592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 755 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 2602 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 761 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 2612 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 767 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 2622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 773 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 2632 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 779 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 2642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 786 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = (yyvsp[-1].nodo);  
							cont_par = 0;
						}
#line 2651 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 792 "sintactico.y" /* yacc.c:1646  */
    {
						(yyvsp[-1].nodo)->lista_acciones[cont_par] = (yyvsp[0].nodo);
						cont_par = cont_par + 1;
					}
#line 2660 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 797 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = new Nodo();
						(yyval.nodo)->id = cont++;
						(yyval.nodo)->valor = "LISTA PARAMETROS";
						(yyval.nodo)->lista_acciones[0] = (yyvsp[0].nodo);
						cont_par = cont_par + 1;
					}
#line 2672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 806 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "PARAMETRO";
				(yyval.nodo)->sub_izq = (yyvsp[-3].nodo);
				(yyval.nodo)->sub_der = (yyvsp[-1].nodo);
			}
#line 2684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 814 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "PARAMETRO";
				struct Nodo *propiedad = new Nodo();
				propiedad->id = cont++;
				propiedad->valor = "TIPO PROPIEDAD";
				struct Nodo *letra = new Nodo();
				letra->id = cont++;
				letra->valor = (yyvsp[-3].TEXT);
				propiedad->sub_izq = letra;
				(yyval.nodo)->sub_izq = propiedad;
				(yyval.nodo)->sub_der = (yyvsp[-1].nodo);
			}
#line 2703 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 829 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "PARAMETRO";
				struct Nodo *propiedad = new Nodo();
				propiedad->id = cont++;
				propiedad->valor = "TIPO PROPIEDAD";
				struct Nodo *color = new Nodo();
				color->id = cont++;
				color->valor = (yyvsp[-3].TEXT);
				propiedad->sub_izq = color;
				(yyval.nodo)->sub_izq = propiedad;
				(yyval.nodo)->sub_der = (yyvsp[-1].nodo);
			}
#line 2722 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 845 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2736 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 855 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2750 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 865 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2764 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 875 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2778 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 885 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2792 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 895 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2806 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 905 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2820 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 915 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 925 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2848 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 935 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2862 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 945 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2876 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 955 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2890 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 965 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "TIPO PROPIEDAD";
					struct Nodo *letra = new Nodo();
					letra->id = cont++;
					letra->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = letra;
				}
#line 2904 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 976 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "TIPO LETRA";
				struct Nodo *letra = new Nodo();
				letra->id = cont++;
				letra->valor = (yyvsp[0].TEXT);
				(yyval.nodo)->sub_izq = letra;
			}
#line 2918 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 986 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "TIPO LETRA";
				struct Nodo *letra = new Nodo();
				letra->id = cont++;
				letra->valor = (yyvsp[0].TEXT);
				(yyval.nodo)->sub_izq = letra;
			}
#line 2932 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 996 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "TIPO LETRA";
				struct Nodo *letra = new Nodo();
				letra->id = cont++;
				letra->valor = (yyvsp[0].TEXT);
				(yyval.nodo)->sub_izq = letra;
			}
#line 2946 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1006 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "TIPO LETRA";
				struct Nodo *letra = new Nodo();
				letra->id = cont++;
				letra->valor = (yyvsp[0].TEXT);
				(yyval.nodo)->sub_izq = letra;
			}
#line 2960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1017 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "IDENTIFICADOR";
					struct Nodo *nombre = new Nodo();
					nombre->id = cont++;
					nombre->valor = (yyvsp[0].TEXT);
					(yyval.nodo)->sub_izq = nombre;
				}
#line 2974 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1028 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = (yyvsp[-1].nodo);
						cont_acciones = 0;
					}
#line 2983 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1035 "sintactico.y" /* yacc.c:1646  */
    {
					(yyvsp[-1].nodo)->lista_acciones[cont_acciones] = (yyvsp[0].nodo);
					cont_acciones = cont_acciones + 1;
					(yyval.nodo) = (yyvsp[-1].nodo);
				}
#line 2993 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1041 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "LISTA DE DISEÑO";
					(yyval.nodo)->lista_acciones[0] = (yyvsp[0].nodo);
					cont_acciones = cont_acciones + 1;
				}
#line 3005 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1050 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = (yyvsp[0].nodo);
			}
#line 3013 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1054 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = (yyvsp[0].nodo);
			}
#line 3021 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1058 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = (yyvsp[0].nodo);
			}
#line 3029 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1062 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = (yyvsp[0].nodo);
			}
#line 3037 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1067 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = (yyvsp[0].nodo);
		}
#line 3045 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1071 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = (yyvsp[0].nodo);
		}
#line 3053 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1076 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			(yyval.nodo)->valor = "FOR";
			struct Nodo *con = new Nodo();
			con->id = cont++;
			con->valor = "CONDICIONES";
			con->sub_izq = (yyvsp[-7].nodo);
			con->sub_der = (yyvsp[-4].nodo);
			(yyval.nodo)->sub_izq = con;
			(yyval.nodo)->sub_der = (yyvsp[-1].nodo);
		}
#line 3070 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1090 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			(yyval.nodo)->valor = "WHILE";
			(yyval.nodo)->sub_izq = (yyvsp[-4].nodo);
			(yyval.nodo)->sub_der = (yyvsp[-1].nodo);
		}
#line 3082 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1099 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = (yyvsp[0].nodo);
				}
#line 3090 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1103 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = (yyvsp[0].nodo);
				}
#line 3098 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1107 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = (yyvsp[0].nodo); 
				}
#line 3106 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1112 "sintactico.y" /* yacc.c:1646  */
    {
		(yyval.nodo) = new Nodo();
		(yyval.nodo)->id = cont++;
		(yyval.nodo)->valor = "IF";
		(yyval.nodo)->sub_izq = (yyvsp[-4].nodo);
		(yyval.nodo)->sub_der = (yyvsp[-1].nodo);		
	}
#line 3118 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1122 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "IF";
				(yyval.nodo)->sub_izq = (yyvsp[-8].nodo);
				(yyval.nodo)->sub_der = (yyvsp[-5].nodo);
				struct Nodo *hijo = new Nodo();
				hijo->id = cont++;
				hijo->valor = "ELSE";
				hijo->sub_izq = (yyvsp[-1].nodo);
				(yyval.nodo)->lista_acciones[0] = hijo;
			}
#line 3135 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1136 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			(yyval.nodo)->valor = "CASE";
			(yyval.nodo)->sub_izq = (yyvsp[-4].nodo);
			(yyval.nodo)->sub_der = (yyvsp[-1].nodo);
			cont_acciones = 0;
		}
#line 3148 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1146 "sintactico.y" /* yacc.c:1646  */
    {
					(yyvsp[-1].nodo)->lista_acciones[cont_acciones] = (yyvsp[0].nodo);
					cont_acciones = cont_acciones + 1;
					(yyval.nodo) = (yyvsp[-1].nodo);
				}
#line 3158 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1152 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "LISTA DE CASOS";
					(yyval.nodo)->lista_acciones[0] = (yyvsp[0].nodo);
					cont_acciones = cont_acciones + 1;
				}
#line 3170 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1161 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			(yyval.nodo)->valor = "CASO";
			(yyval.nodo)->sub_izq = (yyvsp[-4].nodo);
			(yyval.nodo)->sub_der = (yyvsp[-1].nodo);
		}
#line 3182 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1170 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "GRAFICAR";
				(yyval.nodo)->sub_izq = (yyvsp[-2].nodo);
			}
#line 3193 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1178 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = (yyvsp[0].nodo);
					}
#line 3201 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1182 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = (yyvsp[0].nodo);
					}
#line 3209 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1186 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = (yyvsp[0].nodo);
					}
#line 3217 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1190 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = (yyvsp[0].nodo);
					}
#line 3225 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1194 "sintactico.y" /* yacc.c:1646  */
    {
						(yyval.nodo) = (yyvsp[0].nodo);
					}
#line 3233 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1199 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = "REDIMENSIONAR";
					(yyval.nodo)->sub_izq = (yyvsp[-14].nodo);
					(yyval.nodo)->sub_der->lista_acciones[0] = (yyvsp[-7].nodo);
					(yyval.nodo)->sub_der->lista_acciones[1] = (yyvsp[-3].nodo);				
				}
#line 3246 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1209 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			(yyval.nodo)->valor = "ROTAR";
			(yyval.nodo)->sub_izq = (yyvsp[-7].nodo);
			(yyval.nodo)->sub_der = (yyvsp[-3].nodo);
		}
#line 3258 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1218 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			(yyval.nodo)->valor = "MOVER";
			(yyval.nodo)->sub_izq = (yyvsp[-14].nodo);
			(yyval.nodo)->sub_der->lista_acciones[0] = (yyvsp[-7].nodo);
			(yyval.nodo)->sub_der->lista_acciones[1] = (yyvsp[-3].nodo);				
		}
#line 3271 "parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1228 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = new Nodo();
							(yyval.nodo)->id = cont++;
							(yyval.nodo)->valor = "MODIFICAR PROPIEDAD";
							(yyval.nodo)->sub_izq = (yyvsp[-4].nodo);
							(yyval.nodo)->sub_der = (yyvsp[-1].nodo);
						}
#line 3283 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1237 "sintactico.y" /* yacc.c:1646  */
    {
			(yyval.nodo) = new Nodo();
			(yyval.nodo)->id = cont++;
			(yyval.nodo)->valor = "BORRAR";
			(yyval.nodo)->sub_izq = (yyvsp[-2].nodo);
		}
#line 3294 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1245 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = "PROPIEDAD";
				(yyval.nodo)->sub_izq = (yyvsp[-4].nodo);
				(yyval.nodo)->sub_der = (yyvsp[-1].nodo);
			}
#line 3306 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1254 "sintactico.y" /* yacc.c:1646  */
    {
							(yyvsp[-1].nodo)->sub_izq = (yyvsp[-2].nodo);
							(yyvsp[-1].nodo)->sub_der = (yyvsp[0].nodo);
							(yyval.nodo) = (yyvsp[-1].nodo);
						}
#line 3316 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1260 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = (yyvsp[0].nodo);
						}
#line 3324 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1265 "sintactico.y" /* yacc.c:1646  */
    {
							(yyvsp[-1].nodo)->sub_izq = (yyvsp[-2].nodo);
							(yyvsp[-1].nodo)->sub_der = (yyvsp[0].nodo);
							(yyval.nodo) = (yyvsp[-1].nodo);
						}
#line 3334 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1271 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = new Nodo();
							(yyval.nodo)->id = cont++;
							(yyval.nodo)->valor = (yyvsp[-1].TEXT);
							(yyval.nodo)->sub_izq = (yyvsp[0].nodo);
						}
#line 3345 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1278 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = (yyvsp[0].nodo);	
						}
#line 3353 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1283 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = (yyvsp[-1].nodo);
						}
#line 3361 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1287 "sintactico.y" /* yacc.c:1646  */
    {
							(yyval.nodo) = (yyvsp[0].nodo);
						}
#line 3369 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1292 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 3379 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1298 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 3389 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1304 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 3399 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1310 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 3409 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1316 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 3419 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1322 "sintactico.y" /* yacc.c:1646  */
    {
					(yyval.nodo) = new Nodo();
					(yyval.nodo)->id = cont++;
					(yyval.nodo)->valor = (yyvsp[0].TEXT);
				}
#line 3429 "parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1329 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = (yyvsp[0].TEXT);
			}
#line 3439 "parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1335 "sintactico.y" /* yacc.c:1646  */
    {
				(yyval.nodo) = new Nodo();
				(yyval.nodo)->id = cont++;
				(yyval.nodo)->valor = (yyvsp[0].TEXT);
			}
#line 3449 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3453 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1348 "sintactico.y" /* yacc.c:1906  */
