
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "pico.y"

  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  #include "node.h"
  #include "symbol_table.h"

  #define UNDEFINED_SYMBOL_ERROR -21

  Node *syntax_tree = NULL;
  symbol_t s_table;
  int __desloc__ = 0;
  extern int noline;


/* Line 189 of yacc.c  */
#line 94 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDF = 258,
     INT = 259,
     DOUBLE = 260,
     REAL = 261,
     CHAR = 262,
     QUOTE = 263,
     DQUOTE = 264,
     LE = 265,
     GE = 266,
     EQ = 267,
     NE = 268,
     AND = 269,
     OR = 270,
     NOT = 271,
     IF = 272,
     THEN = 273,
     ELSE = 274,
     WHILE = 275,
     INT_LIT = 276,
     F_LIT = 277,
     END = 278,
     TRUE = 279,
     FALSE = 280,
     FOR = 281,
     NEXT = 282,
     REPEAT = 283,
     UNTIL = 284
   };
#endif
/* Tokens.  */
#define IDF 258
#define INT 259
#define DOUBLE 260
#define REAL 261
#define CHAR 262
#define QUOTE 263
#define DQUOTE 264
#define LE 265
#define GE 266
#define EQ 267
#define NE 268
#define AND 269
#define OR 270
#define NOT 271
#define IF 272
#define THEN 273
#define ELSE 274
#define WHILE 275
#define INT_LIT 276
#define F_LIT 277
#define END 278
#define TRUE 279
#define FALSE 280
#define FOR 281
#define NEXT 282
#define REPEAT 283
#define UNTIL 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 50 "pico.y"

   struct _node *node;



