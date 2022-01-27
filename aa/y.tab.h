/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C

      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.

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
    YPUSHI = 258,
    YPUSHIR = 259,
    YPUSH = 260,
    YPUSHR = 261,
    YPOP = 262,
    YPOPR = 263,
    YPUSHX = 264,
    YPOPX = 265,
    YADD = 266,
    YSUB = 267,
    YMUL = 268,
    YDIV = 269,
    YCMP = 270,
    YNOP = 271,
    YJMP = 272,
    YJEQ = 273,
    YJNE = 274,
    YJLT = 275,
    YJLE = 276,
    YJGT = 277,
    YJGE = 278,
    YCALL = 279,
    YRET = 280,
    YINPUT = 281,
    YOUTPUT = 282,
    YWORD = 283,
    YIMPORT = 284,
    YEXPORT = 285,
    YSTOP = 286,
    YMODULE = 287,
    YEND = 288,
    YDOT = 289,
    YSTART = 290,
    YSPFREE = 291,
    YSPALLOC = 292,
    YLABEL = 293,
    YNUMBER = 294,
    YLABYCOLON = 295
};
#endif
/* Tokens.  */
#define YPUSHI 258
#define YPUSHIR 259
#define YPUSH 260
#define YPUSHR 261
#define YPOP 262
#define YPOPR 263
#define YPUSHX 264
#define YPOPX 265
#define YADD 266
#define YSUB 267
#define YMUL 268
#define YDIV 269
#define YCMP 270
#define YNOP 271
#define YJMP 272
#define YJEQ 273
#define YJNE 274
#define YJLT 275
#define YJLE 276
#define YJGT 277
#define YJGE 278
#define YCALL 279
#define YRET 280
#define YINPUT 281
#define YOUTPUT 282
#define YWORD 283
#define YIMPORT 284
#define YEXPORT 285
#define YSTOP 286
#define YMODULE 287
#define YEND 288
#define YDOT 289
#define YSTART 290
#define YSPFREE 291
#define YSPALLOC 292
#define YLABEL 293
#define YNUMBER 294
#define YLABYCOLON 295




#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


