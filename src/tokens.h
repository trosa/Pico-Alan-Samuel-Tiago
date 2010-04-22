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
typedef union {
   char expr[4000]; /* redefinimos a union YYSTYPE, que é o tipo da variável yylval, que conterá uma string */
} YYSTYPE;
extern YYSTYPE yylval;
