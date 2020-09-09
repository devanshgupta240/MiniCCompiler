/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_SECOND_PASS_TAB_H_INCLUDED
# define YY_YY_SECOND_PASS_TAB_H_INCLUDED
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
    FUNCTION = 258,
    BEG = 259,
    END = 260,
    IF = 261,
    GOTO = 262,
    PARAMETER = 263,
    REFPARAMETER = 264,
    CALL = 265,
    LSQUAREB = 266,
    RSQUAREB = 267,
    RETURN = 268,
    NEWLINE = 269,
    CONVERTTOINT = 270,
    CONVERTTOFLOAT = 271,
    LPARE = 272,
    RPARE = 273,
    USERVARIABLE = 274,
    REGINT = 275,
    REGFLOAT = 276,
    LABEL = 277,
    DATAINT = 278,
    DATAFLOAT = 279,
    PRINT = 280,
    READ = 281,
    COMMA = 282,
    COLON = 283,
    SEMI = 284,
    PLUS = 285,
    MINUS = 286,
    MUL = 287,
    DIV = 288,
    MOD = 289,
    EQUAL = 290,
    NOTEQUAL = 291,
    OR = 292,
    AND = 293,
    LESSTHAN = 294,
    GREATTHAN = 295,
    LESSEQUAL = 296,
    GREATEQUAL = 297,
    ASSIGN = 298,
    NEG = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 34 "second_pass.y" /* yacc.c:1909  */

    int intValue;
    float floatValue;
    char *idName;

#line 105 "second_pass.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SECOND_PASS_TAB_H_INCLUDED  */
