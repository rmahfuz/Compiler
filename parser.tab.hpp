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

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
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
    PROGRAM = 258,
    _BEGIN = 259,
    END = 260,
    FUNCTION = 261,
    READ = 262,
    WRITE = 263,
    IF = 264,
    ELSE = 265,
    FI = 266,
    FOR = 267,
    ROF = 268,
    RETURN = 269,
    INT = 270,
    VOID = 271,
    STRING = 272,
    FLOAT = 273,
    PLUS_OP = 274,
    MINUS_OP = 275,
    COLONEQUAL_OP = 276,
    STAR_OP = 277,
    DIVIDE_OP = 278,
    EQUAL_OP = 279,
    NOTEQUAL_OP = 280,
    LESSTHAN_OP = 281,
    GREATERTHAN_OP = 282,
    OPENPARAN_OP = 283,
    CLOSEPARAN_OP = 284,
    SEMICOLON_OP = 285,
    COMMA_OP = 286,
    LESSTHANEQUAL_OP = 287,
    GREATERTHANEQUAL_OP = 288,
    IDENTIFIER = 289,
    INTLITERAL = 290,
    FLOATLITERAL = 291,
    STRINGLITERAL = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "parser.ypp" /* yacc.c:1909  */

	struct Entry* entry;
	struct ASTNode* ast_node;
	struct ASTNodeAddr* ast_node_addr;
	char* str_val;

#line 99 "parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
