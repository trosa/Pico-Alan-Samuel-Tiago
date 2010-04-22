#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20090221

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
#ifdef YYPARSE_PARAM_TYPE
#define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
#else
#define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
#endif
#else
#define YYPARSE_DECL() yyparse(void)
#endif /* YYPARSE_PARAM */

extern int YYPARSE_DECL();

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "pico.y"
  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
  #include <stdio.h>
  #include <stdlib.h>
#line 40 "pico.y"
typedef union {
   char expr[4000]; /* redefinimos a union YYSTYPE, que é o tipo da variável yylval, que conterá uma string */
} YYSTYPE;
#line 45 "y.tab.c"
#define IDF 257
#define INT 258
#define DOUBLE 259
#define FLOAT 260
#define CHAR 261
#define QUOTE 262
#define DQUOTE 263
#define LE 264
#define GE 265
#define EQ 266
#define NE 267
#define AND 268
#define OR 269
#define NOT 270
#define IF 271
#define THEN 272
#define ELSE 273
#define WHILE 274
#define INT_LIT 275
#define F_LIT 276
#define END 277
#define TRUE 278
#define FALSE 279
#define REAL 280
#define FOR 281
#define NEXT 282
#define REPEAT 283
#define UNTIL 284
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    1,    3,    4,    4,    5,    5,    6,
    6,    6,    6,    7,    7,    7,    7,    8,    8,    2,
    2,    9,    9,   10,   10,   13,   13,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   14,   12,   12,   12,
   16,   16,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,
};
static const short yylen[] = {                            2,
    2,    1,    2,    3,    3,    1,    3,    1,    1,    1,
    1,    1,    1,    4,    4,    4,    4,    3,    5,    2,
    3,    3,    1,    1,    4,    1,    3,    3,    3,    3,
    3,    3,    1,    1,    1,    1,    4,    1,    7,    7,
    1,    3,    1,    1,    3,    3,    3,    2,    3,    3,
    3,    3,    3,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,   33,   34,    0,    0,    0,    2,    0,
    0,    0,    0,    0,   23,   36,    0,    0,    0,    0,
    0,    0,   35,    0,    1,    0,    3,    0,    0,    0,
    0,    0,    0,    0,    0,    7,    0,    0,    0,    0,
   43,   44,    0,    0,    0,    0,   32,    4,    0,    0,
    0,    0,    5,    8,    9,   21,    0,    0,    0,   30,
   31,    0,   25,   37,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   27,   45,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   14,   15,   16,   17,    0,   41,   39,   40,    0,
    0,    0,   42,   19,
};
static const short yydgoto[] = {                          7,
    8,    9,   10,   11,   53,   54,   55,   95,   12,   23,
   14,   15,   38,   16,   45,  108,
};
static const short yysindex[] = {                       -34,
  -29,  -38,  -30,    0,    0,  -31,    0,  -34,    0,  -41,
  -20,  -10,    3,  129,    0,    0, -226,  -31,  -31,  -40,
  -40,  -23,    0,   71,    0,   10,    0, -116,  -28,  -31,
  -31,  -31,  -31,  -31,   28,    0,  123,  -17,   29,  -40,
    0,    0,  -40,   39,  -37,    7,    0,    0,  -11,   -4,
   -3,    9,    0,    0,    0,    0,  129,  -39,  -39,    0,
    0,  -31,    0,    0, -247,   32,   12,  -31,  -31,  -31,
  -31,  -31,  -31,  -40,  -40, -189,  -21, -186, -186, -186,
 -186,    0,    0,  129,  129,  129,  129,  129,  129, -247,
 -247,  -28,  -28,   38,   13,   34,   35,   41, -257,   15,
 -170,    0,    0,    0,    0,  -28,    0,    0,    0,  104,
 -162, -186,    0,    0,
};
static const short yyrindex[] = {                         0,
   88,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   94,   79,    0,    0,    0,    0,    0,    0,
    0,  -15,    0,    0,    0,    0,    0,    0,    1,    0,
    0,    0,    0,    0,   92,    0,  -27,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   93,   95,
   96,   97,    0,    0,    0,    0,  110,   -8,   -2,    0,
    0,    0,    0,    0,  132,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   14,   18,   20,   22,   24,   26,  134,
  136,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   85,
    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,   11,  171,  163,    0,    0,    0,  -56,    0,    5,
   89,    0,  -12,    0,   50,    0,
};
#define YYTABLESIZE 306
static const short yytable[] = {                         43,
   20,   20,   33,   76,   13,    6,   39,   34,    6,   21,
   19,    6,   13,   26,   17,  106,   19,   27,   25,  107,
   74,   75,   96,   97,   98,   24,   24,   24,   24,   24,
   35,   24,   28,   13,   28,   28,   28,   28,   29,   56,
   29,   29,   29,   24,   24,   24,   24,   77,   29,   82,
   28,   28,   83,   28,   51,  114,   29,   29,   52,   29,
   53,   18,   54,   30,   49,   26,   50,   18,   48,   64,
   46,   17,   47,   33,   31,   63,   32,   24,   34,   78,
   33,   31,   92,   32,   28,   34,   79,   80,   94,   65,
   29,   73,   67,   72,   24,  101,   13,   13,   73,   81,
   72,   93,   99,  100,  110,  102,   37,   37,   44,   44,
   13,   47,   33,   31,  113,   32,  111,   34,   57,   58,
   59,   60,   61,   90,   91,   20,  103,  104,   44,   24,
   24,   66,   24,  105,   24,   35,   35,   38,   35,  109,
   35,   49,   50,   51,   52,    6,   24,  112,   24,    6,
   37,   10,   35,   11,   12,   13,   84,   85,   86,   87,
   88,   89,   44,   44,   33,   31,   62,   32,   22,   34,
   33,   31,   48,   32,   46,   34,   47,   18,   26,   36,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   22,    0,    0,    0,
    0,    0,    1,    0,    0,   22,    0,    0,   22,   40,
   74,   75,    0,    0,    4,    5,    2,   41,   42,    3,
    4,    5,    2,    4,    5,    3,    4,    5,   24,   24,
   24,   24,   24,   24,    0,   28,   28,   28,   28,   28,
   28,   29,   29,   29,   29,   29,   29,    0,    0,    0,
    0,    0,    0,   20,   74,   75,    0,   20,    0,   74,
   75,   51,   51,    0,    0,   52,   52,   53,   53,   54,
   54,   49,   49,   50,   50,   68,   69,   70,   71,    0,
    0,    0,   68,   69,   70,   71,
};
static const short yycheck[] = {                         40,
    0,   40,   42,   41,    0,   40,   19,   47,   40,   40,
   40,   40,    8,   41,   44,  273,   40,   59,    8,  277,
  268,  269,   79,   80,   81,   41,   42,   43,   44,   45,
  257,   47,   41,   29,   43,   44,   45,   58,   41,   29,
   43,   44,   45,   59,   60,   61,   62,   41,   59,   62,
   59,   60,   41,   62,   41,  112,   59,   60,   41,   62,
   41,   91,   41,   61,   41,   93,   41,   91,   59,   41,
   21,   44,   41,   42,   43,   93,   45,   93,   47,   91,
   42,   43,  272,   45,   93,   47,   91,   91,  275,   40,
   93,   60,   43,   62,    6,   58,   92,   93,   60,   91,
   62,  123,   92,   93,  275,   93,   18,   19,   20,   21,
  106,   41,   42,   43,  277,   45,  106,   47,   30,   31,
   32,   33,   34,   74,   75,  125,   93,   93,   40,   42,
   43,   43,   45,   93,   47,   42,   43,   59,   45,  125,
   47,  258,  259,  260,  261,   58,   59,   44,   61,   58,
   62,   59,   59,   59,   59,   59,   68,   69,   70,   71,
   72,   73,   74,   75,   42,   43,   44,   45,   59,   47,
   42,   43,   41,   45,   41,   47,   41,   93,    8,   17,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,   -1,
   -1,   -1,  257,   -1,   -1,  257,   -1,   -1,  257,  270,
  268,  269,   -1,   -1,  275,  276,  271,  278,  279,  274,
  275,  276,  271,  275,  276,  274,  275,  276,  264,  265,
  266,  267,  268,  269,   -1,  264,  265,  266,  267,  268,
  269,  264,  265,  266,  267,  268,  269,   -1,   -1,   -1,
   -1,   -1,   -1,  273,  268,  269,   -1,  277,   -1,  268,
  269,  268,  269,   -1,   -1,  268,  269,  268,  269,  268,
  269,  268,  269,  268,  269,  264,  265,  266,  267,   -1,
   -1,   -1,  264,  265,  266,  267,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 284
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IDF","INT","DOUBLE","FLOAT","CHAR","QUOTE",
"DQUOTE","LE","GE","EQ","NE","AND","OR","NOT","IF","THEN","ELSE","WHILE",
"INT_LIT","F_LIT","END","TRUE","FALSE","REAL","FOR","NEXT","REPEAT","UNTIL",
};
static const char *yyrule[] = {
"$accept : code",
"code : declaracoes acoes",
"code : acoes",
"declaracoes : declaracao ';'",
"declaracoes : declaracoes declaracao ';'",
"declaracao : listadeclaracao ':' tipo",
"listadeclaracao : IDF",
"listadeclaracao : IDF ',' listadeclaracao",
"tipo : tipounico",
"tipo : tipolista",
"tipounico : INT",
"tipounico : DOUBLE",
"tipounico : FLOAT",
"tipounico : CHAR",
"tipolista : INT '[' listadupla ']'",
"tipolista : DOUBLE '[' listadupla ']'",
"tipolista : FLOAT '[' listadupla ']'",
"tipolista : CHAR '[' listadupla ']'",
"listadupla : INT_LIT ':' INT_LIT",
"listadupla : INT_LIT ':' INT_LIT ',' listadupla",
"acoes : comando ';'",
"acoes : comando ';' acoes",
"comando : lvalue '=' expr",
"comando : enunciado",
"lvalue : IDF",
"lvalue : IDF '[' listaexpr ']'",
"listaexpr : expr",
"listaexpr : expr ',' listaexpr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : '(' expr ')'",
"expr : INT_LIT",
"expr : F_LIT",
"expr : lvalue",
"expr : chamaproc",
"chamaproc : IDF '(' listaexpr ')'",
"enunciado : expr",
"enunciado : IF '(' expbool ')' THEN acoes fiminstcontrole",
"enunciado : WHILE '(' expbool ')' '{' acoes '}'",
"fiminstcontrole : END",
"fiminstcontrole : ELSE acoes END",
"expbool : TRUE",
"expbool : FALSE",
"expbool : '(' expbool ')'",
"expbool : expbool AND expbool",
"expbool : expbool OR expbool",
"expbool : NOT expbool",
"expbool : expr '>' expr",
"expbool : expr '<' expr",
"expbool : expr LE expr",
"expbool : expr GE expr",
"expbool : expr EQ expr",
"expbool : expr NE expr",

};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static unsigned yystacksize;
#line 138 "pico.y"
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

   if (!yyparse()) 
      printf("OKAY.\n");
   else 
      printf("ERROR.\n");

   return(0);
}

