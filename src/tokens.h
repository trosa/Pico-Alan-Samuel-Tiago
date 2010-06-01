
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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
     UNTIL = 284,
     PRINTF = 285
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
#define PRINTF 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 51 "pico.y"

   struct _node *node;



/* Line 1676 of yacc.c  */
#line 118 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