/* Line 214 of yacc.c  */
#line 194 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 206 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNRULES -- Number of states.  */
#define YYNSTATES  116

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,    32,    30,    37,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    35,
      45,    34,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    15,    19,    21,    25,
      27,    29,    31,    33,    35,    37,    42,    47,    52,    57,
      61,    67,    70,    74,    78,    80,    82,    87,    89,    93,
      97,   101,   105,   109,   113,   115,   117,   119,   121,   126,
     128,   136,   144,   146,   150,   152,   154,   158,   162,   166,
     169,   173,   177,   181,   185,   189
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    55,    -1,    55,    -1,    49,    35,
      -1,    48,    49,    35,    -1,    50,    36,    51,    -1,     3,
      -1,     3,    37,    50,    -1,    52,    -1,    53,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,     4,    38,    54,
      39,    -1,     5,    38,    54,    39,    -1,     6,    38,    54,
      39,    -1,     7,    38,    54,    39,    -1,    21,    36,    21,
      -1,    21,    36,    21,    37,    54,    -1,    56,    35,    -1,
      56,    35,    55,    -1,    57,    34,    59,    -1,    61,    -1,
       3,    -1,     3,    38,    58,    39,    -1,    59,    -1,    59,
      37,    58,    -1,    59,    30,    59,    -1,    59,    31,    59,
      -1,    59,    32,    59,    -1,    59,    33,    59,    -1,    40,
      59,    41,    -1,    21,    -1,    22,    -1,    57,    -1,    60,
      -1,     3,    40,    58,    41,    -1,    59,    -1,    17,    40,
      63,    41,    18,    55,    62,    -1,    20,    40,    63,    41,
      42,    55,    43,    -1,    23,    -1,    19,    55,    23,    -1,
      24,    -1,    25,    -1,    40,    63,    41,    -1,    63,    14,
      63,    -1,    63,    15,    63,    -1,    16,    63,    -1,    59,
      44,    59,    -1,    59,    45,    59,    -1,    59,    10,    59,
      -1,    59,    11,    59,    -1,    59,    12,    59,    -1,    59,
      13,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    82,    85,    86,    89,   191,   192,   195,
     196,   199,   200,   201,   202,   205,   206,   207,   208,   211,
     212,   215,   216,   219,   220,   223,   232,   243,   244,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   258,   261,
     262,   263,   266,   267,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDF", "INT", "DOUBLE", "REAL", "CHAR",
  "QUOTE", "DQUOTE", "LE", "GE", "EQ", "NE", "AND", "OR", "NOT", "IF",
  "THEN", "ELSE", "WHILE", "INT_LIT", "F_LIT", "END", "TRUE", "FALSE",
  "FOR", "NEXT", "REPEAT", "UNTIL", "'+'", "'-'", "'*'", "'/'", "'='",
  "';'", "':'", "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "'>'",
  "'<'", "$accept", "code", "declaracoes", "declaracao", "listadeclaracao",
  "tipo", "tipounico", "tipolista", "listadupla", "acoes", "comando",
  "lvalue", "listaexpr", "expr", "chamaproc", "enunciado",
  "fiminstcontrole", "expbool", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      43,    45,    42,    47,    61,    59,    58,    44,    91,    93,
      40,    41,   123,   125,    62,    60
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    53,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    61,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     3,
       5,     2,     3,     3,     1,     1,     4,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     4,     1,
       7,     7,     1,     3,     1,     1,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,     0,     0,    34,    35,     0,     0,     0,     0,
       0,     3,     0,    36,    39,    37,    24,     0,     0,     0,
       0,     0,    25,    36,     0,     1,     0,     2,     4,     0,
      21,     0,     0,     0,     0,     0,     7,     8,     0,    27,
       0,     0,    44,    45,     0,     0,     0,     0,    33,     5,
      11,    12,    13,    14,     6,     9,    10,    22,    23,    29,
      30,    31,    32,    26,     0,    38,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    46,    52,    53,    54,    55,    50,
      51,    47,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,    18,     0,    42,    40,
      41,    19,     0,     0,    43,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    54,    55,    56,    96,    11,
      12,    23,    38,    14,    15,    16,   109,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yytype_int16 yypact[] =
{
      61,    97,   -38,   -34,   -39,   -39,    28,    57,    61,   -21,
      24,   -39,    26,    29,   108,   -39,   -39,    63,    28,    28,
      22,    22,    16,   -39,   -15,   -39,    32,   -39,   -39,   138,
      82,    28,    28,    28,    28,    28,    42,   -39,    30,    95,
      39,    22,   -39,   -39,    22,    85,    -4,    -2,   -39,   -39,
      50,    67,    68,    70,   -39,   -39,   -39,   -39,   108,     8,
       8,   -39,   -39,   -39,    28,   -39,   -39,    79,    14,    28,
      28,    28,    28,    28,    28,    22,    22,    96,    71,    98,
      98,    98,    98,   -39,   -39,   108,   108,   108,   108,   108,
     108,   -39,   107,    82,    82,   100,    92,   109,   110,   111,
     -14,   103,   126,   -39,   -39,   -39,   -39,    82,   -39,   -39,
     -39,   114,   129,    98,   -39,   -39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -39,   -39,   -39,   145,   137,   -39,   -39,   -39,   -29,    -7,
     -39,     0,   -16,     1,   -39,   -39,   -39,   -17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -8
static const yytype_int8 yytable[] =
{
      13,    27,    20,    40,    47,   107,    21,    24,    13,   108,
      75,    76,    75,    76,    28,    32,    33,    34,    35,    39,
      39,    45,    45,    57,    66,    22,    48,    68,    75,    76,
      13,    22,    58,    59,    60,    61,    62,    77,    41,    78,
      34,    35,    45,     4,     5,    67,    42,    43,    83,     4,
       5,    97,    98,    99,    18,    84,    19,    25,    91,    92,
      29,    30,    44,    31,     1,    39,    36,    49,     6,    63,
      85,    86,    87,    88,    89,    90,    45,    45,     2,    17,
      65,     3,     4,     5,   115,    22,   100,   101,    79,    69,
      70,    71,    72,    13,    13,    69,    70,    71,    72,     2,
     112,     6,     3,     4,     5,    80,    81,    13,    82,    32,
      33,    34,    35,    94,    93,    32,    33,    34,    35,    95,
      48,    75,     6,    73,    74,    32,    33,    34,    35,    73,
      74,   103,    64,    -7,    17,    18,   102,    19,    32,    33,
      34,    35,    50,    51,    52,    53,   110,   111,   104,   105,
     106,   113,   114,    26,    37
};

static const yytype_uint8 yycheck[] =
{
       0,     8,    40,    19,    21,    19,    40,     6,     8,    23,
      14,    15,    14,    15,    35,    30,    31,    32,    33,    18,
      19,    20,    21,    30,    41,     3,    41,    44,    14,    15,
      30,     3,    31,    32,    33,    34,    35,    41,    16,    41,
      32,    33,    41,    21,    22,    44,    24,    25,    64,    21,
      22,    80,    81,    82,    38,    41,    40,     0,    75,    76,
      36,    35,    40,    34,     3,    64,     3,    35,    40,    39,
      69,    70,    71,    72,    73,    74,    75,    76,    17,    37,
      41,    20,    21,    22,   113,     3,    93,    94,    38,    10,
      11,    12,    13,    93,    94,    10,    11,    12,    13,    17,
     107,    40,    20,    21,    22,    38,    38,   107,    38,    30,
      31,    32,    33,    42,    18,    30,    31,    32,    33,    21,
      41,    14,    40,    44,    45,    30,    31,    32,    33,    44,
      45,    39,    37,    36,    37,    38,    36,    40,    30,    31,
      32,    33,     4,     5,     6,     7,    43,    21,    39,    39,
      39,    37,    23,     8,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    17,    20,    21,    22,    40,    47,    48,    49,
      50,    55,    56,    57,    59,    60,    61,    37,    38,    40,
      40,    40,     3,    57,    59,     0,    49,    55,    35,    36,
      35,    34,    30,    31,    32,    33,     3,    50,    58,    59,
      58,    16,    24,    25,    40,    59,    63,    63,    41,    35,
       4,     5,     6,     7,    51,    52,    53,    55,    59,    59,
      59,    59,    59,    39,    37,    41,    63,    59,    63,    10,
      11,    12,    13,    44,    45,    14,    15,    41,    41,    38,
      38,    38,    38,    58,    41,    59,    59,    59,    59,    59,
      59,    63,    63,    18,    42,    21,    54,    54,    54,    54,
      55,    55,    36,    39,    39,    39,    39,    19,    23,    62,
      43,    21,    55,    37,    23,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 81 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (2)].node)); pack_nodes(&c, 1, (yyvsp[(2) - (2)].node)); syntax_tree = (yyval.node) = create_node(noline, program_node, NULL, NULL, 2, c); }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 82 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (1)].node)); syntax_tree = (yyval.node) = create_node(noline, program_node, NULL, NULL, 1, c); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 85 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (2)].node)); (yyval.node) = create_node(noline, decls_node, NULL, NULL, 1, c); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 86 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(2) - (3)].node)); (yyval.node) = create_node(noline, decls_node, NULL, NULL, 2, c); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 89 "pico.y"
    { 
                                             Node *n, *n_arr;
                                             int i;
                                             
                                             n = (yyvsp[(1) - (3)].node);
                                             while (1)
                                             {
                                                /* Antes de inserir um elemento na tabela de simbolos, verifica se esse elemento nao está na tabela */
                                                if (lookup(s_table, n->children[0]->lexeme) == NULL)
                                                { 
                                                   entry_t e;

                                                   e.name = (char *)malloc(strlen(n->children[0]->lexeme) + 1);
                                                   strcpy(e.name, n->children[0]->lexeme);
                                                   switch ((yyvsp[(3) - (3)].node)->type)
                                                   {
                                                   case char_node:
                                                      e.type = 0;
                                                      e.size = 1;
                                                      e.array = NULL;
                                                      break;
                                                   case int_node:
                                                      e.type = 1;
                                                      e.size = 4;
                                                      e.array = NULL;
                                                      break;
                                                   case real_node:
                                                      e.type = 2;
                                                      e.size = 4;
                                                      e.array = NULL;
                                                      break;
                                                   case double_node:
                                                      e.type = 3;
                                                      e.size = 8;
                                                      e.array = NULL;
                                                      break;

                                                   case char_array_node:
                                                   case int_array_node:
                                                   case real_array_node:
                                                   case double_array_node:
                                                      i = 0;
                                                      n_arr = (yyvsp[(3) - (3)].node)->children[0];
                                                      e.size = 1;
                                                      /*Inicialização das estruturas */
                                                      e.array = (array_t *)malloc(sizeof(array_t));
                                                      e.array->dim = height(n_arr) - 1;
                                                      e.array->linf = (int *)malloc(sizeof(int) * e.array->dim);
                                                      e.array->lsup = (int *)malloc(sizeof(int) * e.array->dim);
                                                      e.array->c = 0;
                                                      while(1)
                                                      {
							 /* Percorre a arvore e coloca os limites inferiores e superiores nos seus respectivos arrays */
                                                         sscanf(n_arr->children[0]->lexeme, "%d", &(e.array->linf[i]));
                                                         sscanf(n_arr->children[1]->lexeme, "%d", &(e.array->lsup[i]));
							 /* Calculo da Constante C */
                                                         e.size *= e.array->lsup[i] - e.array->linf[i] + 1;
                                                         e.array->c += e.array->linf[i];
                                                         e.array->c *= e.array->lsup[i] - e.array->linf[i] + 1;
                                                         if (n_arr->children_number == 2)
                                                            break;
                                                         n_arr = n_arr->children[2];
                                                         i++;
                                                      }
                                                      switch ((yyvsp[(3) - (3)].node)->type)
                                                      {
                                                      case char_array_node:
                                                         e.type = 4;
                                                         e.size *= 1;
                                                         break;
                                                      case int_array_node:
                                                         e.type = 5;
                                                         e.size *= 4;
                                                         break;
                                                      case real_array_node:
                                                         e.type = 6;
                                                         e.size *= 4;
                                                         break;
                                                      case double_array_node:
                                                         e.type = 7;
                                                         e.size *= 8;
                                                         break;
                                                      }
                                                      break;
                                                   }
                                                   e.desloc = __desloc__;
                                                   __desloc__ += e.size;
                                                   insert(&s_table, &e);
                                                }
                                                else
                                                {
                                                   // ERRO: identificador já declarado;
                                                }

                                                if (n->children_number == 1)
                                                   break;
                                                n = n->children[1];
                                             }

                                             Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, decl_node, NULL, NULL, 2, c);
                                          }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 191 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (1)].node)); (yyval.node) = create_node(noline, decl_list_node, NULL, NULL, 1, c); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 192 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, decl_list_node, NULL, NULL, 2, c); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 195 "pico.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 196 "pico.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 199 "pico.y"
    { (yyval.node) = create_leaf(noline, int_node, NULL, NULL); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 200 "pico.y"
    { (yyval.node) = create_leaf(noline, double_node, NULL, NULL); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 201 "pico.y"
    { (yyval.node) = create_leaf(noline, real_node, NULL, NULL); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 202 "pico.y"
    { (yyval.node) = create_leaf(noline, char_node, NULL, NULL); }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 205 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(3) - (4)].node)); (yyval.node) = create_node(noline, int_array_node, NULL, NULL, 1, c); }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 206 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(3) - (4)].node)); (yyval.node) = create_node(noline, double_array_node, NULL, NULL, 1, c); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 207 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(3) - (4)].node)); (yyval.node) = create_node(noline, real_array_node, NULL, NULL, 1, c); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 208 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(3) - (4)].node)); (yyval.node) = create_node(noline, char_array_node, NULL, NULL, 1, c); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 211 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, array_list_node, NULL, NULL, 2, c); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 212 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (5)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (5)].node)); pack_nodes(&c, 2, (yyvsp[(5) - (5)].node)); (yyval.node) = create_node(noline, array_list_node, NULL, NULL, 3, c); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 215 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (2)].node)); (yyval.node) = create_node(noline, action_node, NULL, NULL, 1, c); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 216 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, action_node, NULL, NULL, 2, c); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 219 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, assig_node, NULL, NULL, 2, c); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 220 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (1)].node)); (yyval.node) = create_node(noline, enun_node, NULL, NULL, 1, c); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 223 "pico.y"
    {
                                 if (lookup(s_table, (yyvsp[(1) - (1)].node)->lexeme) == NULL)
                                 {
                                    printf("UNDEFINED SYMBOL. A variavel %s nao foi declarada.\n", (yyvsp[(1) - (1)].node)->lexeme);
                                    (yyval.node) = create_leaf(noline, error_node, NULL, NULL);
                                    return(UNDEFINED_SYMBOL_ERROR);
                                 }
                                 Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (1)].node)); (yyval.node) = create_node(noline, lvalue_node, NULL, NULL, 1, c);
                              }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 232 "pico.y"
    {
                                 if (lookup(s_table, (yyvsp[(1) - (4)].node)->lexeme) == NULL)
                                 {
                                    printf("UNDEFINED SYMBOL. A variavel %s nao foi declarada.\n", (yyvsp[(1) - (4)].node)->lexeme);
                                    (yyval.node) = create_leaf(noline, error_node, NULL, NULL);
                                    return(UNDEFINED_SYMBOL_ERROR);
                                 }
                                 Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (4)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (4)].node)); (yyval.node) = create_node(noline, lvalue_node, NULL, NULL, 2, c);
                              }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 243 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (1)].node)); (yyval.node) = create_node(noline, expr_list_node,  NULL, NULL, 1, c); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 244 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, expr_list_node,  NULL, NULL, 2, c); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 247 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, plus_node,  NULL, NULL, 2, c); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 248 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, minus_node, NULL, NULL, 2, c); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 249 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, mult_node,  NULL, NULL, 2, c); }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 250 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, div_node,   NULL, NULL, 2, c); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 251 "pico.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 252 "pico.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 253 "pico.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 254 "pico.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 255 "pico.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 258 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (4)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (4)].node)); (yyval.node) = create_node(noline, proc_node,  NULL, NULL, 2, c); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 261 "pico.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 262 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(3) - (7)].node)); pack_nodes(&c, 1, (yyvsp[(6) - (7)].node)); pack_nodes(&c, 2, (yyvsp[(7) - (7)].node)); (yyval.node) = create_node(noline, if_node,  NULL, NULL, 3, c); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 263 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(3) - (7)].node)); pack_nodes(&c, 1, (yyvsp[(6) - (7)].node)); (yyval.node) = create_node(noline, while_node,  NULL, NULL, 2, c); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 266 "pico.y"
    { (yyval.node) = create_leaf(noline, end_node, NULL, NULL); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 267 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(2) - (3)].node)); (yyval.node) = create_node(noline, else_node,  NULL, NULL, 1, c); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 270 "pico.y"
    { (yyval.node) = create_leaf(noline, true_node, NULL, NULL); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 271 "pico.y"
    { (yyval.node) = create_leaf(noline, false_node, NULL, NULL); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 272 "pico.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 273 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, and_node,  NULL, NULL, 2, c); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 274 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, or_node,  NULL, NULL, 2, c); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 275 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(2) - (2)].node));  (yyval.node) = create_node(noline, not_node,  NULL, NULL, 1, c); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 276 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, sup_node,  NULL, NULL, 2, c); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 277 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, inf_node,  NULL, NULL, 2, c); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 278 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, inf_eq_node,  NULL, NULL, 2, c); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 279 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, sup_eq_node,  NULL, NULL, 2, c); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 280 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, eq_node,  NULL, NULL, 2, c); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 281 "pico.y"
    { Node **c; pack_nodes(&c, 0, (yyvsp[(1) - (3)].node)); pack_nodes(&c, 1, (yyvsp[(3) - (3)].node)); (yyval.node) = create_node(noline, neq_node,  NULL, NULL, 2, c); }
    break;



/* Line 1455 of yacc.c  */
#line 1995 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 283 "pico.y"

 /* A partir daqui, insere-se qlqer codigo C necessario.
  */

char* progname;
int lineno;
extern FILE* yyin;


int main(int argc, char* argv[]) 
{
   if (argc != 2) {
     printf("uso: %s <input_file>. Try again!\n", argv[0]);
     exit(-1);
   }
   yyin = fopen(argv[1], "r");
   if (!yyin) {
     printf("Uso: %s <input_file>. Could not find %s. Try again!\n", 
         argv[0], argv[1]);
     exit(-1);
   }

   progname = argv[0];
   init_table(&s_table);

   if (!yyparse()) 
      printf("OKAY.\n");
   else 
      printf("ERROR.\n");

#ifdef DEBUG
   print_table(s_table);
#endif

   if (syntax_tree != NULL)
      deep_free_node(syntax_tree);
   free_table(&s_table);
   return(0);
}

yyerror(char* s) {
  fprintf(stderr, "%s: %s", progname, s);
  fprintf(stderr, "line %d\n", lineno);
}