yyerror(char* s) {
  fprintf(stderr, "%s: %s", progname, s);
  fprintf(stderr, "line %d\n", lineno);
}
#line 355 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    yystate = 0;
    *yyssp = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yyssp = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yyssp = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 22:
#line 87 "pico.y"
	{ printf("%s\n", yyvsp[0].expr); }
break;
case 26:
#line 95 "pico.y"
	{ printf("%s\n", yyvsp[0].expr); }
break;
case 27:
#line 96 "pico.y"
	{ printf("%s\n", yyvsp[-2].expr); }
break;
case 28:
#line 101 "pico.y"
	{ sprintf(yyval.expr, "%s%s+ ", yyvsp[-2].expr, yyvsp[0].expr); }
break;
case 29:
#line 102 "pico.y"
	{ sprintf(yyval.expr, "%s%s- ", yyvsp[-2].expr, yyvsp[0].expr); }
break;
case 30:
#line 103 "pico.y"
	{ sprintf(yyval.expr, "%s%s* ", yyvsp[-2].expr, yyvsp[0].expr); }
break;
case 31:
#line 104 "pico.y"
	{ sprintf(yyval.expr, "%s%s/ ", yyvsp[-2].expr, yyvsp[0].expr); }
break;
case 32:
#line 105 "pico.y"
	{ yyval = yyvsp[-1]; }
break;
case 33:
#line 106 "pico.y"
	{ yyval = yyvsp[0]; }
break;
case 38:
#line 115 "pico.y"
	{ printf("%s\n", yyvsp[0].expr); }
break;
case 49:
#line 130 "pico.y"
	{ printf("%s\n%s\n", yyvsp[-2].expr, yyvsp[0].expr); }
break;
case 50:
#line 131 "pico.y"
	{ printf("%s\n%s\n", yyvsp[-2].expr, yyvsp[0].expr); }
break;
case 51:
#line 132 "pico.y"
	{ printf("%s\n%s\n", yyvsp[-2].expr, yyvsp[0].expr); }
break;
case 52:
#line 133 "pico.y"
	{ printf("%s\n%s\n", yyvsp[-2].expr, yyvsp[0].expr); }
break;
case 53:
#line 134 "pico.y"
	{ printf("%s\n%s\n", yyvsp[-2].expr, yyvsp[0].expr); }
break;
case 54:
#line 135 "pico.y"
	{ printf("%s\n%s\n", yyvsp[-2].expr, yyvsp[0].expr); }
break;
#line 604 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = (short) yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
