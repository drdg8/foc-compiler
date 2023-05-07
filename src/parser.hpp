/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    TEXTERN = 258,
    TRETURN = 259,
    FOR = 260,
    IF = 261,
    ELSE = 262,
    WHILE = 263,
    SWITCH = 264,
    CASE = 265,
    DEFAULT = 266,
    ARRAY = 267,
    CONST = 268,
    INT = 269,
    CHAR = 270,
    FLOAT = 271,
    DOUBLE = 272,
    VOID = 273,
    BOOL = 274,
    CONTINUE = 275,
    LONG = 276,
    UNTIL = 277,
    BREAK = 278,
    GAD = 279,
    SEMI = 280,
    COLON = 281,
    TCEQ = 282,
    TCNE = 283,
    TCLT = 284,
    TCLE = 285,
    TCGT = 286,
    TCGE = 287,
    TEQUAL = 288,
    TLPAREN = 289,
    TRPAREN = 290,
    TLBRACE = 291,
    TRBRACE = 292,
    TLBRACK = 293,
    TRBRACK = 294,
    TCOMMA = 295,
    TDOT = 296,
    ARW = 297,
    BXOR = 298,
    BNOT = 299,
    OR = 300,
    AND = 301,
    TPLUS = 302,
    TMINUS = 303,
    TMUL = 304,
    TDIV = 305,
    TINTEGER = 306,
    TIDENTIFIER = 307,
    TDOUBLE = 308,
    CHARACTER = 309,
    STRING = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

  int token;//标注终结符token
  //标注int double char string
  int iVal;
  std::string *sVal;
  double dVal;
  char cVal;
  bool bVal;
  std::string *strVal;

	Node *node;
	NBlock *block;

  //定义抽象类
  NDeclaration *ndelc;//declaration抽象类
  std::vector<NDeclaration*> *ndelcs;//declarations抽象类
  
  //变量定义
  NVariableDeclaration *var_decl;
	std::vector<NVariableDeclaration*> *var_decls;
//函数定义
  NFunctionDeclaration *func_decl;
  //std::vector<NFunctionDeclaration*> *func_decls;
  

  NExpression *expr;//表达式
	NStatement *stmt;//声明
	NIdentifier *ident;//标识符
  
  //关键词
	NForStatement *forStatement;
  NIfStatement *ifStatement;
  NSwitchStatement *switchStatement;
  NWhileStatement *whileStatement;
  NCaseStatement *caseStatement;
  NLoopStatement *loopStatement;
  CaseList *caseList;
  NBreakStatement *breakStatement;
  

	std::vector<NExpression*> *expressionList;

	
	

#line 159 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
